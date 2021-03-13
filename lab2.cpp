#include <iostream>
#include <math.h>

using namespace std;

const int MAX_N = 100;



double myExp(double x, double eps)
{
      double result = 0;
      int i = 1;
      double d= 1;
      while(fabs(d) > eps)
      {
            result += d;
            d = d*x/i;
            i++;
      }
      return result;
}
double getValue()
{
    while (true)
    {
        cout << "Enter your x: ";
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
    cout << "Your exponent: " <<myExp(x, 0.01);
}
