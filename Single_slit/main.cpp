#include <iostream>
#include<fstream>
#include<stdio.h>
//#include<gsl_complex_math.h>
//#include<gsl_complex.h>
#include<math.h>
//#include<gsl_integration.h>
//#include"dcomplex.h"
#include <stdio.h>
#include <complex.h>
#include <tgmath.h>
#include<complex>
#include<cmath>
#include<math.h>
#include<gsl_complex_math.h>
#include<gsl_complex.h>

//typedef complex<double> dcomplex;

using namespace std;

complex<double> func(double x1,double x0)
{
    complex<double> J=x0*I;
    complex<double> X =exp(J*x1);
    return X;
}

int main(void)
{

    int i;        //n is for subintervals and i is for loop


    double a=-0.5;
    double b=0.5;
    int n=100;

    double x[n+1];
    complex<double> y[n+1];
    double h=(b-a)/n;  //get the width of the subintervals

    ofstream fileOut( "E:\\Python\\plot_data\\sing_slit.txt" );

    for (double j=-30;j<=30;j=j+0.1)
    {
    complex<double> sum=0;
         for (i=0;i<=n;i++)
         {
            x[i]=a+i*h;            //and store them in arrays
            y[i]=func(x[i],j);
         }
         for (i=1;i<n;i++)            //loop to evaluate h*(y1+...+yn-1)
         {
            sum=sum+h*y[i];
         }
    double X=real(h/2.0*(y[0]+y[n])+sum);
    double Y=X*X;
    fileOut <<dec<< j << "  " << Y << endl;
    }

fileOut.close();
}
