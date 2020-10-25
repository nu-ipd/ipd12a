#include <iostream>

int main()
{
    std::cout << "Enter a number to square:\n";

    double x;
    std::cin >> x;
    if (!std::cin) {
        std::cerr << "Could not read number!\n";
        return 1;
    }

    std::cout << x << " * " << x << " == " << x * x << "\n";
}