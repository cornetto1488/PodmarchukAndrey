#include <iostream>
#include <math.h>

using namespace std;

double getDouble();
long long int fact(int number);

class sinx {
public:
    sinx();
    double getSinx();
    double getInput();
private:
    double x = 0;
    const double rad = 2 * 3.1415;
    double input = 0;
    double border;
    double sum = 0;
    void calculate();
};

sinx::sinx() {
    cout << "Enter x: ";
    x = getDouble();
    input = x;
    if (x > 0)
        while (x > rad) {
            x -= rad;
        }
    else if (x < 0)
        while (x < -rad) {
            x -= -rad;
        }
    cout << "Enter border (border must be in range (0, 1]: ";
    while (true) {
        border = getDouble();
        if (border <= 0 || border > 1)
            cout << "Do input again: ";
        else
            break;
    }
}

void sinx::calculate() {
    int i = 0;
    double term = 0;
    do
    {
        long long int factorial = 0;
        factorial = fact(2 * i + 1);
        term = pow(-1, i) * (pow(x, 2 * i + 1) / factorial);
        sum += term;
        i++;
        if (2 * i + 1 >= 20)
            break;
    } while (abs(term) >= border);
}

double sinx::getInput() {
    return input;
}

double sinx::getSinx() {
    calculate();
    return sum;
}

int main()
{
    sinx sin;
    cout << "Sin(" << sin.getInput() << ") = " << sin.getSinx();
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
