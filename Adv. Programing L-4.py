#include <iostream>
#include <cmath>

from tkinter import DoubleVar
from token import DOUBLESLASH


class Shape {
protected:
    std::string color;

public:
    Shape(const std::string& col) : color(col) {}

    // Public method to get the color
    std::string getColor() const {
        return color;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const std::string& col, double r) : Shape(col), radius(r) {}

    double calculateArea() const {
        return 3.14 * std::pow(radius, 2);
    }

    // Function to change color and print area with color
    void changeColorAndPrint() {
        // Accessing the color member directly (protected)
        color = "Blue";

        // Accessing the color through the public method
        // color = getColor();  // Uncomment this line to use the public method

        std::cout << "Circle - Color: " << color << ", Area: " << calculateArea() << std::endl;
    }
};

class Rectangle : public Shape {
private:
    DOUBLESLASH length;
    DoubleVar width;

public:
    Rectangle(const std::string& col, double len, double wid) : Shape(col), length(len), width(wid) {}

    double calculateArea() const {
        return length * width;
    }

    // Function to change color and print area with color
    void changeColorAndPrint() {
        // Accessing the color member directly (protected)
        color = "Red";

        // Accessing the color through the public method
        // color = getColor();  // Uncomment this line to use the public method

        std::cout << "Rectangle - Color: " << color << ", Area: " << calculateArea() << std::endl;
    }
};

int main() {
    Circle myCircle("Green", 5.0);
    Rectangle myRectangle("Yellow", 4.0, 6.0);

    // Demonstrate changing color and printing area
    myCircle.changeColorAndPrint();
    myRectangle.changeColorAndPrint();

    return 0;
}
