#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

namespace Utilities
{

    std::vector<Utility::OptionData> FileReader::readData()
    {
        std::ifstream file(filename);
        std::string line;
        std::vector<Utility::OptionData> options;

        if (!file.is_open())
        {
            throw std::runtime_error("Could not open file: " + filename);
        }

        // Assuming the first row contains headers
        std::getline(file, line);
        std::vector<std::string> headers;
        std::stringstream ss(line);
        std::string header;
        while (getline(ss, header, ','))
        {
            headers.push_back(header);
        }

        // Validate headers
        validateHeaders(headers, filename);

        // Reading the actual data
        while (getline(file, line))
        {
            std::stringstream ss(line);
            std::string data;
            Utility::OptionData optionData;

            getline(ss, data, ',');
            optionData.S = std::stod(data);
            getline(ss, data, ',');
            optionData.K = std::stod(data);
            getline(ss, data, ',');
            optionData.C = std::stod(data);
            getline(ss, data, ',');
            optionData.P = std::stod(data);
            getline(ss, data, ',');
            optionData.T = std::stod(data);
            getline(ss, data, ',');
            optionData.r = std::stod(data);

            options.push_back(optionData);
        }

        file.close();
        return options;
    }

    void FileReader::validateHeaders(const std::vector<std::string> &headers, const std::string &filename)
    {
        // Define required columns for each file type
        std::vector<std::string> requiredColumns;

        if (filename == "OptionData.csv")
        {
            requiredColumns = {"S", "K", "C", "P", "T", "r"};
        }
        else if (filename == "PriceHistory.csv")
        {
            requiredColumns = {"Date", "Open", "High", "Low", "Close", "Volume"};
        }
        else
        {
            throw std::runtime_error("Unsupported file type: " + filename);
        }

        for (const auto &column : requiredColumns)
        {
            if (std::find(headers.begin(), headers.end(), column) == headers.end())
            {
                throw std::runtime_error("Missing required column: " + column);
            }
        }
    }
}
