#include <stdio.h>
#include <math.h>

#define ERR .0001

int bisecITER = 0;
int falPosITER = 0;

//main function
double f(double x)
{
    return x*x*x - 2*x - 5;
}

//differentiate the function
double fd(double x)                              
{
    return 3*x*x - 2;
}

double fdd(double x)
{
    return 3*x;
}

//Formatted print function
void print(int ITER, double a, double b, double c)
{
    printf("      %2d     |  %lf  |  %lf  |  %lf  |  %9lf  \n", ITER, a, b, c, f(c));
}

//bisection method function
void bisec(double a, double b)
{
    bisecITER = 0;
    if(f(a) * f(b) >= 0)
    {
        printf("The assumed values are wrong...\nTry new values...\n\n\ta = ");
        scanf("%lf", &a);
        printf("\tb = ");
        scanf("%lf", &b);
        printf("\n\n");
        return;
    }
    else
    {
        ++bisecITER;
        double c = a;
        printf("==================\n Bisection Method \n==================\n");
        printf("\n   Iter. No. |      a     |      b     |      x     |      f(x)     \n");
        printf("  ------------------------------------------------------------------\n");

        print(bisecITER, a, b, c);
        while (fabs(b - a) >= ERR)
        {
            ++bisecITER;
            c = (a+b)/2;
            if (f(c) == 0.0){
                print(bisecITER, a, b, c);
                break;
            }
            else if (f(c)*f(a) < 0)
            {
                b = c;
                print(bisecITER, a, b, c);
            }
            else if (f(c) * f(a) > 0)
            {
                a = c;
                print(bisecITER, a, b, c);
            }
            else
            {
                printf("This is a RIDICULUS function\n");
                return;
            }
        }
    printf("\n\nThe value of root is : %lf\n", c);
    printf("Absolute error       : %lf\n", ERR);
    printf("Number of Iterations : %d\n\n", bisecITER);
    }
}

void falPos(double a, double b)
{
    double c, temp, error;
    falPosITER = 0;

    if(f(a) * f(b) > 0)
    {
        printf("The assumed values are wrong...\nTry new values...\n\n\ta = ");
        scanf("%lf", &a);
        printf("\tb = ");
        scanf("%lf", &b);
        printf("\n\n");
        return;
    }
    else
    {
        printf("\n\n=======================\n False Position Method \n=======================\n");
        printf("\n   Iter. No. |      a     |      b     |      x     |      f(x)     \n");
        printf("  ------------------------------------------------------------------\n");

        if(f(a) == 0 || f(b) == 0)
        {
                printf("Root:\t%f\n", f(a) == 0 ? a:b);
                return;
        }

        do
        {
            temp = c;
            c = (((a * f(b)) - (b * f(a))) / (f(b) - f(a)));
            print(++falPosITER, a, b, c);
            if(f(c) == 0)
            {
                  break;
            }
            else if(f(a) * f(c) < 0)
            {
                  b = c;
            }
            else 
            {
                  a = c;
            }
            error = fabs(c - temp);
      } while(error > ERR);

    printf("\n\nThe value of root is : %lf\n", c);
    printf("Absolute error       : %lf\n", ERR);
    printf("Number of Iterations : %d\n\n", falPosITER);
    }
}

void compare()
{
    printf("\nNumber of iterations in Bisection method: %d\nNumber of iterations in False Position method: %d\n", bisecITER, falPosITER);

    if(bisecITER == 0 || falPosITER == 0)
    {
        printf("\nBoth or one of the methods are not run before...\nTo calculate the number of iterations, FIRST, run the both methods and then compare.\n\n");
    }
    else if(falPosITER < bisecITER)
    {
        printf("So, False Position Method is efficient.\n\n");
    }
    else if(bisecITER < falPosITER)
    {
        printf("So, Bisection method is efficient.\n\n");
    }
    else
    {
        printf("Both method has the same iterations.\n\n");
    }
}


int main()
{
    double a = 2.0, b = 3.0;

    while(1)
    {
        printf("Enter your choice:\n\t1. Bisection Method\n\t2. False Position Method\n\t3. Comparison\n\t4. Exit\n\n");
        int c;
        scanf("%d", &c);
        switch(c)
        {
            case 1: bisec(a, b); break;
            case 2: falPos(a, b); break;
            case 3: compare(); break;
            case 4: return 0;
            default : printf("\nI N V A L I D   C H O I C E. . .\nP R O G R A M   T E R M I N A T I N G...\n");
                      return 0;
        }
    }

    return 0;
}
