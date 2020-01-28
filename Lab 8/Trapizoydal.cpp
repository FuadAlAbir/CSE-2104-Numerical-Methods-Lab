#include <iostream>
#include <cmath>

#define size 100

using namespace std;

double func(double x) {
    return 1/(1 + x);
}

int main() {
    double ax[size], ay[size];
    double trapizoydal = 0, simpsonOneThird = 0, simpsonThreeEighth = 0;
    int n, u, l;
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

    // trapizoydal
    for(int i = 1; i < n; i++) {
        trapizoydal += (h * ay[i]);
    }
    trapizoydal += (h * ay[n]/2) + (h * ay[0]/2);

    // one third
    for(int i = 1; i < n; i += 2) {
        simpsonOneThird += (4*h*ay[i]/3.0);
        if(7 == i) break;
        simpsonOneThird += (2*h*ay[i+1]/3.0);
    }
    simpsonOneThird += h*ay[n]/3 + h*ay[0]/3;
    
    // three eighth
    for(int i = 3; i <= n - 2; i += 3) {
        simpsonThreeEighth += 6*h/8.0*ay[i];
    }
    for(int i = 1; i <= n; i++) {
        if(i % 3 == 0) continue;
        simpsonThreeEighth += 9*h/8.0*(ay[i]);
    }
    simpsonThreeEighth += 3*h/8.0*ay[n] + 3*h/8.0*ay[0];

    cout << "\nTrapizoydal: " << trapizoydal << endl;
    cout << "Simpson One Third: " << simpsonOneThird << endl;
    cout << "Simpson Three Eighth: " << simpsonThreeEighth << endl;

}

