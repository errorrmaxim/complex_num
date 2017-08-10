#include "complex_num.h"


int main(int argc, char *argv[])
{
    complex_num<double>a;
    complex_num<double>b;
    complex_num<double>answ;
    char operation;
    cout << "Input complex numper separetly: a = "; cin >> a;
    cout << "Input complex numper separetly: b = "; cin >> b;
    cout << "Choose operation + | - | / | * :"; cin >> operation;

    switch (operation) {
            case '+': answ = a + b;break;
            case '-': answ = a - b;break;
            case '/': answ = a / b;break;
            case '*': answ = a * b;break;
    default: cout << "Undefined operation!" << endl;
                     return -1;
        break;
    }

    cout << a << " + " << b << " = " << answ << endl;
    return 0;
}
