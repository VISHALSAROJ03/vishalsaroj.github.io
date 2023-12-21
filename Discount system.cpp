#include <iostream>
using namespace std;

int main() {
    double totalPurchase;
    
    // Prompt the user to enter the total purchase value
    cout << "Enter the total purchase value in dollars: ";
    cin >> totalPurchase;
    
    double discount = 0.0;

    // Check for discounts based on the total purchase value
    if (totalPurchase > 100.0) {
        discount = 0.10;  // 10% discount for purchases over $100
    } else if (totalPurchase > 50.0) {
        discount = 0.05;  // 5% discount for purchases over $50
    }

    double discountedPrice = totalPurchase - (totalPurchase * discount);

    // Display the discounted price
    cout << "Discounted Price: $" << discountedPrice << endl;

    return 0;
}
