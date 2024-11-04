#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class BinaryAddition {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0;
        
        int maxLength = max(a.length(), b.length());
        a = string(maxLength - a.length(), '0') + a;
        b = string(maxLength - b.length(), '0') + b;
        
        for (int i = maxLength - 1; i >= 0; i--) {
            int bit1 = a[i] - '0';
            int bit2 = b[i] - '0';
            
            int sum = bit1 + bit2 + carry;
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        
        if (carry) {
            result.push_back('1');
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    bool isValidBinary(const string& str) {
        return str.find_first_not_of("01") == string::npos;
    }
};

int main() {
    BinaryAddition calculator;
    string binary1, binary2;
    
    cout << "Binary Number Addition Program\n";
    cout << "------------------------------\n\n";
    
    while (true) {
        cout << "Enter first binary number: ";
        cin >> binary1;
        
        if (!calculator.isValidBinary(binary1)) {
            cout << "Error: Invalid binary number! Please use only 0s and 1s.\n\n";
            continue;
        }
        
        cout << "Enter second binary number: ";
        cin >> binary2;
        
        if (!calculator.isValidBinary(binary2)) {
            cout << "Error: Invalid binary number! Please use only 0s and 1s.\n\n";
            continue;
        }
        
        string sum = calculator.addBinary(binary1, binary2);
        
        cout << "\nCalculation:\n";
        cout << string(max(binary1.length(), binary2.length()) + 2, ' ') 
             << binary1 << endl;
        cout << string(max(binary1.length(), binary2.length()) + 2 - binary2.length(), ' ') 
             << "+" << binary2 << endl;
        cout << string(max(binary1.length(), binary2.length()) + 3, '-') << endl;
        cout << string(max(binary1.length(), binary2.length()) + 2 - sum.length(), ' ') 
             << " " << sum << endl;
        
        char choice;
        cout << "\nDo you want to add more binary numbers? (y/n): ";
        cin >> choice;
        
        if (tolower(choice) != 'y') {
            cout << "\nThank you for using the Binary Addition Calculator!\n";
            break;
        }
        cout << "\n";
    }
    
    return 0;
}