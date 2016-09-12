#include"matrix.h"
#ifndef MATRIX_SPECTRUM_H_INCLUDED
#define MATRIX_SPECTRUM_H_INCLUDED

class Matrix_Spectrum:public Matrix
{
    private:
        double gamma1,gamma2;
    public:
        Matrix_Spectrum(double gm1,double gm2);
        Matrix_Spectrum(int n,int m,double gm1,double gm2);
        Matrix_Spectrum(int n,int m,double hh,double gm1,double gm2);
        Matrix_Spectrum(double**c,int n,int m,double gm1,double gm2);
};


#endif // MATRIX_SPECTRUM_H_INCLUDED
