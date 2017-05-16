import nltk


class Analyzer:
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        self.positives = []

        with open(positives) as positives_file:
            for line in positives_file:
                if line[0].isalpha():
                    self.positives.append(line.rstrip("\n"))
                else:
                    continue

        self.negatives = []
        with open(negatives) as negatives_file:
            for line in negatives_file:
                if line[0].isalpha():
                    self.negatives.append(line.rstrip("\n"))
                else:
                    continue

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        score = 0
        text = text.lower()
        tokenizer = nltk.tokenize.TweetTokenizer()

        for word in tokenizer.tokenize(text):
            if word in self.positives:
                score += 1
            elif word in self.negatives:
                score -= 1

        return score
