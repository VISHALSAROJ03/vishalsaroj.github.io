#include <iostream>

int main() {
    double num1, num2, num3;
    
    // Input
    std::cout << "Enter three numbers: ";
    std::cin >> num1 >> num2 >> num3;
    
    // Calculate the product
    double product = num1 * num2 * num3;

    // Calculate the average
    double average = (num1 + num2 + num3) / 3.0;

    // Output the product and average
    std::cout << "Product of the three numbers: " << product << std::endl;
    std::cout << "Average of the three numbers: " << average << std::endl;

    return 0;
}
