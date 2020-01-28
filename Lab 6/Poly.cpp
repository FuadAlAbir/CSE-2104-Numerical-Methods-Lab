#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of data: ";
    cin >> n;
    double x[n], y[n], sumX = 0, lnY = 0, sumXX = 0, sumXY = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout << x[i] << "\t" << log(y[i]) << "\t" << x[i]*x[i] << "\t" << x[i]*log(y[i]) << endl;
        sumX = sumX + x[i];
        lnY = lnY + log(y[i]);
        sumXX = sumXX + x[i]*x[i];
        sumXY = sumXY + x[i]*log(y[i]);
    }
    cout << sumX << "\t" << lnY << "\t" << sumXX << "\t" << sumXY << endl;

    double D = n*sumXX - sumX*sumX;
    double a0 = (lnY*sumXX - sumX*sumXY)/D;
    double a1 = (n*sumXY - lnY*sumX)/D;

    double a = exp(a0), b = a1;

    cout << endl << "a0 = " << a0 << "\ta1 = " << a1;
    cout << endl << "a = " << a << "\tb = " << b << endl;

    double iX;
    
    cout << "\nEnter a value to check: ";
    cin >> iX;
    b = b * iX;
    double dY = a*exp(b);
    cout << iX << " = " << dY;
    
    int dn;
    for(int i = 0; i < n; i++)
    {
        if(iX == x[i]) dn = i;
    }
    double ERR = (dY - y[dn])/dY*100;
    cout << "\nPersentage Error: " << ERR << endl;
    
}