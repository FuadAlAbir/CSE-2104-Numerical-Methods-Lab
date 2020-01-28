#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of data: ";
    cin >> n;
    double x[n], y[n], sumX = 0, sumY = 0, sumXX = 0, sumX3 = 0, sumX4 = 0, sumXY = 0, sumXXY = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << "-----------------------------------------------------\nX\tY\tX^2\tX^3\tX^4\tXY\tX^2Y\n-----------------------------------------------------" << endl; 
    for(int i = 0; i < n; i++)
    {
        cout << x[i] << "\t" << y[i] << "\t" << x[i]*x[i] << "\t" << x[i]*x[i]*x[i] << "\t" << x[i]*x[i]*x[i]*x[i] << "\t" << x[i]*y[i] << "\t" << x[i]*x[i]*y[i] << endl;
        sumX = sumX + x[i];
        sumY = sumY + y[i];
        sumXX = sumXX + x[i]*x[i];
        sumX3 = sumX3 + x[i]*x[i]*x[i];
        sumX4 = sumX4 + x[i]*x[i]*x[i]*x[i];
        sumXY = sumXY + x[i]*y[i];
        sumXXY = sumXXY + x[i]*x[i]*y[i];
    }
    cout << "------------------------------------------------------------" << endl;
    cout << sumX << "\t" << sumY << "\t" << sumXX << "\t" << sumX3 << "\t" << sumX4 << "\t" << sumXY << "\t" << sumXXY << endl;

    double D = n * (sumX4 * sumXX - sumX3 * sumX3) - sumX * (sumX * sumX4 - sumX3 * sumXX) + sumXX * (sumX * sumX3 - sumXX * sumXX);
    double a0 = (sumX * (sumX3 * sumXXY - sumXY * sumX4) - sumXX * (sumXX * sumXXY  - sumXY * sumX3) + sumY * (sumXX * sumX4 - sumX3 * sumX3))/D;
    double a1 = (n * (sumX3 * sumXXY - sumXY * sumX4) - sumXX * (sumX * sumXXY - sumXY * sumXX) + sumY * (sumX * sumX4 - sumXX * sumX3))/D;
    double a2 = (n * (sumXX * sumXXY - sumXY * sumX3) - sumX * (sumX * sumXXY - sumXX * sumXY) + sumY * (sumX * sumX3 - sumXX * sumXX))/D;
    a1 = a1 * -1;
    cout << endl << "a0 = " << a0 << "\ta1 = " << a1 << "\ta2 = " << a2 << endl;

    double iX;
    cout << "Enter a value to check: ";
    cin >> iX;
    
    double dY = a0 + a1*iX + a2*iX*iX;
    cout << iX << " = " << dY << endl;
    
    int dn;
    for(int i = 0; i < n; i++)
    {
        if(iX == x[i]) dn = i;
    }
    double ERR = (dY - y[dn])/dY*100;
    cout << "Persentage Error: " << ERR << endl;
}