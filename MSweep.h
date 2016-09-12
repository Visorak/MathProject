#ifndef MSWEEP_H_INCLUDED
#define MSWEEP_H_INCLUDED
#include"GaussMethod.h"

class SweepMethod:public GaussMethod
{
    public:
        SweepMethod(SystemOfEquations*f);
        virtual Solution*Solve();
        Solution*Solve(int a,int b);
        Solution*SolveWithBC1A(double a,double al1,double al2,double gm1,double b,double bt1,double bt2,double gm2);
        Solution*SolveWithBC2A(double a,double al1,double al2,double gm1,double b,double bt1,double bt2,double gm2);
        virtual~SweepMethod(){};
};

class MSweep
{
public:
	MSweep();
	~MSweep();
};

#endif // MSWEEP_H_INCLUDED
