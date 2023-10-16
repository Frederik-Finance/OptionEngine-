#include <iostream>

// Utility Namespace to encapsulate the DataTypes
namespace Utility
{

    // Structure to hold option data
    struct OptionData
    {
        double S; // Underlying asset price
        double K; // Strike price
        double C; // Call option price
        double P; // Put option price
        double T; // Time to expiration
        double r; // Risk-free interest rate

        // Constructor to initialize the structure with data
        OptionData(double S, double K, double C, double P, double T, double r)
            : S(S), K(K), C(C), P(P), T(T), r(r) {}

        // Default constructor
        OptionData() = default;

        // Function to display option data (For testing and debugging)
        void display()
        {
            std::cout << "Underlying asset price (S): " << S << std::endl;
            std::cout << "Strike price (K): " << K << std::endl;
            std::cout << "Call option price (C): " << C << std::endl;
            std::cout << "Put option price (P): " << P << std::endl;
            std::cout << "Time to expiration (T): " << T << std::endl;
            std::cout << "Risk-free interest rate (r): " << r << std::endl;
        }
    };
}

// Example usage
// int main()
// {
//     Utility::OptionData optionData(100, 100, 10, 5, 1, 0.05);
//     optionData.display();
//     return 0;
// }
