
//#include"MathComponents.h"
#ifndef MMR_H_INCLUDED
#define MMR_H_INCLUDED

#include "stdafx.h"
#include"IterMethods.h"
#include"matrix.h"
#include"vector.h"
class MMR:public IterMethods
{
    private:
        Vector *web_X,*web_Y,*web_Z,*X0,*XN,*ExSol,*rN,*ArN;
        Matrix*A;
        Matrix*U0,*UN,*RN,*rightPart;
        int N,M,Dim;
        long long int nPractic;
        double CalculationIterationParametr();
        void CalculationResidual();
        SystemOfEquations*funcExactSol;
    public:
        MMR(SystemOfEquations*f,int space,double eps);
        double ReturnCalculationParametr(){return tauN;}
        virtual~MMR();
        void SolutionEquation();
        virtual Solution*Solve();
};

#endif // MMR_H_INCLUDED
