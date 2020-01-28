#include<bits/stdc++.h>
using namespace std;

double arr1[100];
double arr2[100];
double DIV[100];

double find_B(int n)
{
    double sum=0.0;
    for(int i=1;i<n;i++)
    {
        sum = sum + (1.0*arr1[i]*arr2[n-i]);
    }
    return sum;
}

void div()
{
    cout<<" n\t DIV\n"<<endl;
    for(int i=1;i<10;i++)
    {
        DIV[i]=(arr2[i]/(1.0*arr2[i+1]));
    }
    cout<<"\n";
}

int main()
{
    double x,a,b,c,d;
    double fx;
    cout<<"Equation's Co-efficients"<<endl;

    cin>> a >> b >>  c >> d;

    arr1[1]= c/(-d);
    arr1[2]= b/(-d);
    arr1[3]= a/(-d);

    arr2[1]=1;

    for(int i=2;i<12;i++)
    {
        arr2[i]=find_B(i);
    }

    div();
    int i;
    for(i=1;i<=10;i++)
    {
        if(fabs(DIV[i]-DIV[i+1]) > 0.0001 && DIV[i+1])
        {
            cout<<endl;
            cout<<i<<"\t "<<DIV[i]<<endl;
        }
        else
            break;
    }
    cout << "\n\nRoot is: ";
    cout << fixed << setprecision(6)<<DIV[i]<<endl;
    return 0;

}