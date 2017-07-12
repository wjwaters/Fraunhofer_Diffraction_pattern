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
//#include<complex>
#include<cmath>
#include<gsl_integration.h>
#include <stdlib.h>
#include<gsl_monte.h>
//#include<gsl_monte_miser.h>
#include<gsl_monte_plain.h>
//#include<gsl_monte_vegas.h>

//FUNCTION BEING INTEGRATED//
//****** (Real{int_{r}int_{a} r*exp^{i*(x0*r*cos(a)+y0*r*sin(a)} dxdy})^2 ********//


//MONTE CARLO INTEGRATION

using namespace std;
//DEFINE FUNCTION TO BE INTEGRATED
struct func_params {double xd;double yd;};
double func(double x[],size_t dim, void *p)
{
    struct func_params * fp = (struct func_params*)p;
    if (dim != 2)
    {
        fprintf(stderr, "error: dim != 2");
    }
    return (1/(2*M_PI))*x[1]*cos(x[1]*fp->xd*cos(x[0])+x[1]*fp->yd*sin(x[0]));
}
int main(void)
{
    double i;
    double j=0;
    ofstream fileOut( "E:\\Plot_data\\circular_ap.txt" ); // Save data to .txt file

    for (i=-20;i<=20;i=i+0.1)
    {
        //for (j=-10;j<=10;j=j+0.1)
        //{
            double x0=i;            //represent co-ordinates on the detector
            double y0=j;
            //1ST INTEGRATION
            gsl_monte_function F;
            struct func_params params = {x0,y0};
            F.f = &func;
            F.dim = 2;
            F.params = &params;
            double ap_rad=0.5;
            double result, error;
            double xl[2]={0,0};                 //lower limits
            double xu[2]={2*M_PI,ap_rad};       //upper limits
            size_t calls = 5000;
            const gsl_rng_type *T;
            gsl_rng *r;
            gsl_rng_env_setup ();
            T = gsl_rng_default;
            r = gsl_rng_alloc (T);
            {
                gsl_monte_plain_state *s = gsl_monte_plain_alloc (2);
                gsl_monte_plain_integrate (&F, xl, xu, 2, calls, r, s, &result, &error);
                gsl_monte_plain_free (s);
            }
            double R=result*result;
            fileOut <<dec<<x0<<"    "<< R << endl;
       // }
    }
fileOut.close();
}





