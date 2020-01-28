#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x)
{
    return x*x*x - 2*x - 5;
}

double fd(double x)
{
    return 3*x*x - 2;
}

double newRaph(double x)
{
    return x - f(x)/fd(x);
}

int main()
{
    double xo = 1, x1, x2;
    int n = 0;
    while(1)
    {
        x1 = newRaph(xo);
        x2 = newRaph(x1);
        cout << n << "\t" << fixed << setprecision(10) << xo << "\t " << x1 << "\t " << x2 << endl;
        if(fabs(x1 - x2) < .000001)
        {
            cout << "\nRoot: " << x2 << endl;
            break;
        }
        xo = x1;
        x1 = x2;
        n++;
    }
}