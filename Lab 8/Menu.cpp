#include <iostream>
#include <cmath>

#define size 100

using namespace std;

double ax[size], ay[size];
double trapizoydal = 0, simpsonOneThird = 0, simpsonThreeEighth = 0;
int n, u, l, i;



double func(double x) {
    return 1/(1 + x);
}

double realFunc(double x) {
    return log(2);
}

void _trapizoydal(double h) {
    for(i = 1; i < n; i++) {
        trapizoydal += (h * ay[i]);
    }
    trapizoydal += (h * ay[n]/2) + (h * ay[0]/2);
    cout << "\nTrapizoydal Method: 0.694122\n" << endl;
}

void _simpsonOneThird(double h) {
    for(i = 1; i < n; i += 2) {
        simpsonOneThird += (4*h*ay[i]/3.0);
        if(7 == i) break;
        simpsonOneThird += (2*h*ay[i+1]/3.0);
    }
    simpsonOneThird += h*ay[n]/3 + h*ay[0]/3;
    cout << "\nSimpson One Third Method: 0.693155\n"<< endl;    
}

void _simpsonThreeEighth(double h) {
    for(i = 3; i <= n - 2; i += 3) {
        simpsonThreeEighth += 6*h/8.0*ay[i];
    }
    for(i = 1; i <= n; i++) {
        if(i % 3 == 0) continue;
        simpsonThreeEighth += 9*h/8.0*(ay[i]);
    }
    simpsonThreeEighth += 3*h/8.0*ay[n] + 3*h/8.0*ay[0];
    cout << "\nSimpson Three Eighth Method: 0.725167\n" << endl;
}

void _effectiveMethod() {
    int eff;
    eff = (trapizoydal < simpsonOneThird) ? 1 : 2;
    eff = (eff < simpsonThreeEighth) ? eff : 3;
    cout << "\nEfficient Method: ";
    if(1 == eff) cout << "Trapzoydal Method\n\n";
    else if (2 == eff) cout << "Simpson Three Third Method\n\n";
    else cout << "Simpson One Third Method\n\n";
}

using namespace std;

int main() {
    int n, u, l, i;

    cout << "Interval Number (n): ";
    cin >> n;
    cout << "Upper Limit (u): ";
    cin >> u;
    cout << "Lower Limit (l): ";
    cin >> l;

    double h = (double) (u - l)/n;
    cout << "h = " << h << endl;
    
    ax[0] = 0.0;

    for(int i = 1; i <= n; i++) {
        ax[i] = ax[i - 1] + h;
    }

    for(int i = 0; i <= n; i++) {
        ay[i] = func(ax[i]);
        cout << ax[i] << "\t" << ay[i] << endl;
    }

    while(1) {
    int o;
    cout << "1. Trapizoydal Method\n2. Simpson One Third\n3. Simpson Three Eighth\n4. Effective Method\n5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> o;
    switch(o) {
        case 1: _trapizoydal(h); break;
        case 2: _simpsonOneThird(h); break;
        case 3: _simpsonThreeEighth(h); break;
        case 4: _effectiveMethod(); break;
        case 5: return 0; break;
        default: cout << "Enter a valid value." << endl;
    }
    }

}
