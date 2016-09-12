#include"FunctionLaplas.h"

FunctionLaplas::FunctionLaplas(Matrix*a,double (*eq)(double,double),int n,int m):SystemOfEquations(eq,n,m,h)
{
    a->CountElements(n,m);
    h=a->H();
    u=new Matrix(*a);
    N=n;M=m;
}

FunctionLaplas::FunctionLaplas(Matrix*a,double (*eq)(double),int n):SystemOfEquations(eq,n,h)
{
    N=n;
    u=new Matrix(*a);
}
FunctionLaplas::FunctionLaplas(Matrix*a):SystemOfEquations(a)
{
    int n,m;
    a->CountElements(n,m);
    h=a->H();
    u=new Matrix(*a);
    N=n;M=m;
}
FunctionLaplas::FunctionLaplas(Matrix*a,Matrix*bc):SystemOfEquations(a,bc)
{
    int n,m;
    a->CountElements(n,m);
    h=a->H();
    u=new Matrix(*a);
    N=n;M=m;
}
Matrix&FunctionLaplas::InputMatrix()
{
    return *u;
}
FunctionLaplas::FunctionLaplas(double (*eq)(double,double),int n,int m,double h):SystemOfEquations(eq,n,m,h){}
Matrix&FunctionLaplas::Operator(Matrix*u)
{
    //u->CountElements(N,M);

    //cout<<"u"<<u<<endl;
    //cout<<endl<<"UN2: "<<u<<endl;
    double a,B,c,d,e,f,h=u->H();
    Matrix*res=new Matrix(N,M,h);
    //cout<<" h:"<<h<<endl;
    for(int i=1;i<N-1;i++)
        for(int j=1;j<M-1;j++)
        {
            a=u->GetElement(i+1,j);
            //cout<<" a:"<<a;
            B=u->GetElement(i,j);
            //cout<<" B:"<<B;
            c=u->GetElement(i-1,j);
            //cout<<" c:"<<c;
            d=u->GetElement(i,j+1);
            //cout<<" d:"<<d;
            e=u->GetElement(i,j-1);
            //cout<<" e:"<<e;
            f=(a-2*B+c)/pow(h,2)+(d-2*B+e)/pow(h,2);
            //cout<<" f:"<<f;
            res->SetElement(i,j,f);
        }
    //cout<<"res"<<res<<endl;
    return *res;
}
double FunctionLaplas::Operator(double**u,int i,int j,double h)
{
    return (u[i+1][j]-2*u[i][j]+u[i-1][j])/pow(h,2)+(u[i][j+1]-2*u[i][j]+u[i][j-1])/pow(h,2);
}
