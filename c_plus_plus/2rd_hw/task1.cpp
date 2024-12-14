#include <iostream>
#include <numeric> 
#include <stdexcept> 
#include <cmath>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) { // Ensure the denominator positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructors
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }

    // Getters
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Setters
    void setNumerator(int num) {
        numerator = num;
        simplify();
    }

    void setDenominator(int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        denominator = denom;
        simplify();
    }

    Fraction& operator+=(const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        numerator *= other.denominator;
        denominator *= other.numerator;
        simplify();
        return *this;
    }

    //  arithmetic operator
    Fraction operator+(const Fraction& other) const {
        Fraction result = *this;
        result += other;
        return result;
    }

    Fraction operator-(const Fraction& other) const {
        Fraction result = *this;
        result -= other;
        return result;
    }

    Fraction operator*(const Fraction& other) const {
        Fraction result = *this;
        result *= other;
        return result;
    }

    Fraction operator/(const Fraction& other) const {
        Fraction result = *this;
        result /= other;
        return result;
    }

    // 输入和输出运算
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
        out << fraction.numerator << "/" << fraction.denominator;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Fraction& fraction) {
        char slash;
        in >> fraction.numerator >> slash >> fraction.denominator;
        if (fraction.denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        fraction.simplify();
        return in;
    }

    // 搞成double
    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

    Fraction& operator=(const Fraction& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }

    static bool isRational(double value) {
        double intPart;
        double fracPart = std::modf(value, &intPart);
        if (fracPart == 0.0) {
            return true; 
        }
        const double epsilon = 1e-9;
        for (int denom = 1; denom <= 100000; ++denom) {
            double num = fracPart * denom;
            if (std::fabs(num - std::round(num)) < epsilon) {
                return true;
            }
        }
        return false;
    }
};

// Manue
void showMenu() {
    std::cout << "\n========= Fraction Program =========\n";
    std::cout << "1. Add two fractions\n";
    std::cout << "2. Subtract two fractions\n";
    std::cout << "3. Multiply two fractions\n";
    std::cout << "4. Divide two fractions\n";
    std::cout << "5. Convert fraction to double\n";
    std::cout << "6. Check if a number is rational\n";
    std::cout << "7. Exit\n";
    std::cout << "===================================\n";
}

int main() {
    while (true) {
        showMenu();
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Fraction a, b;
            std::cout << "Enter first fraction (numerator/denominator): ";
            std::cin >> a;
            std::cout << "Enter second fraction (numerator/denominator): ";
            std::cin >> b;
            std::cout << "Result: " << (a + b) << "\n";
            break;
        }
        case 2: {
            Fraction a, b;
            std::cout << "Enter first fraction (numerator/denominator): ";
            std::cin >> a;
            std::cout << "Enter second fraction (numerator/denominator): ";
            std::cin >> b;
            std::cout << "Result: " << (a - b) << "\n";
            break;
        }
        case 3: {
            Fraction a, b;
            std::cout << "Enter first fraction (numerator/denominator): ";
            std::cin >> a;
            std::cout << "Enter second fraction (numerator/denominator): ";
            std::cin >> b;
            std::cout << "Result: " << (a * b) << "\n";
            break;
        }
        case 4: {
            Fraction a, b;
            std::cout << "Enter first fraction (numerator/denominator): ";
            std::cin >> a;
            std::cout << "Enter second fraction (numerator/denominator): ";
            std::cin >> b;
            std::cout << "Result: " << (a / b) << "\n";
            break;
        }
        case 5: {
            Fraction a;
            std::cout << "Enter a fraction (numerator/denominator): ";
            std::cin >> a;
            std::cout << "As double: " << a.toDouble() << "\n";
            break;
        }
        case 6: {
            double value;
            std::cout << "Enter a number: ";
            std::cin >> value;
            if (Fraction::isRational(value)) {
                std::cout << value << " is a rational number." << std::endl;
            } else {
                std::cout << value << " is not a rational number." << std::endl;
            }
            break;
        }
        case 7:
            std::cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
