#include"SystemOfEquations.h"
#include<windows.h>
#include <iostream>
#include "Matrix.h"
using namespace std;

SystemOfEquations::SystemOfEquations(double (*eq)(double),int n,double h)
{
    marker=0;
    dimension=1;
    FunctionOfX=eq;
    FunctionOfXY=NULL;
    FunctionOfXYZ=NULL;
    N=n;
    this->h=h;
}

SystemOfEquations::SystemOfEquations(Matrix*A)
{
    //cout<<"oneee:"<<A<<endl;
    marker=1;
    dimension=2;
    FunctionOfXYZ=NULL;
    FunctionOfXY=NULL;
    FunctionOfX=NULL;

    F=new Matrix(*A);

    /*cout<<"oneee?:"<<F<<endl;
    system("pause");*/

    A->CountElements(N,M);
    BC=new Matrix(N,M);


    /*Vector*web_X=new Vector(N,0.);
    Vector*web_Y=new Vector(M,0.);
    cout<<"Hel113"<<endl;
    for(int i=0;i<N;i++)
            web_X->SetElement(i,(double)i/(N-1));
    for(int i=0;i<M;i++)
            web_Y->SetElement(i,(double)i/(M-1));

    double a,b,c;
    for(int i=0;i<N;i++)
    {
        a=web_X->GetElement(i);
        for(int j=0;j<M;j++)
        {
            b=web_Y->GetElement(j);
            c=funcExactSol->FunctionOfXY(a,b);
            ExactSol->SetElement(i,j,c);
        }
    }*/
}
SystemOfEquations::SystemOfEquations(Matrix*A,Matrix*bc)
{
    marker=1;
    dimension=2;
    FunctionOfXYZ=NULL;
    FunctionOfXY=NULL;
    FunctionOfX=NULL;
    F=new Matrix(*A);
    A->CountElements(N,M);
    BC=new Matrix(*bc);
}
void SystemOfEquations::RightPart(Matrix*A)
{
    /*cout<<"one:"<<A<<endl;
    cout<<"one?:"<<F<<endl;
    system("pause");*/
    *A=*F;
    A->H(F->H());
    /*cout<<"two:"<<A<<endl;
    system("pause");*/
    return;
}
void SystemOfEquations::BoundaryConditions(Matrix*bc)
{
    *bc=*BC;
    return;
}
SystemOfEquations::SystemOfEquations(double (*eq)(double,double),int n,int m,double h)
{
    marker=0;
    dimension=2;
    FunctionOfXYZ=NULL;
    FunctionOfXY=eq;
    FunctionOfX=NULL;
    N=n;M=m;
    this->h=h;
}
SystemOfEquations::SystemOfEquations(double (*eq)(double,double,double),int n,int m,int l,double h)
{
    dimension=3;
    FunctionOfXYZ=eq;
    FunctionOfXY=NULL;
    FunctionOfX=NULL;
    N=n;M=m;L=l;
    this->h=h;
}
/*Function::Function(double (*eq)(double,double))
{
    dimension=2;
    FunctionOfXYZ=NULL;
    FunctionOfXY=eq;
    FunctionOfX=NULL;
}
Function::Function(double (*eq)(double))
{
    dimension=1;
    FunctionOfX=eq;
    FunctionOfXY=NULL;
    FunctionOfXYZ=NULL;
}*/
