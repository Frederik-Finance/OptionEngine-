#include "PCPCheck.h"
#include <cmath>
#include <iostream>

namespace PCPChecker
{

    // Method to verify the Put-Call Parity and identify arbitrage opportunities
    void PCPCheck::verifyPCP(const std::vector<Utility::OptionData> &options)
    {
        for (const auto &option : options)
        {
            double leftSide = option.C - option.P;
            double rightSide = option.S - option.K * exp(-option.r * option.T);

            // Allowing a small discrepancy due to pricing models, bid-ask spreads, etc.
            if (fabs(leftSide - rightSide) > 0.01)
            {
                Utility::ArbitrageOpportunity opportunity;
                opportunity.optionData = option;
                opportunity.arbitrageAmount = fabs(leftSide - rightSide);

                arbitrageOpportunities.push_back(opportunity);
            }
        }
    }

    // Method to log identified arbitrage opportunities
    void PCPCheck::logArbitrageOpportunities()
    {
        if (arbitrageOpportunities.empty())
        {
            std::cout << "No arbitrage opportunities found." << std::endl;
            return;
        }

        for (const auto &opportunity : arbitrageOpportunities)
        {
            std::cout << "Arbitrage Opportunity Found: "
                      << "S: " << opportunity.optionData.S
                      << ", K: " << opportunity.optionData.K
                      << ", C: " << opportunity.optionData.C
                      << ", P: " << opportunity.optionData.P
                      << ", T: " << opportunity.optionData.T
                      << ", r: " << opportunity.optionData.r
                      << ", Arbitrage Amount: " << opportunity.arbitrageAmount
                      << std::endl;
        }
    }
}
