#include <iostream>
#define size 5
#define dySize 4
#define ddySize 3
using namespace std;

int main() {
    double x[size], y[size], dy[size], ddy[size], dddy[size], ddddy[size], bd[size], bdd[size], bddd[size];
    dy[4] = ddy[4] = ddy[3] = dddy[4] = dddy[3] = dddy[2] = bd[0] = bdd[0] = bdd[1] = bddd[0] = bddd[1] = bddd[2] = 0;

    for(int i = 0; i < size; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < dySize; i++) {
        dy[i] = y[i + 1] - y[i];
    }
    for(int i = 0; i < ddySize; i++) {
        ddy[i] = dy[i + 1] - dy[i];
    }
    cout << "X\tY\tdY\tddY\n";
    for(int i = 0; i < size; i++) {
        cout << x[i] << "\t" << y[i] << "\t" << dy[i] << "\t" << ddy[i] << endl;
    }

    int index = 0;
    double h = x[index + 1] - x[index];
    double p = (-2*dy[index]/ddy[index] + 1) / 2.0;
    cout << "p = " << p << endl;
    double maxX = x[index] + p*h;
    cout << "Max_X = " << maxX << endl;

    double xx = maxX;

    double pn = (double) (xx - x[0]) / (x[1] - x[0]);
    dddy[0] = ddy[0] - ddy[1];
    dddy[1] = ddy[1] - ddy[2];
    ddddy[0] = dddy[0] - dddy[1];
    ddddy[1] = ddddy[2] = ddddy[3] = ddddy[4] = 0;

    cout << "X\tY\tdY\tddY\tdddY\tddddY\n";
    for(int i = 0; i < 5; i++)
    {
        dddy[3] = 0;
        cout << x[i] << "\t" << y[i] << "\t" << dy[i] << "\t" << ddy[i] << "\t" << dddy[i] << "\t" << ddddy[i] << endl;
    }

    double fy = x[0] + pn*dy[0] + pn*(pn-1)*ddy[0]/2 + pn*(pn-1)*(pn-2)*dddy[0]/6;

    cout << "new P = " << pn << "\nMaximum output for MaxX: " << fy << endl; 

}