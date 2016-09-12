#ifndef GAUSSSELECTMETHOD_H_INCLUDED
#define GAUSSSELECTMETHOD_H_INCLUDED
#include"GaussMethod.h"

class GaussSelectMethod:public GaussMethod
{
    int N;
    Matrix*A;
    Vector*F,*X;
    public:
        int movements;
        GaussSelectMethod(SystemOfEquations*f);
        virtual Solution*Solve();
        virtual~GaussSelectMethod(){};
};
#endif // GAUSSSELECTMETHOD_H_INCLUDED
