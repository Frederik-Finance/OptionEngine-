#include <iostream>
#include "Utilities/FileReader.h" // Include the FileReader class
#include "PCPChecker/PCPCheck.h"  // Include the PCPCheck class

int main()
{
    try
    {
        // Step 1: Read the data from the file
        Utilities::FileReader fileReader("OptionData.csv");
        std::vector<Utility::OptionData> options = fileReader.readData();

        // Step 2: Perform the put-call parity check
        PCPChecker::PCPCheck pcpChecker;
        pcpChecker.verifyPCP(options);

        // Step 3: Log the identified arbitrage opportunities
        pcpChecker.logArbitrageOpportunities();
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
