#include <iostream>
#include <math.h>

using namespace std;

double getDouble();
long long int fact(int number);

int main()
{
    double input = 0;
    double x = 0;
    double sum = 0;
    double term = 0;
    int i = 0;
    const double rad = 2 * 3.1415;
    long long int factorial = 0;


    cout << "Enter x: ";
    input = getDouble();
    x = input;
    if (x > 0)
        while (x > rad) {
            x -= rad;
        }
    else if (x < 0)
        while (x < -rad) {
            x -= -rad;
        }

    do
    {
        factorial = fact(2 * i + 1);
        term = pow(-1, i) * (pow(x, 2 * i + 1) / factorial);
        sum += term;
        i++;
        if (2 * i + 1 >= 20)
            break;
    } while (abs(term) >= 0.001);

    cout << "Sin(" << input << ") = " << sum;
}

double getDouble() {
    while (true) {
        double number;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Do input again." << endl;
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}

long long int fact(int number)
{
    if (number < 0)
        return 0;
    if (number == 0)
        return 1;
    else
        return number * fact(number - 1);
}
