from collections import deque

class Exchange:
    def __init__(self, initialBalance):
        self.buy_orders = deque()
        self.sell_orders = deque()
        self.initialBalance = initialBalance

    def add_trade(self, trade):
        # Validate trade
        amount = trade['amount']
        price = trade['price']

        if amount > 0:
            self.buy_orders.append(trade)
        else:
            self.sell_orders.append(trade)

        return self.match_trades() # api call