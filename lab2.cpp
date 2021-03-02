#include <iostream>
#include <math.h>

using namespace std;

const int MAX_N = 100;

double factorial(double i) {
    if (i == 0.0) {
        return 1.0;
    }
    else {
        double result = i * factorial(i - 1.0);
        return result;
    }
}


double myExp(double x)
{
    double result = 0;
    double i = 1;
    double add;
    for (int i = 0; i < MAX_N; i++)
    {
        add = pow(x, i) / factorial(i);
        result += add;
    }
    return result;
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << "Exp = " <<myExp(x);
}
