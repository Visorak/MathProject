#include "C:\VisoGor\TestMyMath\ConjugateGradients.h"
/*template <typename Result>
ConjugateGradients<Result>::ConjugateGradients(Function*f,double eps):VariatMethods<Result>(eps)
{
    func=f;
    func->InputMatrix().CountElements(N,M);
    h=func->InputMatrix().H();
    web_X=new Vector(N,0.);
    web_Y=new Vector(M,0.);
    U0=new Matrix(func->InputMatrix());
    ExactSol=new Matrix(N,M,h);
    UN=new Matrix(N,M,h);
    RN=new Matrix(N,M,h);
    RNprev=new Matrix(N,M,h);
    W=new Matrix(N,M,h);
    ArN=new Matrix(N,M,h);
    ArNprev=new Matrix(N,M,h);
    alphaN=1;

    for(int i=0;i<N;i++)
        web_X->SetElement(i,(double)i/(N-1));
    for(int i=0;i<M;i++)
        web_Y->SetElement(i,(double)i/(M-1));
    nPractic=0;
}
template <typename Result>
ConjugateGradients::ConjugateGradients(Function*f):VariatMethods(0.001)
{
    func=f;
    func->InputMatrix().CountElements(N,M);
    h=func->InputMatrix().H();
    ///h=(double)1/(N-1);
    web_X=new Vector(N,0.);
    web_Y=new Vector(M,0.);
    U0=new Matrix(N,M,h);
    ExactSol=new Matrix(N,M,h);
    UN=new Matrix(N,M,h);
    RN=new Matrix(N,M,h);
    RNprev=new Matrix(N,M,h);
    W=new Matrix(N,M,h);
    ArN=new Matrix(N,M,h);
    ArNprev=new Matrix(N,M,h);
    alphaN=1;

    for(int i=0;i<N;i++)
        web_X->SetElement(i,(double)i/(N-1));
    for(int i=0;i<M;i++)
        web_Y->SetElement(i,(double)i/(M-1));
    nPractic=0;
}

///ф-ия вычисления невязки
void ConjugateGradients::CalculationResidual()
{
    double c;
    RNprev=RN;
    for(int i=1;i<N-1;i++)
        for(int j=1;j<M-1;j++)
        {
            c=func->Operator(UN,i,j,h)-func->Operator(ExactSol,i,j,h);
            RN->SetElement(i,j,c);
        }
}
///ф-ия вычисления тау
double ConjugateGradients::CalculationTau()
{
    ArNprev=ArN;
    for(int i=1;i<N-1;i++)
        for(int j=1;j<M-1;j++)
            ArN->SetElement(i,j,func->Operator(RN,i,j,h));
    double a,b;
    Matrix&t=*ArN;
    a=t%RN;
    b=t%ArN;
    //t=NULL;
    tauN=a/b;
    return tauN;
}
double ConjugateGradients::CalculationAlpha()
{
    alpha0=alphaN;
    double a,b;
    //Matrix&t=*RN;
    a=*RN%*RN;//a=t%RN;
    b=*ArNprev%*RNprev;
    //t=NULL;
    tauN=a/b;
    alphaN=(1-(1/alpha0)*(tauN/tau0)*(a/b));
    return alphaN;
}
///ф-ия вычисления всей задачи
void ConjugateGradients::SolutionEquation()
{
    int i,j;
    double a,b,c,norm;

    for(int i=0;i<N;i++)
    {
        a=web_X->GetElement(i);
        for(int j=0;j<M;j++)
        {
            b=web_Y->GetElement(j);
            c=func->FunctionOfXY(a,b);
            U0->SetElement(i,j,c);
            RN->SetElement(i,j,c);
            ExactSol->SetElement(i,j,c);
        }
    }
    ///находим нулевую невязку
    CalculationResidual();
    norm=RN->Norm();

    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            UN->SetElement(i,j,0);
    while(norm>=epsilon)
    {
        nPractic++;
        CalculationTau();
        CalculationAlpha();
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
        norm=RN->Norm();
    }
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

void ConjugateGradients::PrintOfDisplay(bool exact,bool approximate,bool evaluation,bool error)
{
    ///точное решение
    if(exact==1)
        cout<<"Matrix U*\n"<<ExactSol<<endl;
    ///приближенное значение
    if(approximate==1)
        cout<<"Matrix U\n"<<U0<<endl;
    ///погрешность вычисления
    if(evaluation==1)
        cout<<"Matrix W\n"<<W<<endl;
    ///Вывод практической оценки
    if(error==1)
        cout<<"nPractic = "<<nPractic<<endl;
}
bool ConjugateGradients::PrintOfFile(bool exact,bool approximate,bool evaluation,bool error,string str)
{
    ///точное решение
    if(exact==1)
        cout<<"Matrix U*\n"<<ExactSol<<endl;
    ///приближенное значение
    if(approximate==1)
        cout<<"Matrix U\n"<<U0<<endl;
    ///погрешность вычисления
    if(evaluation==1)
        cout<<"Matrix W\n"<<W<<endl;
    ///Вывод практической оценки
    if(error==1)
        cout<<"nPractic = "<<nPractic<<endl;
}
ConjugateGradients::~ConjugateGradients()
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
*/
