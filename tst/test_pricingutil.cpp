#include <gtest/gtest.h>

#include "pricingutil.h"

TEST(PricingUtilFormula, TestFormula) {
    PricingUtil util = PricingUtil();

    EXPECT_NEAR(util.calcVal(1, 0.1, 3), 3, 1e-4);
    EXPECT_NEAR(util.getVal(), 3, 1e-4);
    EXPECT_NEAR(util.calcVal(30, 0.1, 3), 90, 1e-4);
    EXPECT_NEAR(util.getVal(), 90, 1e-4);
    EXPECT_NEAR(util.calcVal(100, 0, 3), 270, 1e-4);
    EXPECT_NEAR(util.getVal(), 270, 1e-4);
}