#include <iostream>

using namespace std;

int main()
{
    int size;
    cin >> size;
    double x[size], y[size];

    for(int i = 0; i < size; i++)
    {
        cin >> x[i] >> y[i];
    }

    double mulUp = 1.0, mulDn = 1.0;
    double value;
    double givenX;
    cin >> givenX;
    int count = 0;
    for(int j = 0; j < size; j++)
    {
        for(int i = 0; i < size; i++)
        {
            if(i == count)
            {
                continue;
            }
            mulUp *= givenX - x[i];
            count++;
            cout << mulUp << endl;
        }
        count = 0;
        for(int i = 1; i < size; i++)
        {
            if(i == count)
            {
                continue;
            }
            mulDn *= x[0] - x[i];
            count++;
            cout << mulDn << endl;
        }
        value += mulUp/mulDn*y[j];
        mulUp = 1;
        mulDn = 1;
        cout << value << endl;
    }
    //cout << value;
}