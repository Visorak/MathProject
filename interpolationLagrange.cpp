#include"interpolationLagrange.h"

InterpolationLagrange::InterpolationLagrange(double (*fX)(double),int a,int b):Interpolation(fX,a,b)
{
    Rl=new Vector(N,0.);
    Rn=new Vector(N,0.);
}
InterpolationLagrange::InterpolationLagrange(double (*fX)(double),int a,double h,int n):Interpolation(fX,a,h,n)
{
    Rl=new Vector(N,0.);
    Rn=new Vector(N,0.);
}
InterpolationLagrange::InterpolationLagrange(double (*fX)(double),Vector*s,int n):Interpolation(fX,s,n)
{
    Rl=new Vector(N,0.);
    Rn=new Vector(N,0.);
}
InterpolationLagrange::~InterpolationLagrange()
{
    delete Rl;
    delete Rn;
    level=NULL;
}
double InterpolationLagrange::RnX(double X)
{
    double a=maxDiff;
    for(int i=0,k=1;i<=N;i=(i/10+1)*10,k++)
    {
        a*=(X-x->GetElement(i))/k;
    }
    return a;//(F4x(x)*(x-x0)*(x-x1)*(x-x2)*(x-x3))/(1*2*3*4);
}

double InterpolationLagrange::Polynom(double X)
{
    double a,b,c=0;
    for(int i=0;i<=N;i=(i/10+1)*10)
    {
        a=y->GetElement(i);b=1;
        for(int j=0;j<=N;j=(j/10+1)*10)
        {
            if(i!=j)
            {
                b*=((X-x->GetElement(j))/(x->GetElement(i)-x->GetElement(j)));
            }
        }
        c+=a*b;
    }
    return c;
}
Vector&InterpolationLagrange::SolveInterpolant(int l)
{
    level=l;
    double MaxDiff,temp;

    MaxDiff=fabs(DerivativePoint(y,0,l+1,0.1));
    //*/MaxDiff=fabs(F6x(x[0]));
    for(int i=1;i<N;i++)
    {
        temp=fabs(DerivativePoint(y,i,l+1,0.1));
        //*/temp=fabs(F6x(x[i]));
        if(temp>MaxDiff)
            MaxDiff=fabs(temp);
    }
    for(int i=0;i<N;i++)
    {
        IntPol->SetElement(i,Polynom(x->GetElement(i)));
        Rl->SetElement(i,fabs(y->GetElement(i))-IntPol->GetElement(i));
        Rn[i]=fabs(RnX(x->GetElement(i)));

        //printf("x[%d] = %6.3lf y[%d] = %6.3lf L3(x) = %6.3lf R3 = %lf Rn = %lf\n",i,x[i],i,y[i],L[i],R[i],Rn[i]);
    }
    cout<<"MaxDiff = "<<MaxDiff<<endl;
    return *IntPol;
}
void InterpolationLagrange::PrintOfDisplay(bool anchorPoints,bool points,bool function,bool interpolation,bool remainingMember,bool remainingMemberN)
{
    if(anchorPoints==true)
        for(int i=0;i<N;i=(i/10+1)*10)
        {
            cout<<"x["<<i/10<<"]="<<x->GetElement(i)<<endl;
        }

    for(int i=0;i<N;i++)
    {
        if(points==true)
            printf("x[%d] = %6.3lf ",i,x->GetElement(i));
        if(function==true)
            printf("y[%d] = %6.3lf ",i,y->GetElement(i));
        if(interpolation==true)
            printf("L[%d] = %6.3lf ",i,IntPol->GetElement(i));
        if(remainingMember==true)
            printf("R%d[%d] = %6.3lf ",level,i,Rl->GetElement(i));
        if(remainingMemberN==true)
            printf("Rn[%d] = %6.3lf ",i,Rn->GetElement(i));
        if(points==true||function==true||interpolation==true||remainingMember==true||remainingMemberN==true)
            cout<<endl;
    }
    return;
}


interpolationLagrange::interpolationLagrange()
{
}


interpolationLagrange::~interpolationLagrange()
{
}
