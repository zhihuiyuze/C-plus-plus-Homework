#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

class Vector {
private:
    std::vector<double> elements;

public:
    Vector() {}
    Vector(std::initializer_list<double> init) : elements(init) {}
    Vector(size_t size, double value = 0.0) : elements(size, value) {}

    double get(size_t index) const {
        if (index >= elements.size()) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    void set(size_t index, double value) {
        if (index >= elements.size()) {
            throw std::out_of_range("Index out of range");
        }
        elements[index] = value;
    }

    size_t size() const {
        return elements.size();
    }

    Vector& operator+=(const Vector& other) {
        if (elements.size() != other.elements.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        for (size_t i = 0; i < elements.size(); ++i) {
            elements[i] += other.elements[i];
        }
        return *this;
    }

    Vector& operator-=(const Vector& other) {
        if (elements.size() != other.elements.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        for (size_t i = 0; i < elements.size(); ++i) {
            elements[i] -= other.elements[i];
        }
        return *this;
    }

    Vector& operator*=(double scalar) {
        for (double& element : elements) {
            element *= scalar;
        }
        return *this;
    }

    Vector operator+(const Vector& other) const {
        Vector result = *this;
        result += other;
        return result;
    }

    Vector operator-(const Vector& other) const {
        Vector result = *this;
        result -= other;
        return result;
    }

    Vector operator*(double scalar) const {
        Vector result = *this;
        result *= scalar;
        return result;
    }

    double operator*(const Vector& other) const {
        if (elements.size() != other.elements.size()) {
            throw std::invalid_argument("Vectors must be of the same size");
        }
        double result = 0.0;
        for (size_t i = 0; i < elements.size(); ++i) {
            result += elements[i] * other.elements[i];
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "[";
        for (size_t i = 0; i < vec.elements.size(); ++i) {
            os << vec.elements[i];
            if (i != vec.elements.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector& vec) {
        size_t size;
        is >> size;
        vec.elements.resize(size);
        for (size_t i = 0; i < size; ++i) {
            is >> vec.elements[i];
        }
        return is;
    }

    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            elements = other.elements;
        }
        return *this;
    }
};

Vector operator*(double scalar, const Vector& vec) {
    return vec * scalar;
}

int main() {
    Vector v1, v2;
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Input Vector 1\n";
        std::cout << "2. Input Vector 2\n";
        std::cout << "3. Display Vectors\n";
        std::cout << "4. Add Vectors\n";
        std::cout << "5. Subtract Vectors\n";
        std::cout << "6. Scalar Product\n";
        std::cout << "7. Multiply Vector by Scalar\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Vector 1 (size followed by elements): ";
                std::cin >> v1;
                break;
            case 2:
                std::cout << "Enter Vector 2 (size followed by elements): ";
                std::cin >> v2;
                break;
            case 3:
                std::cout << "Vector 1: " << v1 << "\n";
                std::cout << "Vector 2: " << v2 << "\n";
                break;
            case 4: {
                try {
                    Vector v3 = v1 + v2;
                    std::cout << "Result of addition: " << v3 << "\n";
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 5: {
                try {
                    Vector v3 = v1 - v2;
                    std::cout << "Result of subtraction: " << v3 << "\n";
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 6: {
                try {
                    double scalarProduct = v1 * v2;
                    std::cout << "Scalar product: " << scalarProduct << "\n";
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 7: {
                double scalar;
                std::cout << "Enter scalar value: ";
                std::cin >> scalar;
                Vector v3 = v1 * scalar;
                std::cout << "Result of multiplication: " << v3 << "\n";
                break;
            }
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
