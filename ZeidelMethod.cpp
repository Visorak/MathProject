#include"ZeidelMethod.h"

ZeidelMethod::ZeidelMethod(SystemOfEquations*f,double eps):IterMethods(eps)
{
    //epsilon=eps;
    int n,m;
    A=new Matrix(f->InputMatrix());
    A->CountElements(n,m);
    if(n!=m)
    {
        cout<<"Error! Matrix is not square!\a"<<endl;
        exit(0);
    }
    X=new Vector(n,0.);
    Xn=new Vector(*X);
    F=new Vector(f->Result());

}

ZeidelMethod::~ZeidelMethod()
{
    delete A;
    delete F;
    delete X;
    delete Xn;
}

Solution*ZeidelMethod::Solve()
{
    return (new Solution(SolutionEquation()));
}

Vector*ZeidelMethod::SolutionEquation()
{
    double N=1;
    if(!DominateDiagMatrix())
    {
        cout<<"Error! No diagonal dominance!"<<endl;
        exit(0);
    }

    while(N>this->epsilon)
    {
        this->countIteration++;
        /*cout<<"fghjkl "<<N<<endl;
        system("PAUSE");*/
        Zeidel();
        N=X->Norm(*X-*Xn);
        *Xn=*X;
    }
    return X;
}

void ZeidelMethod::Zeidel()
{
    double a,b,c;
    int n=F->CountElements();
    for(int i=0;i<n;i++)
    {
        a=F->GetElement(i);
        X->SetElement(i,a);
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                a=X->GetElement(i);
                b=A->GetElement(i,j);
                c=X->GetElement(j);
                X->SetElement(i,a-b*c);
            }
        }
        a=X->GetElement(i);
        b=A->GetElement(i,i);
        X->SetElement(i,a/b);
    }
}

bool ZeidelMethod::DominateDiagMatrix()
{
    int k=0,n=F->CountElements();
    for(int i=0;i<n;i++)
    {
        double s=0.0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
                s+=fabs(A->GetElement(i,j));
        }
        if(fabs(A->GetElement(i,i))<s)
            return false;
        if(fabs(A->GetElement(i,i))==s)
            k++;
    }
    if(k==n)
        return false;
    double Max=A->GetElement(0,0);
    for(int j=0;j<n;j++)
    {
        for(int i=j;i<n;i++)
            if(A->GetElement(i,j)>Max)
            {
                A->MoveString(i,j);
                F->MoveElement(i,j);
                Max=A->GetElement(i,j);
            }
    }
    return true;
}
