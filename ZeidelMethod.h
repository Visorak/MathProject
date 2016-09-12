#ifndef ZEIDELMETHOD_H_INCLUDED
#define ZEIDELMETHOD_H_INCLUDED
#include"IterMethods.h"

class ZeidelMethod:public IterMethods
{
    protected:
        Matrix*A;
        //long double epsilon;
        Vector*X,*F,*Xn;
        virtual Vector*SolutionEquation();
        void Zeidel();
        bool DominateDiagMatrix();
    public:
        ZeidelMethod(SystemOfEquations*F,double eps);
        virtual Solution*Solve();
        virtual~ZeidelMethod();
};

#endif // ZEIDELMETHOD_H_INCLUDED
