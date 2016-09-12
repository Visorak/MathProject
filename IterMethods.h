//#include"C:\VisoGor\MyMath.h"
#ifndef ITERMETHODS_H_INCLUDED
#define ITERMETHODS_H_INCLUDED
#include"Methods.h"

class IterMethods: public Methods
{
    protected:
        double tauN;
        long double epsilon;
        long long int countIteration;
    public:
        long long int CountIteration(){return countIteration;}
        IterMethods(double eps){epsilon=eps;countIteration=0;}
        virtual Solution*Solve()=0;
        virtual~IterMethods(){};
};

#endif // ITERMETHODS_H_INCLUDED
