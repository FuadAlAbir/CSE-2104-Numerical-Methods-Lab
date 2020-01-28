#include <iostream>

#define size 7
#define dySize size - 1
#define ddySize size - 2
#define d3Size size - 3
#define d4Size size - 4
#define d5Size size - 5
#define d6Size size - 6

using namespace std;

int main() {
    double ax[size], ay[size], dy[dySize], ddy[ddySize], d3y[d3Size], d4y[d4Size], d5y[d5Size], d6y[d6Size];

   for(int i = 0; i < size; i++) {
        cin >> ax[i] >> ay[i];
    }
    for(int i = 0; i < dySize; i++) {
        dy[i] = ay[i + 1] - ay[i];
    }
    for(int i = 0; i < ddySize; i++) {
        ddy[i] = dy[i + 1] - dy[i];
    }
    for(int i = 0; i < d3Size; i++) {
        d3y[i] = ddy[i + 1] - ddy[i];
    }
    for(int i = 0; i < d4Size; i++) {
        d4y[i] = d3y[i + 1] - d3y[i];
    }
    for(int i = 0; i < d5Size; i++) {
        d5y[i] = d4y[i + 1] - d4y[i];
    }
    for(int i = 0; i < d6Size; i++) {
        d6y[i] = d5y[i + 1] - d5y[i];
    }
    cout << "X\tY\tdY\tddY\td3Y\td4Y\td5Y\td6Y\n";
    for(int i = 0; i < size; i++)
    {
        cout << ax[i] << "\t" << ay[i] << "\t" << dy[i] << "\t" << ddy[i] << "\t" << d3y[i] << "\t" << d4y[i] << "\t" << d5y[i] << "\t" << d6y[i] << endl;
    }
    double inputX;
    int index;
    cout << "Enter x: ";
    cin >> inputX;
    for(int i = 0; i < size; i++) {
        if(inputX == ax[i]) {
            index = i;
            break;
        }
    }
    cout << "Index = " << index << endl;
    double h = 1 / (ax[1] - ax[0]);
    
    double diffY = h * (dy[index] - .5*ddy[index] + d3y[index]/3.0 - .25*d4y[index] + .2*d5y[index]);
    double doublediffY = h * h * (ddy[index] - d3y[index] + 11/12.0 * d4y[index] - 5/6.0 * d5y[index]);
    cout << "dy/dx = " << diffY << endl;
    cout << "ddy/ddx = " << doublediffY << endl;
}