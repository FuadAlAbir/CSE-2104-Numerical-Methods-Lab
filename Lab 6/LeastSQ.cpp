#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of data: ";
    cin >> n;
    double x[n], y[n], sumX = 0, sumY = 0, sumXX = 0, sumXY = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << "------------------------------\nX\t  Y\tX^2\t XY\n------------------------------" << endl; 
    for(int i = 0; i < n; i++)
    {
        cout << x[i] << "\t" << y[i] << "\t" << x[i]*x[i] << "\t" << x[i]*y[i] << endl;
        sumX = sumX + x[i];
        sumY = sumY + y[i];
        sumXX = sumXX + x[i]*x[i];
        sumXY = sumXY + x[i]*y[i];
    }
    cout << "------------------------------\n" << sumX << "\t" << sumY << "\t" << sumXX << "\t" << sumXY << endl;

    double D = n*sumXX - sumX*sumX;
    double a0 = (sumY*sumXX - sumX*sumXY)/D;
    double a1 = (n*sumXY - sumY*sumX)/D;

    cout << endl << "a0 = " << a0 << "\ta1 = " << a1 << endl;
    double iX;
    
    cout << "Enter a value to check: ";
    cin >> iX;
    
    double dY = a0 + a1*iX;
    cout << iX << " = " << dY << endl;
    
    int dn;
    for(int i = 0; i < n; i++)
    {
        if(iX == x[i]) dn = i;
    }
    double ERR = (dY - y[dn])/dY*100;
    cout << "Persentage Error: " << ERR << endl;
}