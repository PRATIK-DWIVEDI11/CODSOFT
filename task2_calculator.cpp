#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose one operation (+, -, *, /): ";
    cin >> operation;

    switch(operation) {
        case '+':
            cout << "Addition is: " << num1 + num2;
            break;
        case '-':
            cout << "Substraction is: " << num1 - num2;
            break;
        case '*':
            cout << "Multiplication is: " << num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                cout << "Divison is: " << num1 / num2;
            else
                cout << "Not defined!";
            break;
        default:
            cout << "Choose from above operation!";
    }

    return 0;
}
