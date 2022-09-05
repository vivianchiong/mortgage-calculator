#include <iostream>
#include <iomanip>
#include <cfenv>
#include <cmath>

template <typename T>
void enterInput(const std::string& str, T& arg)  {
    do {
        if (std::cout << str && std::cin >> arg) break;
        std::cout << "Invalid input, please re-enter ... " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(int argc, char* const argv[]) {
    double loan = 0.0;
    int years = 0;
    double APR = 0.0;

    enterInput<double>("Enter principal loan amount in USD: ", loan);
    enterInput<int>("Enter term length in years: ", years);
    enterInput<double>("Enter % APR: ", APR);

    int months = years * 12;
    double decMonthsRate = APR/(100*12);
    double num = loan * decMonthsRate * std::pow(1 + decMonthsRate, months);
    double denom = std::pow(1 + decMonthsRate, months) - 1;
    double monthlyPayment = num/denom;

    std::fesetround(FE_DOWNWARD);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your monthly payment is: $" << monthlyPayment << std::endl;
}