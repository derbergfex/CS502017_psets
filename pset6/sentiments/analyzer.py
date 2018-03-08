import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        self.positives = []
        self.negatives = []

        with open(positives) as positives:
            for line in positives:
                if not line.startswith((";", " ")):
                    self.positives.extend(line.split())

        with open(negatives) as negatives:
            for line in negatives:
                if not line.startswith((";", " ")):
                    self.negatives.extend(line.split())


    def analyze(self, text):

        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        score = 0

        for token in tokens:

            if token.lower() in self.positives:
                score += 1
            elif token.lower() in self.negatives:
                score -= 1

        return score


