#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "DataTypes.h"

namespace Utilities
{

    class FileReader
    {
    private:
        std::string fileName; // Stores the name/path of the file

    public:
        // Constructor to initialize the FileReader with a file name/path
        FileReader(const std::string &fileName) : fileName(fileName) {}

        // Method to read and validate data from the file
        std::vector<Utility::OptionData> readData()
        {
            std::vector<Utility::OptionData> options;
            std::ifstream file(fileName);
            std::string line;

            if (!file.is_open())
            {
                std::cerr << "Error opening file: " << fileName << std::endl;
                return options; // Return an empty vector if file opening failed
            }

            // Read the header line
            getline(file, line);
            validateHeader(line);

            while (getline(file, line))
            {
                std::stringstream ss(line);
                double S, K, C, P, T, r;

                // The data must be comma-separated
                char comma;
                ss >> S >> comma >> K >> comma >> C >> comma >> P >> comma >> T >> comma >> r;

                options.emplace_back(S, K, C, P, T, r);
            }

            file.close();
            return options;
        }

        // Method to validate the header based on the file name
        void validateHeader(const std::string &header)
        {
            if (fileName == "OptionData.csv" && header != "S,K,C,P,T,r")
            {
                throw std::invalid_argument("Invalid header for OptionData.csv");
            }
            else if (fileName == "PriceHistory.csv" && header != "Date,Open,High,Low,Close,Volume")
            {
                throw std::invalid_argument("Invalid header for PriceHistory.csv");
            }
        }
    };
}

// Example Usage
// int main()
// {
//     try
//     {
//         // Create an instance of FileReader with the desired file name
//         Utilities::FileReader fileReader("OptionData.csv");

//         // Call the readData() method to get a vector of OptionData instances
//         std::vector<Utility::OptionData> options = fileReader.readData();

//         // Use the data
//         for (const auto &option : options)
//         {
//             std::cout << "S: " << option.S
//                       << ", K: " << option.K
//                       << ", C: " << option.C
//                       << ", P: " << option.P
//                       << ", T: " << option.T
//                       << ", r: " << option.r
//                       << std::endl;
//         }
//     }
//     catch (const std::invalid_argument &e)
//     {
//         // Handle the exception (here its just printing an error message)
//         std::cerr << "An error occurred: " << e.what() << std::endl;
//     }

//     return 0;
// }