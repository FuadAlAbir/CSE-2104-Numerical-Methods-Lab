#include<iostream>

using namespace std;

double func(double y) {
    return - y;
}
int main(){
    double x, y, h, input_x, temp;
    cin >> x >> y >> h >> input_x;

    while(x != input_x){
        temp = h * func(y);
        y = y + temp;
        x = x + h;
    }
    cout << y << endl;
}

