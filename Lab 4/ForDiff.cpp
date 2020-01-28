#include <iostream>

using namespace std;

int main()
{
    int x[4], y[4], d[4], dd[4], ddd[4], bd[4], bdd[4], bddd[4];
    d[4] = dd[4] = dd[3] = ddd[4] = ddd[3] = ddd[2] = bd[0] = bdd[0] = bdd[1] = bddd[0] = bddd[1] = bddd[2] = 0;
    cout << "Enter the value of x: ";
    for(int i = 0; i < 4; i++)
    {
        cin >> x[i];
    }
    cout << "Enter the value of y: ";
    for(int i = 0; i < 4; i++)
    {
        cin >> y[i];
    }
    double xx;
    cout << "Enter the value of x to find corresponding output: ";
    cin >> xx;

    double p = (double) (xx - x[0]) / (x[1] - x[0]);

    cout << "\nP = " << p << endl;

    for(int i = 0; i < 3; i++)
    {
        d[i] = y[i + 1] - y[i];
    }
    for(int i = 0; i < 2; i++)
    {
        dd[i] = d[i + 1] - d[i];
    }
    for(int i = 0; i < 1; i++)
    {
        ddd[i] = dd[i + 1] - dd[i];
    }

    for(int i = 1; i < 4; i++)
    {
        bd[i] = y[i] - y[i - 1];
    }
    for(int i = 2; i < 4; i++)
    {
        bdd[i] = bd[i] - bd[i - 1];
    }
    for(int i = 3; i < 4; i++)
    {
        bddd[i] = bdd[i] - bdd[i - 1];
    }

    cout << "\nx\ty\tD1\tD2\tD3\n"; 
    for(int i = 0; i < 4; i++)
    {
        ddd[3] = 0;
        cout << x[i] << "\t" << y[i] << "\t" << d[i] << "\t" << dd[i] << "\t" << ddd[i] << endl;
    }

    cout << "\nx\ty\tBD1\tBD2\tBD3\n"; 
    for(int i = 0; i < 4; i++)
    {
        cout << x[i] << "\t" << y[i] << "\t" << bd[i] << "\t" << bdd[i] << "\t" << bddd[i] << endl;
    }


    double fy = x[0] + p*d[0] + p*(p-1)*dd[0]/2 + p*(p-1)*(p-2)*ddd[0]/6;

    //double by = x[4] + p*bd[4] + p*(p-1)*bdd[4]/2 + p*(p-1)*(p-2)*bddd[4]/6;

    cout << fy << endl; 


}