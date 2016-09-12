#include "MathComponents.h"
#include "matrix_spectrum.h"
#ifndef MCIP_H_INCLUDED
#define MCIP_H_INCLUDED

class MCIP
{
    private:
        Vector *web_X,*web_Y;
        Matrix*ExactSol,*RN,*W;
        Matrix_Spectrum*U0,*UN;
        double tauN,gm1,gm2,rou,psi,eps,NormW0,NormWN,h;
        int N,M,nPractic,nTheoretic;
        Function*func;
    public:
        MCIP(int n,int m,double hh,double epselon,Function*f);
        MCIP(int n,int m,double hh,Function*f);
        MCIP(int n,int m,Function*f);
        ~MCIP();
        void CalculationResidual();
        void SolutionEquation();
        void PrintOfDisplay(bool exact,bool approximate,bool evaluation,bool error);
        bool PrintOfFile(bool exact,bool approximate,bool evaluation,bool error,string str);
};

#endif // MCIP_H_INCLUDED
