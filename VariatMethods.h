#ifndef VARIATMETHODS_H_INCLUDED
#define VARIATMETHODS_H_INCLUDED
#include"Methods.h"

class VariatMethods:Methods
{
    protected:
        double epsilon,tau0,tauN,alpha0,alphaN;
        long long int countIteration;
    public:
        virtual Solution*Solve()=0;
        VariatMethods(double eps){epsilon=eps;countIteration=0;}
        virtual ~VariatMethods(){};
};


#endif // VARIATMETHODS_H_INCLUDED
