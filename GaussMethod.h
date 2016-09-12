//#include"C:\VisoGor\MyMath.h"
#ifndef GAUSSMETHOD_H_INCLUDED
#define GAUSSMETHOD_H_INCLUDED
#include"ExactMethods.h"
#include"SystemOfEquations.h"

class GaussMethod:public ExactMethods
{
    protected:
        int N,dimensions;
        Matrix*A;
        Vector*X,*F;
    public:
        GaussMethod(SystemOfEquations*f);
        virtual Solution*Solve();
        virtual~GaussMethod();
};
#endif // GAUSSMETHOD_H_INCLUDED
