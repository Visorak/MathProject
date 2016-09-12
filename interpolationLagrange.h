#include"C:\VisoGor\MyMath.h"
#ifndef INTERPOLATIONLAGRANGE_H_INCLUDED
#define INTERPOLATIONLAGRANGE_H_INCLUDED
#include"interpolation.h"
class InterpolationLagrange:public Interpolation
{
    private:
        Vector*Rl,*Rn;
        int level,maxDiff;
    public:
        InterpolationLagrange(double (*fX)(double),int a,int b);
        InterpolationLagrange(double (*fX)(double),int a,double h,int n);
        InterpolationLagrange(double (*fX)(double),Vector*s,int n);
        double Polynom(double X);
        double RnX(double X);
        virtual Vector&SolveInterpolant(int l);
        Vector&GetRemainingMember();
        void PrintOfDisplay(bool anchorPoints,bool points,bool function,bool interpolation,bool remainingMember,bool remainingMemberN);
        virtual~InterpolationLagrange();
};

#endif // INTERPOLATIONLAGRANGE_H_INCLUDED

class interpolationLagrange
{
public:
	interpolationLagrange();
	~interpolationLagrange();
};
