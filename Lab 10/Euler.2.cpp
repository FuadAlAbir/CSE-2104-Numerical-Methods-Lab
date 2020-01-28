#include <iostream>

using namespace std;

double dFunc(double x, double y) {
    return x - y * y;
}

int main() {
    double Xo, Yo, Y1, h, X;
    double k1, k2, k3, k4;
    cin >> Xo >> Yo >> X;
    while(1) {
        cin >> h;
        while(Xo != X) {
            k1 = h * dFunc(Xo, Yo);
            k2 = h * dFunc((Xo + h/2.0), (Yo + k1/2.0));
            k3 = h * dFunc((Xo + h/2.0), (Yo + k2/2.0));
            k4 = h * dFunc((Xo + h), (Yo + k3));
            Xo = Xo + h;
            Y1 = Yo + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
            }
            cout << Y1 << endl;
    }
}
