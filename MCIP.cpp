#include "C:\VisoGor\TestMyMath\MCIP.h"

MCIP::MCIP(int n,int m,double hh,double epselon,SystemOfEquations*f)
{
    N=n;
    M=m;
    h=hh;
    eps=epselon;
    func=f;
    gm1=(-8.0)*pow(sin(M_PI*h/2),2)/pow(h,2);
    gm2=(-8.0)*pow(cos(M_PI*h/2),2)/pow(h,2);
    psi=gm1/gm2;
    rou=(1-psi)/(1+psi);
    tauN=(double)2/(gm1+gm2);
    web_X=new Vector(N,0.);
    web_Y=new Vector(M,0.);
    ExactSol=new Matrix(N,M,h);
    U0=new Matrix_Spectrum(N,M,h,gm1,gm2);
    UN=new Matrix_Spectrum(N,M,h,gm1,gm2);
    RN=new Matrix(N,M,h);
    W=new Matrix(N,M,h);

    for(int i=0;i<N;i++)
        web_X->SetElement(i,(double)i/(N-1));
    for(int i=0;i<M;i++)
        web_Y->SetElement(i,(double)i/(M-1));
    nPractic=0;
}
MCIP::MCIP(int n,int m,double hh,SystemOfEquations*f)
{
    N=n;
    M=m;
    h=hh;
    eps=0.001;
    func=f;
    gm1=(-8.0)*pow(sin(M_PI*h/2),2)/pow(h,2);
    gm2=(-8.0)*pow(cos(M_PI*h/2),2)/pow(h,2);
    psi=gm1/gm2;
    rou=(1-psi)/(1+psi);
    tauN=(double)2/(gm1+gm2);
    web_X=new Vector(N,0.);
    web_Y=new Vector(M,0.);
    ExactSol=new Matrix(N,M,h);
    U0=new Matrix_Spectrum(N,M,h,gm1,gm2);
    UN=new Matrix_Spectrum(N,M,h,gm1,gm2);
    RN=new Matrix(N,M,h);
    W=new Matrix(N,M,h);

    for(int i=0;i<N;i++)
        web_X->SetElement(i,(double)i/(N-1));
    for(int i=0;i<M;i++)
        web_Y->SetElement(i,(double)i/(M-1));
    nPractic=0;
}
MCIP::MCIP(int n,int m,SystemOfEquations*f)
{
    N=n;
    M=m;
    h=(double)1/(N-1);
    eps=0.001;
    func=f;
    gm1=(-8.0)*pow(sin(M_PI*h/2),2)/pow(h,2);
    gm2=(-8.0)*pow(cos(M_PI*h/2),2)/pow(h,2);
    psi=gm1/gm2;
    rou=(1-psi)/(1+psi);
    tauN=(double)2/(gm1+gm2);
    web_X=new Vector(N,0.);
    web_Y=new Vector(M,0.);
    ExactSol=new Matrix(N,M,h);
    U0=new Matrix_Spectrum(N,M,h,gm1,gm2);
    UN=new Matrix_Spectrum(N,M,h,gm1,gm2);
    RN=new Matrix(N,M,h);
    W=new Matrix(N,M,h);

    for(int i=0;i<N;i++)
        web_X->SetElement(i,(double)i/(N-1));
    for(int i=0;i<M;i++)
        web_Y->SetElement(i,(double)i/(M-1));
    nPractic=0;
}
///ф-ия вычисления невязки
void MCIP::CalculationResidual()
{
    /*for(int i=1;i<N-1;i++)
        for(int j=1;j<M-1;j++)
            RN->SetElement(i,j,func->Operator(UN,i*N+j)-func->Operator(ExactSol,i*N+j));*/
}
///ф-ия вычисления всей задачи
void MCIP::SolutionEquation()
{
    double a,b,c,**temp;
    int i,j;
    temp=new double*[N];
    for(int i=0;i<N;i++)
        temp[i]=new double[M];
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
        {
            a=web_X->GetElement(i);
            b=web_Y->GetElement(j);
            U0->SetElement(i,j,func->FunctionOfXY(a,b));
            temp[i][j]=U0->GetElement(i,j);
            c=U0->GetElement(i,j);
            ExactSol->SetElement(i,j,c);
        }

    for(i=1;i<N-1;i++)
        for(j=1;j<M-1;j++)
            U0->SetElement(i,j,0);

    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            temp[i][j]=(U0->GetElement(i,j))-temp[i][j];
    Matrix T;
    NormW0=T.Norm(temp,N,M,h);
    for(int i=0;i<M;i++)
        delete temp[i];
    delete []temp;
    temp=NULL;

    ///находим нулевую невязку
    CalculationResidual();
    N=RN->Norm();
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            UN->SetElement(i,j,0);
    while(N>=eps)
    {
        nPractic++;
        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
            {
                c=(U0->GetElement(i,j))-tauN*(RN->GetElement(i,j));
                UN->SetElement(i,j,c);
            }

        CalculationResidual();

        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
            {
                c=UN->GetElement(i,j);
                U0->SetElement(i,j,c);
            }
        N=RN->Norm();
    }
    NormWN=W->Norm();
    double eps1=NormWN/NormW0;
    nTheoretic=log(1/eps1)/log(1/rou);
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            a=U0->GetElement(i,j);
            b=ExactSol->GetElement(i,j);
            W->SetElement(i,j,a-b);
        }
    }
}

void MCIP::PrintOfDisplay(bool exact,bool approximate,bool evaluation,bool error)
{
    ///точное решение
    if(exact==1)
        cout<<"Matrix U*\n"<<ExactSol<<endl;
    ///приближенное значение
    if(approximate==1)
        cout<<"Matrix U\n"<<UN<<endl;
    ///погрешность вычисления
    if(evaluation==1)
        cout<<"Matrix W\n"<<W<<endl;
    ///Вывод nt(теор) np(пратик)
    if(error==1)
    {
        //cout<<"NormW0 = "<<NormW0<<endl;
        //cout<<"NormWN = "<<NormWN<<endl;
        cout<<"nTheoretic = "<<nTheoretic<<endl;
        cout<<"nPractic = "<<nPractic<<endl;
    }
    return;
}
bool MCIP::PrintOfFile(bool exact,bool approximate,bool evaluation,bool error,string str)
{
    ///точное решение
    if(exact==1)
        cout<<"Matrix U*\n"<<ExactSol<<endl;
    ///приближенное значение
    if(approximate==1)
        cout<<"Matrix U\n"<<UN<<endl;
    ///погрешность вычисления
    if(evaluation==1)
        cout<<"Matrix W\n"<<W<<endl;
    ///Вывод nt(теор) np(пратик)
    if(error==1)
    {
        //cout<<"NormW0 = "<<NormW0<<endl;
        //cout<<"NormWN = "<<NormWN<<endl;
        cout<<"nTheoretic = "<<nTheoretic<<endl;
        cout<<"nPractic = "<<nPractic<<endl;
    }
    return 0;
}
MCIP::~MCIP()
{
    delete[] web_X;
        web_X=NULL;
    delete[] web_Y;
        web_Y=NULL;
    delete[] U0;
        U0=NULL;
    delete[] UN;
        UN=NULL;
    delete[] RN;
        RN=NULL;
    delete[] W;
        W=NULL;
    delete[] ExactSol;
        ExactSol=NULL;
}
