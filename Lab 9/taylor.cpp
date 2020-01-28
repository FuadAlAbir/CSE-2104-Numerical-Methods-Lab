#include <iostream>
#include <cmath>

using namespace std;

double _dy (double x, double y) {
    return x - y * y;
}

double _ddy (double x, double y) {
    return 1 - 2 * y * _dy(x, y);
}

double _d3y (double x, double y) {
    return - 2 * y * _ddy(x, y) - 2 * _dy(x, y) * _dy(x, y);
}

double _d4y (double x, double y) {
    return - 2 * y * _d3y(x, y) - 2 * _dy(x, y) * _ddy(x, y);
}

double _d5y (double x, double y) {
    return - 2 * y * _d4y(x, y) - 8 * _dy(x, y) * _d3y(x, y) - 6 * _ddy(x, y) * _ddy(x, y);
}

double result_Y (double new_x, double x, double y) {
    return 1 + new_x * _dy(x, y) + pow(new_x, 2) * _ddy(x, y) / 2 + pow(new_x, 3) * _d3y(x, y) / 6 + pow(new_x, 4) * _d4y(x, y) / 24 + pow(new_x, 4) * _d5y(x, y) / 120;
}

int main() {
    double input_x, x, y;
    cout << "Enter input value to find desired output: ";
    cin >> input_x;
    cout << "Enter initial value of x and y respectively: ";
    cin >> x >> y;
    cout << result_Y(input_x, x, y);   
}