#include"MMR.h"

MMR::MMR(SystemOfEquations*f,int space,double eps):IterMethods(eps)
{
    funcExactSol=f;
    funcExactSol->CountElements(N,M);
    Dim=space;
    if(Dim==1)
    {
        A=new Matrix(funcExactSol->InputMatrix());
        X0=new Vector(N,0.);
        XN=new Vector(N,0.);
        ExSol=new Vector(funcExactSol->Result());
        rN=new Vector(N,0.);
        ArN=new Vector(N,0.);
    }
    else if(Dim==2)
    {
        rightPart=new Matrix(N,M);
        //cout<<rightPart<<endl;
        funcExactSol->RightPart(rightPart);
        double h=rightPart->H();
        U0=new Matrix(N,M,h);
        funcExactSol->BoundaryConditions(U0);
        UN=new Matrix(*U0);
        RN=new Matrix(N,M,h);
        /*cout<<"h="<<h<<endl;
        cout<<rightPart<<endl;
        system("PAUSE");*/
    }
    else if(Dim==3)
    {
        web_X=new Vector(N,0.);
        web_Y=new Vector(M,0.);
        web_Z=new Vector(M,0.);

    }
    else
        exit(0);

    nPractic=0;
}
double MMR::CalculationIterationParametr()
{
    double a,b;
    if(Dim==1)
    {
        /*for(int i=1;i<N-1;i++)
            ArN->SetElement(i,func->Operator(RN,i,h));*/
        *ArN=*A*(*rN);
        a=(*ArN) * (*rN);
        b=*ArN**ArN;
    }
    if(Dim==2)
    {
        Matrix*ARN=&(funcExactSol->Operator(RN));
        for(int i = 0; i<N; i++)
            for(int j = 0; j<M; j++)
            {
                a+=RN->GetElement(i,j)*ARN->GetElement(i,j);
                b+=ARN->GetElement(i,j)*ARN->GetElement(i,j);
            }
        delete ARN;
        //a=RN->Skalyar(ARN);
        //b=ARN->Skalyar(ARN);
    }
    tauN=a/b;
    return tauN;
}
void MMR::CalculationResidual()
{
    double a;
    if(Dim==1)
    {
        *rN=*A*(*XN)-*ExSol;
        return;
    }
    if(Dim==2)
    {
        Matrix*temp=&(funcExactSol->Operator(UN));
        for(int i=1;i<N-1;i++)
            for(int j=1;j<M-1;j++)
            {
                a=temp->GetElement(i,j);
                RN->SetElement(i,j,a+rightPart->GetElement(i,j));
            }
        delete temp;
        return;
    }
}
void MMR::SolutionEquation()
{
    int i,j;
    double a,b,c,norm,h;
    if(Dim==1)
    {
        *X0=*ExSol;
        *rN=*ExSol;
    }
    if(Dim==2)
    {
        for(int i=1;i<N-1;i++)
            for(int j=1;j<M-1;j++)
            {
                U0->SetElement(i,j,1);
                UN->SetElement(i,j,1);
            }
        //h=UN->H();
        /*cout<<U0<<endl;
        system("pause");*/
    }
    /*cout<<"start:"<<endl<<U0<<endl;
        system("pause");*/
    ///находим нулевую невязку
    CalculationResidual();
    norm=RN->Norm();
    double norm0=norm;
    while(norm>=epsilon)
    {
        countIteration++;
        //cout<<norm<<endl;
        CalculationIterationParametr();
        if(Dim==1)
        {
            *XN=*X0-(*rN*tauN);
            CalculationResidual();
            *X0=*XN;
            norm=rN->Norm();
        }
        if(Dim==2)
        {

            for(int i=1;i<N-1;i++)
                for(int j=1;j<M-1;j++)
                    UN->SetElement(i,j,U0->GetElement(i,j)-RN->GetElement(i,j)*tauN);
            for(int i=1;i<N-1;i++)
                for(int j=1;j<M-1;j++)
                    U0->SetElement(i,j,UN->GetElement(i,j));
            CalculationResidual();
            norm=RN->Norm()/norm0;
        }
    }
    /*cout<<"finish:"<<endl<<U0<<endl;
        system("pause");*/
    //cout<<norm;
    ///проверка
    /*Matrix*W=new Matrix(11,11,1.0);
    W=&(*(&funcExactSol->Operator(U0))-*ExactSol);*/
    /*cout.precision(7);
    cout<<"Погрешность:\n"<<W<<endl;
    cout.precision(3);*/
    //cout<<" Количество итераций: "<<nPractic<<endl;
    //delete W;
    //U0->Flip('h');
}
Solution*MMR::Solve()
{
    SolutionEquation();
    return (new Solution(UN));
}
MMR::~MMR()
{
    if(Dim==1)
    {
        delete A;
            A=NULL;
        delete X0;
            X0=NULL;
        delete XN;
            XN=NULL;
        delete rN;
            rN=NULL;
        delete ArN;
            ArN=NULL;
        delete ExSol;
            ExSol=NULL;
    }
    if(Dim==2)
    {
        delete U0;
            U0=NULL;
        delete UN;
            UN=NULL;
        delete RN;
            RN=NULL;
        delete rightPart;
            rightPart=NULL;
    }
    funcExactSol=NULL;
}
