#include <iostream>
#include <string>

// In your C++ folder, create a new file called "rectangle.cpp". In this file, create a main function as usual. Then create a class called "Rectangle." It should have as attributes "length" and "width" (both integers). Develop the class using the design principles we have been using to design classes (e.g., the attributes should be private variables, and there should be at least one constructor and public getter and setter methods for each attribute). Then, create a public method "getArea()" that calculates and returns the area of the rectangle. Use the Dog class we have been working on as a template to help you write the code for the Rectangle class. Then, in the main function, create a Rectangle object named "rectangle" with length = 5 and width = 3. Print out the area of rectangle by printing the value returned by its "getArea()" method. Make sure to have "#include <string>" and "#include <iostream>" at the top of the file.

class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle(int l, int w) : length(l), width(w) {}

    int getLength() const {
        return length;
    }

    void setLength(int l) {
        length = l;
    }

    int getWidth() const {
        return width;
    }

    void setWidth(int w) {
        width = w;
    }

    int getArea() const {
        return length * width;
    }
};

int main() {
    Rectangle rectangle(5, 3);

    std::cout << "The area of the rectangle is: " << rectangle.getArea() << std::endl;

    return 0;
}
