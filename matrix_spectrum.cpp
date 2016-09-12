#include"matrix_spectrum.h"
Matrix_Spectrum::Matrix_Spectrum(double gm1,double gm2):Matrix()
{
    gamma1=gm1;
    gamma2=gm2;
}
Matrix_Spectrum::Matrix_Spectrum(int n,int m,double gm1,double gm2):Matrix(n,m,0.)
{
    gamma1=gm1;
    gamma2=gm2;
}
Matrix_Spectrum::Matrix_Spectrum(int n,int m,double hh,double gm1,double gm2):Matrix(n,m,hh)
{
    gamma1=gm1;
    gamma2=gm2;
}
Matrix_Spectrum::Matrix_Spectrum(double**c,int n,int m,double gm1,double gm2):Matrix(c,n,m)
{
    gamma1=gm1;
    gamma2=gm2;
}
