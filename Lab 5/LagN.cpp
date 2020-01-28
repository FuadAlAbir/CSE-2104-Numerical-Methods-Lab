#include<iostream>

using namespace std;

int main()
{
    double a[10], b[10];
    int n,i,j;
    double x, X, Y, mul;
    double Value = 0.0;
    cout << "Enter number of data: ";
    cin >> n;
    cout << "Enter the values of x & y";
    cout << "\nX\tY\n";
    for(i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    cout << "Desired X : ";
    cin >> x;
    for(i=0; i < n; i++)
    {
        X=1;
        Y=1;
        for(j = 0; j < n; j++)
        {
            if(j != i)
            {
                X = X*(x-a[j]);
                Y = Y*(a[i]-a[j]);
            }
        }
        mul = (X/Y) * b[i];
        Value += mul;
    }
    cout<< "Desired Output: " << Value <<endl;
    return 0;
}