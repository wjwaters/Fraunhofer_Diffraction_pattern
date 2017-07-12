#include <iostream>
#include <stdio.h>
#include <gsl_sf_bessel.h>
#include <gsl_mode.h>
#include <gsl_precision.h>
#include <gsl_sf_result.h>
#include <gsl_types.h>
#include<fstream>
#include<gsl_complex.h>
#include<gsl_complex_math.h>
#include<math.h>
#include <complex.h>
#include <tgmath.h>
#include<complex>
#include<cmath>
#include<gsl_integration.h>
#include <stdlib.h>
#include <limits>

//****** (Real{int_{y}int_{x} exp^{i*(x*x0+y*y0} dxdy})^2 ********//

using namespace std;
struct func_params {double x0;double w;long double k;};
double func(double x, void *p)
{
    struct func_params * fp = (struct func_params*)p;
    return exp(-(x*x)/(fp->w*fp->w))*cos(fp->k*fp->x0*x);
}
int main(void)
{
double i;
ofstream fileOut( "E:\\Plot_data\\gauss_ap.txt" ); // Save data to .txt file

for(i=-1;i<=1;i=i+0.01)
{
    double x0=i;//X0 is the (x) co-ordinates on the detector.
    double w=1;
    double k=10;
    double inf = numeric_limits<double>::infinity();
    //Int limits
    double low = 0;             //aperture height (assuming centre at (0,0))
    double upp = 10000;
    //error
    double epsabs = 1e-9;
    double epsrel = 1e-9;
    gsl_integration_workspace *work = gsl_integration_workspace_alloc (100000);
    gsl_function F1;
    F1.function = &func;
    struct func_params params = {x0, w, k};
    F1.params = &params;
    size_t limit=100000;
    double result, error;
    // Perform integration
    gsl_integration_qag(&F1, low, upp, epsabs, epsrel, limit,5, work, &result, &error);
    double R = result;
    double intensity=R*R;
    cout<<"  integral  = "<<intensity;
    //Store co-ordinates in form:  X0 YO  R*R
    fileOut <<dec<<x0<<"  " << intensity << endl;
}
fileOut.close();
}
