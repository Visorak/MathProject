#ifndef METHODRELAXATION_H_INCLUDED
#define METHODRELAXATION_H_INCLUDED
#include"ZeidelMethod.h"

class MethodRelaxation:public ZeidelMethod
{
    private:
        bool omega;
    protected:
        virtual Vector*SolutionEquation();
    public:
        MethodRelaxation(SystemOfEquations*a,double eps,bool om);
        virtual~MethodRelaxation(){};
        //virtual Solution*Solve(Vector*x);
        virtual Solution*Solve();
        void PrintOfDisplay(float om,double N,int iter,Vector&x);

};

#endif // METHODRELAXATION_H_INCLUDED
