//
// Created by Ethan on 9/13/2023.
//

#include <vector>
#include "action.h"

#ifndef LEARNSOMETHING_HACKATHONBOT_H
#define LEARNSOMETHING_HACKATHONBOT_H

class HackathonBot {
public:
    HackathonBot();
    void takeAction(float price);
    double getBalance();
    bool isHolding();
private:
    void sell(float price);
    void buy(float price);
    double balance;
    bool holding;
    int downStreakWindow;
    int upStreakWindow;
    int downStreakAfterSell;
    int noFluctuationStreak;
    float purchasePrice;
    std::vector<float> prices;
};

#endif //LEARNSOMETHING_HACKATHONBOT_H
