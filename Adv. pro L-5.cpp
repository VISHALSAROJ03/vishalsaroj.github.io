#include <iostream>
#include <vector>

int main() {
    // Create a vector of integers
    std::vector<int> myVector;

    // Populate the vector with some integers
    myVector.push_back(5);
    myVector.push_back(10);
    myVector.push_back(15);
    myVector.push_back(20);
    myVector.push_back(25);

    // Display the contents of the vector
    std::cout << "Vector elements: ";
    for (int num : myVector) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}
