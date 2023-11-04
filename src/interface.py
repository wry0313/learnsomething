from collections import deque

class Exchange:
    # implement this!
    balance = 0

    def __init__(self, initialBalance):
        """Initial Balance is the amount that each account should start with."""
        self.initialBalance = initialBalance

    def add_trade(self, trade):
        """Adds a trade to the exchange (validation required)
        and returns a match if required. It is up to you on how you will
        handle representing trades. """

        if trade.amount < self.initialBalance:
            return False

        self.balance += trade.amount

        return True
