#include <cmath>
#include <math.h>
#include <iostream>

using namespace std;


    static double f(double x1, double x2)
    {
        return (pow(1-x1,2)+5*pow(x2-pow(x1,2),2));
    }

    static double explorX1 (double x1, double x2, double* vecofInc)
    {
        double X1 = x1 + vecofInc[0];
        if (f(X1, x2) <= f(x1, x2))
            x1=X1;
        else
        {
            X1 = x1 - vecofInc[0];
            if (f(X1 ,x2) <= f(x1, x2))
                x1=X1;
        };
        return(x1);
    }

    static double modulInc(double* vecofInc)
    {
        return (sqrt(pow(vecofInc[0], 2) + pow(vecofInc[1],2)));
    }

    static double explorX2 (double x1, double x2, double* vecofInc)
    {
        double X2 = x2 + vecofInc[1];
        if (f(x1, X2) < f(x1, x2))
            x2=X2;
        else
        {
            X2 = x1 - vecofInc[1];
            if (f(x1 ,X2) < f(x1, x2))
                x2=X2;
        };
        return(x2);
    }

    static double sampleSearch(double x1, double x1_, double x2, double x2_)
    {
        return f(2*x1 - x1_, 2*x2 - x2_);
    }

    static double changeInc1 (double vecofInc, double a)
    {
        cout << "Change" << '\n';
        double newVector = vecofInc/a;
        return newVector;
    }

    static double changeInc2(double vecofInc, double a)
    {
        double newVector = vecofInc/a;
        return newVector;
    }


int main()
{
    double x1=1;
    double x2=0;

    cout << "Enter k reduce:";
    double a;
    cin >> a;
    cout <<'\n';

    double ebc=0.01;

    double vecofInc[2] = {0,1};

    while (modulInc(vecofInc) > ebc)
    {
        double X1 = explorX1(x1, x2, vecofInc);
        double X2 = explorX2(x1, x2, vecofInc);
        double tempx1 = x1;
        double tempx2 = x2;
        if ((X1 == x1)&&(X2 == x2))
        {
            vecofInc[0] = changeInc1(vecofInc[0], a);
            vecofInc[1] = changeInc2(vecofInc[1], a);
            cout << "run" << "x1=" << x1 << " " << "x2=" << x2 << '\n';
            continue;
        }
        else if(X1==x1)
            x2=X2;
        else if(X2==x2)
            x1=X1;
        else
            x1=X1;
        x2=X2;
        if (sampleSearch(x1, tempx1, x2, tempx2) >= f(x1, x2))
        {
            cout << "run" << "x1=" << x1 << " " << "x2=" << x2 << '\n';
            continue;
        }
        else
        {
            x1 = 2*x1 - tempx1;
            x2 = 2*x2 - tempx2;
            cout << "run" << "x1=" << x1 << " " << "x2=" << x2 << '\n';
        }

    }
    cout << "x1=" << x1 << " " << "x2=" << x2;

}

