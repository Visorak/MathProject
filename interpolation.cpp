#include"interpolation.h"

Interpolation::Interpolation(double (*fX)(double),int a,int b)
{
    FunctionOfX=fX;
    N=abs(b-a);
    x=new Vector(N,0.);
    A=a;
    B=b;
    H=0.1;
    y=new Vector(N,0.);
    x->SetElement(0,A);
    for(int i=1;i<N;i++)
    {
        x->SetElement(i,x->GetElement(i-1)+H);
    }

    double c;
    for(int i=0;i<N;i++)
    {
        c=x->GetElement(i);
        y->SetElement(i,fX(c));
    }
    IntPol=new Vector(N,0.);
}
Interpolation::Interpolation(double (*fX)(double),int a,double h,int n)
{
    FunctionOfX=fX;
    N=n;
    x=new Vector(N,0.);
    A=a;
    H=h;
    y=new Vector(N,0.);
    x->SetElement(0,A);
    for(int i=1;i<N;i++)
    {
        x->SetElement(i,x->GetElement(i-1)+H);
    }
    double c;
    for(int i=0;i<N;i++)
    {
        c=x->GetElement(i);
        y->SetElement(i,fX(c));
    }
    B=c;
    IntPol=new Vector(N,0.);
}
Interpolation::Interpolation(double (*fX)(double),Vector*s,int n)
{
    if(s->CountElements()!=n)
    {
        cout<<"The segments do not match!\a"<<endl;
        exit(0);
    }
    FunctionOfX=fX;
    N=n;
    H=0.1;
    x=new Vector(N,0.);
    x=s;
    A=s->GetElement(0);
    B=s->GetElement(n-1);
    y=new Vector(N,0.);
    x->SetElement(0,A);
    for(int i=1;i<n;i++)
    {
        x->SetElement(i,x->GetElement(i-1)+H);
    }

    double c;
    for(int i=0;i<n;i++)
    {
        c=x->GetElement(i);
        y->SetElement(i,fX(c));
    }
    IntPol=new Vector(N,0.);
}
Interpolation::~Interpolation()
{
    delete x;
    delete y;
    delete IntPol;
    N=NULL;
    A=NULL;
    B=NULL;
    H=NULL;
}


interpolation::interpolation()
{
}


interpolation::~interpolation()
{
}
