#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int i;
    double d;
    double a[3];
    double b[3];
    double res = 0;
    double f, h, alpha, y;
    cout << "a= ";
    for (i = 0; i < 3; i++)
        cin >> a[i];
    cout << "b= ";
    for (i = 0; i < 3; i++)
        cin >> b[i];
    for (i = 0; i < 3; i++)
        res += a[i] * b[i];
    d = res;
    f = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    h = sqrt(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
    y = acos(d / (f * h));
    cout << "alpha= " << y;
}
