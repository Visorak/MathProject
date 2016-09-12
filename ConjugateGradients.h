#include "C:\VisoGor\MyMath.h"
#include"Function.h"
#ifndef CONJUGATEGRADIENTS_H_INCLUDED
#define CONJUGATEGRADIENTS_H_INCLUDED
#include"VariatMethods.h"

class ConjugateGradients:public VariatMethods
{
    private:
        double alphaN;
        Vector *web_X,*web_Y;
        Matrix*U0,*ExactSol,*UN,*RN,*RNprev,*W,*ArN,*ArNprev;
        double h;
        int N,M,nPractic;
        double CalculationTau();
        void CalculationResidual();
        double CalculationAlpha();
        Function*func;
    public:
        ConjugateGradients(Function*f,double eps);
        ConjugateGradients(Function*f);
        virtual~ConjugateGradients();
        void SolutionEquation();
};


#endif // CONJUGATEGRADIENTS_H_INCLUDED
