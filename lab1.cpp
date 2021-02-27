#include <iostream>
#include <math.h>

using namespace std;

int main() {
    const double g = 9.8;
    const double PI = 3.1415;
    double V;
    double a;
    double L;
    setlocale(LC_ALL, "RUS");
    do
    {
        cout << "Введите скорость полета: ";
        cin >> V;
        if (cin.fail())
        {
            cout << "Ошибка ввода: Скорость должна быть числом.\n";
            cin.clear();
            cin.ignore(32767, '\n');
            fflush(stdin);
        }
        else

            if (V <= 0)
            {
                cout << "Ошибка ввода: Скорость не может быть меньше 0.\n";
                cin.clear();
                fflush(stdin);
            }
    } while (V <= 0);

    do
    {
        cout << "Введите угол альфа: ";
        cin >> a;
        if (cin.fail())
        {
            cout << "Ошибка ввода: Угол должен быть числом.\n";
            cin.clear();
            cin.ignore(32767, '\n');
            fflush(stdin);
        }
        else

            if (a <= 0 || a> 90)
            {
                cout << "Ошибка ввода: Угол не может быть меньше 0 или больше 90.\n";
                cin.clear();
                fflush(stdin);
            }
    } while (a <= 0 || a > 90);


    L = (pow(V, 2) * sin(2 * ((a / 180) * PI))) / g;

    cout << "Дальность полёта тела составляет:" << L;

}
