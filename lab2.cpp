#include <iostream>
#include <math.h>

using namespace std;

const int MAX_N = 100;

double factorial(double i)
{
    if (i == 0.0)
    {
        return 1.0;
    }
    else
    {
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
double getValue()
{
    while (true)
    {
        cout << "Enter x: ";
        double x;
        cin >> x;
        if (cin.fail())
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(32767, '\n');
                cout << "Input error. You need to enter a number, not a letter.\n \n";
            }
        }
        else
        {
            cin.ignore(32767, '\n');
            return x;
        }
    }
}
int main()
{
    double x = getValue();
    cout << "Exp = " <<myExp(x);
}
