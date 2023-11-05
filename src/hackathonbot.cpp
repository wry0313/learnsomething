//
// Created by Ethan on 9/13/2023.
//

#include "hackathonbot.h"
#include "iostream"

HackathonBot::HackathonBot() {}

void HackathonBot::takeAction(float price) {
    if (prices.size() > 0) {
        if (price < prices.back()) {
            upStreakWindow = 0;
            downStreakWindow++;
            if (!holding) {
                downStreakAfterSell++;
            }
        } else if (price > prices.back()) {
            upStreakWindow++;
            downStreakWindow = 0;
        }
        else {
            upStreakWindow = 0;
            downStreakWindow = 0;
        }
    }
    prices.push_back(price);

    if (holding) {
        float percentChangeFromBuy = (price - purchasePrice) / purchasePrice * 100;
        if (abs(percentChangeFromBuy) <= 5) {
            noFluctuationStreak++;
            if (noFluctuationStreak>=10) {
                this->sell(price);
                return;
            }
        }

        int window = prices.size();

        if (downStreakWindow >= 47 || upStreakWindow >= 52 || percentChangeFromBuy <= -62 || percentChangeFromBuy >= 89) {
            this->sell(price);
            return;
        }
        else if (window >= 4) {
            auto it = prices.end();
            it -= 3;
            float first = *it;
            std::vector<float> delta;
            float prev = first;
            while (it != this->prices.end()) {
                it++;
                float curr = *it;
                delta.push_back((curr - prev) / prev);
            }
            delta.push_back((*it - first) / first);

            if ((delta.at(0) >= 0.2 &&
                 delta.at(1) <= -0.15 &&
                 delta.at(2) >= 0.3 &&
                 delta.at(3) >= 0.5)
            or  (delta.at(0) <= -0.15 &&
                 delta.at(1) >= 0.15 &&
                 delta.at(2) <= -0.25 &&
                 delta.at(3) <= -0.45))
            {
                this->sell(price);
                return;
            }
        }
    } else {
        if (price < 52 || downStreakAfterSell >= 5) {
            this->buy(price);
            return;
        }
    }
}


void HackathonBot::buy(float price) {
    prices.push_back(price);
    balance -= price;
    prices.clear();
    holding = true;
}

void HackathonBot::sell(float price){
    this->holding = false;
    downStreakAfterSell = 0;
    balance += price;
    purchasePrice = price;
    prices.clear();
}

double HackathonBot::getBalance() {
    return balance + (holding ? prices.back() : 0);
}

bool HackathonBot::isHolding() {
    return holding;
}