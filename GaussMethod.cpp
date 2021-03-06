#include"GaussMethod.h"
#include<stdio.h>

GaussMethod::GaussMethod(SystemOfEquations*f):ExactMethods()
{
    int m;
    A=new Matrix(f->InputMatrix());
    F=new Vector(f->Result());
    A->CountElements(N,m);
    if(N!=m)
    {
        printf("Error gauss method!\a");
        return;
    }
    X=new Vector(f->Solution());
}
Solution*GaussMethod::Solve()
{
    int i,j;
    double coef;
    ///1 ����
    Matrix*A1=new Matrix(*A);
    Vector*F1=new Vector(*F);
    for(i=0;i<N-1;i++)
    {
        for(int k=i+1;k<N;k++)
        {
            coef=(-1)*A->GetElement(k,i)/A->GetElement(i,i);
            for(j=i;j<N;j++)
                A1->SetElement(k,j,(A->GetElement(k,j)+A->GetElement(i,j)*coef));
            F1->SetElement(k,(F->GetElement(k)+F->GetElement(i)*coef));
        }
        A=A1;
        F=F1;
    }
    ///2 ����
    double dt=1;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(i==j)
                dt*=A->GetElement(i,j);
    if(dt==0)
    {
        cout<<"Error! System is linearly dependent!"<<endl;
        exit(0);
    }
    double a,b;
    for(i=N-1;i>=0;i--)
    {
        a=F->GetElement(i);
        b=A->GetElement(i,i);
        for(j=0;j<N;j++)
        {
            if(j>i)
                a-=A->GetElement(i,j)*X->GetElement(j);
        }
        if(a==0||b==0)
            X->SetElement(i,0);
        else
            X->SetElement(i,a/b);
    }
    return (new Solution(X));
}
GaussMethod::~GaussMethod()
{
    delete A;
    delete F;
    delete X;
}
