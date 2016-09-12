#include"MethodRelaxation.h"
/*template <typename Result>
MethodRelaxation<Result>::MethodRelaxation(Function*a,double eps,bool om):ZeidelMethod<Result>(a,eps)
{
    omega=om;
}
template <typename Result>
Result&MethodRelaxation<Result>::Solve(Vector*x)
{
    /*int n,m;
    a->CountElements(m,n);
    if(x->CountElements()!=n)
    {
        cout<<"Error! X is not equal function!\a"<<endl;
        exit(0);
    }*/
    /**X=*x;
    return Solution();
}
Vector&MethodRelaxation::Solve()
{
    return Solution();
}
Vector&MethodRelaxation::Solution()
{
    Vector*Y=new Vector(*X);
    double om=(double)omega;
    om=1.1;
    double omE=om+0.9;

    double N=1,a;
    DominateDiagMatrix();
    int iter=0;

    for(om;om<omE;om=om+0.1)
    {
        while(N>epsilon)
        {
            iter++;
            Zeidel();
            *Y=*X;
            *X=*Xn+(*Y-*Xn)*om;
            N=X->Norm(*X-*Xn);
            *Xn=*X;
        }
        PrintOfDisplay(om,N,iter,*X);
        iter=0;
        N=1;
        *X=0;*Xn=0;
    }

}
void MethodRelaxation::PrintOfDisplay(float om,double N,int iter,Vector&x)
{
    cout<<"Omega="<<om<<": Norma=";
    cout<<N<<"; count iterations is "<<iter<<endl;
    cout<<"X*: "<<x<<endl<<endl;
}*/
