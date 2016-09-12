#include"MSweep.h"
SweepMethod::SweepMethod(SystemOfEquations*f):GaussMethod(f)
{
    dimensions=f->Dimension();
    ///проверка, что матрица трёхдиагональная
    if(dimensions==2)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(j>i+1 && i>j+1)
                {
                    if(A->GetElement(i,j)!=0)
                    {
                        cout<<"Error!\a The matrix isn't three-diagonal, the system cannot be solved by this method!"<<endl;
                        exit(0);
                    }
                }

}
Solution*SweepMethod::Solve(int a,int b)
{
    if(a<0 && b>N-1 && a>b-2 || a!=b)
    {
        cout<<a<<" "<<b<<endl;
        cout<<"Error section"<<endl;
        exit(0);
    }
    int i;
    double**At;
    At=new double*[N];
    for(int i=0;i<N;i++)
        At[i]=new double[N];
    A->ConversionInStandart(At);
    *X=*F;

    double*P,*Q;
    double*alpha,*betta,*gamma,*delta;
    P=new double [N+1];
    Q=new double [N+1];
    alpha=new double [N+1];
    betta=new double [N+1];
    gamma=new double [N+1];
    delta=new double [N+1];

///расчёт прогоночных коэффициентов
    alpha[a]=0;
    betta[a]=-At[a][a];
    gamma[a]=At[a][a+1];
    delta[a]=F->GetElement(a);
    alpha[b]=At[b][b-1];
    betta[b]=-At[b][b];
    gamma[b]=0;
    delta[b]=F->GetElement(b);
    for(i=a+1;i<b;i++)
    {
        alpha[i]=At[i][i-1];
        betta[i]=-At[i][i];
        gamma[i]=At[i][i+1];
        delta[i]=F->GetElement(i);
    }
///вычисление значений многочлена P и Q с помощью прогоночных коэффициентов
    P[a]=gamma[a]/betta[a];
    Q[a]=-1.0*(delta[a]/betta[a]);
    for(i=a+1;i<b;i++)
    {
        P[i]=gamma[i]/(betta[i]-alpha[i]*P[i-1]);
        Q[i]=((alpha[i]*Q[i-1])-delta[i])/(betta[i]-(alpha[i]*P[i-1]));
    }
///получение ветора Х
    X->SetElement(b,(alpha[b]*Q[b-1]-delta[b])/(betta[b]-alpha[b]*P[b-1]));
    for(i=b-1;i>=a;i--)
        X->SetElement(i,P[i]*X->GetElement(i+1)+Q[i]);

    delete[]alpha;
    delete[]betta;
    delete[]gamma;
    delete[]delta;
    delete[]P;
    delete[]Q;
    alpha=NULL;
    betta=NULL;
    gamma=NULL;
    delta=NULL;
    P=NULL;
    Q=NULL;
    for(i=0;i<N;i++)
        delete[]At[i];
    delete[]At;
    At=NULL;

    return (new Solution(X));
}
Solution*SweepMethod::SolveWithBC1A(double a,double al1,double al2,double gm1,double b,double bt1,double bt2,double gm2)
{
    int i;
    double**At,h=A->H();
    At=new double*[N];
    for(int i=0;i<N;i++)
        At[i]=new double[N];
    A->ConversionInStandart(At);

    double*P,*Q;
    double*alpha,*betta,*A,*B,*C,*G,*Y;
    //double a=0,al1=0,al2=1,gm1=5,b=1,bt1=0,bt2=1,gm2=13;
    P=new double [N+1];
    Q=new double [N+1];
    alpha=new double [N+1];
    betta=new double [N+1];
    A=new double [N+1];
    B=new double [N+1];
    C=new double [N+1];
    G=new double [N+1];
    Y=new double [N+1];

    A[1]=At[1][0];
    B[0]=At[0][0];
    C[0]=At[0][1];
    G[0]=F->GetElement(0);
    A[N-1]=At[N-1][N-2];
    B[N-1]=At[N-1][N-1];
    C[N-1]=At[N-2][N-1];
    G[N-1]=F->GetElement(N-1);
    for(i=1;i<N-1;i++)
    {
        A[i]=At[i][i-1];
        B[i]=At[i][i];
        C[i]=At[i][i+1];
        G[i]=F->GetElement(i);
    }
    alpha[1]=(-al1/h)/(-al1/h+al2);
    betta[1]=gm1/(-al1/h+al2);
    for(int i=1;i<N;i++)
    {
        alpha[i+1]=-C[i]/(B[i]+alpha[i]*A[i]);
        betta[i+1]=(G[i]-A[i]*betta[i])/(B[i]+alpha[i]*A[i]);
    }
    Y[N-1]=(gm2*h+bt1*betta[N-1])/(bt1-bt1*alpha[N-1]+bt2*h);
    for(int i=N-2;i>=0;i--)
        Y[i]=alpha[i+1]*Y[i+1]+betta[i+1];

    for(int i=0;i<N;i++)
        X->SetElement(i,Y[i]);

    delete[]alpha;
    delete[]betta;
    delete[]A;
    delete[]B;
    delete[]C;
    delete[]G;
    delete[]Y;
    alpha=NULL;
    betta=NULL;
    A=NULL;
    B=NULL;
    C=NULL;
    G=NULL;
    Y=NULL;
    for(i=0;i<N;i++)
        delete[]At[i];
    delete[]At;
    At=NULL;

    return (new Solution(X));
}
Solution*SweepMethod::SolveWithBC2A(double a,double al1,double al2,double gm1,double b,double bt1,double bt2,double gm2)
{
    int i;
    double**At,h=A->H();
    At=new double*[N];
    for(int i=0;i<N;i++)
        At[i]=new double[N];
    A->ConversionInStandart(At);

    double*P,*Q;
    double*alpha,*betta,*A,*B,*C,*G,*Y,*Alpha,*Betta;
    //double a=0,al1=0,al2=1,gm1=5,b=1,bt1=0,bt2=1,gm2=13;
    P=new double [N+1];
    Q=new double [N+1];
    alpha=new double [N+1];
    betta=new double [N+1];
    A=new double [N+1];
    B=new double [N+1];
    C=new double [N+1];
    G=new double [N+1];
    Y=new double [N+1];
    Alpha=new double [N+1];
    Betta=new double [N+1];

    A[1]=At[1][0];
    B[0]=-At[0][0];
    C[0]=At[0][1];
    G[0]=F->GetElement(0);
    A[N-1]=At[N-1][N-2];
    B[N-1]=-At[N-1][N-1];
    C[N-1]=At[N-2][N-1];
    G[N-1]=F->GetElement(N-1);
    for(i=1;i<N-1;i++)
    {
        A[i]=At[i][i-1];
        B[i]=-At[i][i];
        C[i]=At[i][i+1];
        G[i]=F->GetElement(i);
    }

    alpha[1]=(-4*al1+al1*(B[i]/C[i]))/(2*h*al2-3*al1+al1*(A[i]/C[i]));
    betta[1]=(al1*(G[i]/C[i])+2*h*gm1)/(2*h*al2-3*al1+al1*(A[i]/C[i]));

    for(int i=1;i<=N;i++)
    {
        alpha[i+1]=(-C[i])/(A[i]*alpha[i]-B[i]);
        betta[i+1]=(G[i]-A[i]*betta[i])/(A[i]*alpha[i]-B[i]);
    }

    Y[N]=(2*h*gm2+4*bt1*betta[N]-bt1*alpha[N-1]*betta[N]-bt1*betta[N-1])/(2*h*bt2+3*bt1-4*bt1*alpha[N]+bt1*alpha[N-1]*alpha[N]);
    for(int i=N-1;i>=0;i--)
        Y[i]=alpha[i+1]*Y[i+1]+betta[i+1];


    for(int i=0;i<N;i++)
        X->SetElement(i,Y[i]);

    delete[]alpha;
    delete[]betta;
    delete[]A;
    delete[]B;
    delete[]C;
    delete[]G;
    delete[]Y;
    alpha=NULL;
    betta=NULL;
    A=NULL;
    B=NULL;
    C=NULL;
    G=NULL;
    Y=NULL;
    for(i=0;i<N;i++)
        delete[]At[i];
    delete[]At;
    At=NULL;

    return (new Solution(X));
}
Solution*SweepMethod::Solve()
{
    /*int i;
    double**At;
    At=new double*[N];
    for(int i=0;i<N;i++)
        At[i]=new double[N];
    A->ConversionInStandart(At);

    double*P,*Q;
    double*alpha,*betta,*gamma,*delta;
    P=new double [N+1];
    Q=new double [N+1];
    alpha=new double [N+1];
    betta=new double [N+1];
    gamma=new double [N+1];
    delta=new double [N+1];

    alpha[0]=0;
    betta[0]=-At[0][0];
    gamma[0]=At[0][1];
    delta[0]=F->GetElement(0);
    alpha[N-1]=At[N-1][N-2];
    betta[N-1]=-At[N-1][N-1];
    gamma[N-1]=0;
    delta[N-1]=F->GetElement(N-1);
    for(i=1;i<N-1;i++)
    {
        alpha[i]=At[i][i-1];
        betta[i]=-At[i][i];
        gamma[i]=At[i][i+1];
        delta[i]=F->GetElement(i);
    }
    P[0]=gamma[0]/betta[0];
    Q[0]=-1.0*(delta[0]/betta[0]);
    for(i=1;i<N-1;i++)
    {
        P[i]=gamma[i]/(betta[i]-alpha[i]*P[i-1]);
        Q[i]=((alpha[i]*Q[i-1])-delta[i])/(betta[i]-(alpha[i]*P[i-1]));
    }
    X->SetElement(N-1,(alpha[N-1]*Q[N-2]-delta[N-1])/(betta[N-1]-alpha[N-1]*P[N-2]));
    //X->SetElement(N-1,13.0);
    for(i=N-2;i>=0;i--)
        X->SetElement(i,P[i]*X->GetElement(i+1)+Q[i]);
    //X->SetElement(0,5.0);

    delete[]alpha;
    delete[]betta;
    delete[]gamma;
    delete[]delta;
    delete[]P;
    delete[]Q;
    alpha=NULL;
    betta=NULL;
    gamma=NULL;
    delta=NULL;
    P=NULL;
    Q=NULL;
    for(i=0;i<N;i++)
        delete[]At[i];
    delete[]At;
    At=NULL;

    return (new Solution(X));*/
    return Solve(0,N-1);
}


MSweep::MSweep()
{
}


MSweep::~MSweep()
{
}
