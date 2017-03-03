/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9
#define RIGHT 1
#define LEFT 2
#define DOWN 3
#define UP 4
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"


// board
int board[DIM_MAX][DIM_MAX];

// Coordinates
struct cord {
    int row;
    int col;
} num, zero;

// dimensions
int d;

// prototypes
void clear(void);

void greet(void);

void init(void);

void draw(void);

bool move(int tile);

bool findNumber(int tile);

bool swapTiles(int n);

bool won(void);

int main(int argc, string argv[]) {
    // ensure proper usage
    if (argc != 2) {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX) {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL) {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true) {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1) {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won()) {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // quit if user inputs 0 (for testing)
        if (tile == 0) {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile)) {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void) {
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void) {
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void) {
    int num = d * d - 1, temp;
    for (int row = 0; row < d; ++row)
        for (int col = 0; col < d; ++col, --num)
            board[row][col] = num;
    board[d - 1][d - 1] = 0;
    if (d % 2 == 0) {
        int a = d - 1, b = d - 2, c = d - 3;
        temp = board[a][c];
        board[a][c] = board[a][b];
        board[a][b] = temp;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void) {
    int n = 1;
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < d; ++j)
            if (board[i][j] == 0) {
                printf("%4c", '_');
                continue;
            } else if (board[i][j] == n++) // Highlight correct tile positions
                printf(GREEN "%4d" RESET, board[i][j]);
            else
                printf("%4d", board[i][j]);
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile) {
    if (!findNumber(tile)) // Confirm that input is within the number range
        return false;

    if (board[num.row][num.col + 1] == 0 && num.col + 1 != d)
        return swapTiles(RIGHT);
    else if (board[num.row][num.col - 1] == 0 && num.col)
        return swapTiles(LEFT);
    else if (board[num.row + 1][num.col] == 0 && num.row + 1 != d)
        return swapTiles(DOWN);
    else if (board[num.row - 1][num.col] == 0 && num.row)
        return swapTiles(UP);
    else
        return false;
    return false;
}

// Returns true if inputted tile is found while saving the position
// to global variable, else returns false
bool findNumber(int tile) {
    for (int i = 0; i < d; ++i)
        for (int j = 0; j < d; ++j)
            if (board[i][j] == tile) {
                num.row = i;
                num.col = j;
                return true;
            }
    return false;
}

// Returns true if tiles are swapped, else returns false
bool swapTiles(int i) {
    int temp, row = num.row, col = num.col;
    switch (i) {
        case 1 :
            temp = board[row][col + 1];
            board[row][col + 1] = board[row][col];
            board[row][col] = temp;
            return true;
        case 2:
            temp = board[row][col - 1];
            board[row][col - 1] = board[row][col];
            board[row][col] = temp;
            return true;
        case 3:
            temp = board[row + 1][col];
            board[row + 1][col] = board[row][col];
            board[row][col] = temp;
            return true;
        case 4:
            temp = board[row - 1][col];
            board[row - 1][col] = board[row][col];
            board[row][col] = temp;
            return true;
        default:
            return false;
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void) {
    int n = 1;
    for (int row = 0; row < d; ++row)
        for (int col = 0; col < d; ++col, ++n)
            if (board[row][col] != n && n < d * d)
                return false;
            else
                continue;

    if (n == d * d + 1)
        return true;

    return false;
}

