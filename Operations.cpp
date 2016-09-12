#include "Operations.h"
#include"SystemOfEquations.h"

///матрица производных n-го порядка в точке
double Operations::der(double **u,int i,int j,double h)
{
    double ki=0,li=0,kj=0,lj=0;

    ki=u[i+1][j];
    li=u[i-1][j];
    kj=u[i][j+1];
    lj=u[i][j-1];

    ki=(ki-u[i][j])/h;
    li=(u[i][j]-li)/h;
    kj=(kj-u[i][j])/h;
    lj=(u[i][j]-lj)/h;

    return (ki-li+kj-lj)/h;
}

void Operations::DerivativeMatrix(double**u,double**du,int dN,double h,int n,int m)
{
    int i,j;
    for(int d=1;d<dN;d++)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                du[i][j]=u[i][j];

        //du[0][0]=DerivativeBorder(u[0][0],du,du,d);
        ///du[n][n]
        for(i=1;i<n-1;i++)
            for(j=1;j<n-1;j++)
                du[i][j]=der(u,i,j,h);
    }
}

double Operations::DerivativeBorder(double X,double*x,double*y,int n)
{
    n=n*10;
    double a,b,c=0,d=0;
    for(int i=0;i<=n;i=(i/10+1)*10)
    {
        a=y[i];b=1;
        for(int j=0;j<=n;j=(j/10+1)*10)
        {
            if(i!=j)
            {
                c+=(X-x[j]);
                b*=(1./(x[i]-x[j]));
            }
        }
        d+=2*a*c*b;
    }
    return d;
}

double Operations::DerivativePoint(double**u,int i,int j,int dN,double h,int n,int m)
{
    if(dN==0)
        return u[i][j];
    double **a;
    a=new double *[n];
    for(int i=0;i<n;i++)
        a[i]=new double[m];

    if(dN==1)
        dN=1;

    if(dN>2)
        DerivativeMatrix(u,a,dN-1,h,n,m);

    double c=der(a,i,j,h);
    for(int i=0;i<m;i++)
        delete a[i];
            delete[] a;
            a=NULL;
    return c;
}
double Operations::DerivativePoint(Matrix*u,int i,int j,int dN,double h)
{
    int n,m;
    //cout<<"der"<<endl<<u<<endl;
    u->CountElements(n,m);
    double**mx;
    mx=new double*[n];
    for(int l=0;l<n;l++)
        mx[l]=new double[m];
    u->ConversionInStandart(mx);
    //double p = DerivativePoint(mx,i,j,dN,h,n,m);
    double p = A(mx,i,j,h);
    for(int l=0;l<m;l++)
        delete mx[l];
    delete[] mx;
    mx=NULL;
    return p;
}
double Operations::A(double**u,int i,int j,double h)
{
    return (u[i+1][j]-2*u[i][j]+u[i-1][j])/pow(h,2)+(u[i][j+1]-2*u[i][j]+u[i][j-1])/pow(h,2);
}
double Operations::Norm(int n,int m,double**rn,double h)
{
    double N=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            N+=(pow(rn[i][j],2)*pow(h,2));
    return sqrt(N);
}
double Operations::DerivativePoint(double*u,int i,int dN,double h)
{

}
double Operations::DerivativePoint(Vector*u,int i,int dN,double h)
{

}
double Operations::Integration(double a,double b,int n,double (*eq)(double),double (*eqd)(double),int WI)
{
    double h;
    if(n!=0)
    {
        h=(b-a)/n;
        cout<<"h "<<h<<endl;
    }
    else
    {
        h=0.01;
        n=fabs((b-a)/h);
    }
    //func=new Function(eq);
    marker=false;
    double*x,*y;
    y=new double[n+1];
    x=new double[n+1];
    printf("n = %d\n",n);
    x[0]=a;
    for(int i=1;i<n+1;i++)
    {
        x[i]=a+i*h;
    }
    for(int i=0;i<n+1;i++)
    {
         y[i]=eq(x[i]);
    }
    if(WI==1)
    {
        RatingTrapezoid(x,h,n,b,a,eqd);
        return IntegrationTrapezoid(y,h,n);
    }
    if(WI==2)
    {
        RatingSimpson(x,h,n,b,a,eqd);
        return IntegrationSimpson(y,h,n);
    }
    if(WI==3)
    {
        Rating3D8(x,h,n,b,a,eqd);
        return Integration3D8(y,h,n);
    }
    if(WI==4)
    {
        return IntegrationGauss(a,b,eq);
    }
    if(WI==5)
    {
        RatingLeftRectangle(x,h,n,b,a,eqd);
        return IntegrationLeftRectangle(y,h,n);
    }
    if(WI==6)
    {
        RatingRightRectangle(x,h,n,b,a,eqd);
        return IntegrationRightRectangle(y,h,n);
    }
    if(WI==7)
    {
        double *temp=new double[n+1];
        for(int i=0;i<n;i++)
            temp[i]=eq(x[i]+h/2.);
        RatingCentralRectangle(x,h,n,b,a,eqd);
        double icr=IntegrationCentralRectangle(temp,h,n);
        delete temp;
        return icr;
    }
    else
    {
        cout<<"Way is not fined"<<endl;
        exit(0);
    }
}
/*double Operations::Integration(double a,double b,double (*eq)(double))
{
    double*x,*y,h=0.01;
    int n=fabs((b-a)/h);
    y=new double[n+1];
    x=new double[n+1];
    printf("n = %d\n",n);
    x[0]=a;
    for(int i=1;i<n+1;i++)
    {
        x[i]=a+i*h;
    }
    for(int i=0;i<n+1;i++)
    {
         y[i]=eq(x[i]);
    }
    return IntegrationTrapezoid(y,h,n);
}*/
//double Integration(double a,double b,Function*eq,WayIntegration WI);
//double Integration(double a,double b,Function*eq);
double Operations::IntegrationTrapezoid(double*y,double h,int n)
{
    double I=(y[0]+y[n])/2.;
    for(int i=1;i<n;i++)
        I+=y[i];
    return I*h;
}
double Operations::RatingTrapezoid(double *x,double h,int n,double b,double a,double (*eq2)(double))
{
    double Max=eq2(x[0]);
    for(int i=1;i<n;i++)
    {
        if(eq2(x[i])>Max)
            Max=eq2(x[i]);
    }
    ratingIntegration=-1*((b-a)/12.)*Max*h*h;
    marker=true;
    return ratingIntegration;
}
double Operations::IntegrationSimpson(double*y,double h,int n)
{
    double I=y[0];
    for(int i=1;i<n;i++)
    {
        if(i%2==0)
            I+=2.*y[i];
        else
            I+=4.*y[i];
    }
    I+=y[n];

    return I*(h/3.0);

}
double Operations::RatingSimpson(double *x,double h,int n,double b,double a,double (*eq4)(double))
{
    double Max=eq4(x[0]);
    for(int i=1;i<n;i++)
    {
        if(eq4(x[i])>Max)
            Max=eq4(x[i]);
    }
    ratingIntegration=-1*((b-a)/180.)*Max*pow(h,4);
    marker=true;
    return ratingIntegration;
}
double Operations::Integration3D8(double*y,double h,int n)
{
    double I=y[0]+y[n],I1=0,I2=0;
    for(int i=1;i<n;i++)
    {
        if(i%3==0)
            I2+=y[i];
        else
            I1+=y[i];
    }
    I=I+3*I1+2*I2;

    return I*3*h/8.;
}
double Operations::Rating3D8(double *x,double h,int n,double b,double a,double (*eq4)(double))
{
    double Max=eq4(x[0]);
    for(int i=1;i<n;i++)
    {
        if(eq4(x[i])>Max)
            Max=eq4(x[i]);
    }
    ratingIntegration=-1*((b-a)/80.)*Max*pow(h,4);
    marker=true;
    return ratingIntegration;
}
double Operations::IntegrationGauss(double a,double b,double (*eq)(double))
{
    double *x=new double[4];
    double *t=new double[4];
    double *Ai=new double[4];
    t[0]=-0.86113631;
    t[3]=0.86113631;
    t[1]=-0.33998104;
    t[2]=0.33998104;
    Ai[0]=0.34785458;
    Ai[3]=0.34785458;
    Ai[1]=0.65214516;
    Ai[2]=0.65214516;
    for(int i=0;i<4;i++)
        x[i]=((b+a)/2)+((b-a)/2)*t[i];
    double I=0;
    for(int i=0;i<4;i++)
    {
        I+=Ai[i]*eq(x[i]);
    }
    return I*(b-a)/2;
}
double Operations::IntegrationLeftRectangle(double*y,double h,int n)
{
    double I=0;
    for(int i=0;i<n;i++)
    {
        I+=y[i];
    }
    return I*h;
}
double Operations::RatingLeftRectangle(double *x,double h,int n,double b,double a,double (*eq1)(double))
{
    double Max=eq1(x[0]);
    for(int i=1;i<n;i++)
    {
        if(eq1(x[i])>Max)
            Max=eq1(x[i]);
    }
    ratingIntegration=Max*pow(b-a,2)/(2.*n);
    marker=true;
    return ratingIntegration;
}
double Operations::IntegrationRightRectangle(double*y,double h,int n)
{
    double I=0;
    for(int i=1;i<n+1;i++)
    {
        I+=y[i];
    }
    return I*h;
}
double Operations::RatingRightRectangle(double *x,double h,int n,double b,double a,double (*eq1)(double))
{
    double Max=eq1(x[0]);
    for(int i=1;i<n;i++)
    {
        if(eq1(x[i])>Max)
            Max=eq1(x[i]);
    }
    ratingIntegration=Max*pow(b-a,2)/(2.*n);
    marker=true;
    return ratingIntegration;
}
double Operations::IntegrationCentralRectangle(double*y,double h,int n)
{
    double I=0;
    for(int i=0;i<n;i++)
    {
        I+=y[i];
    }
    return I*h;
}
double Operations::RatingCentralRectangle(double *x,double h,int n,double b,double a,double (*eq2)(double))
{
    double Max=eq2(x[0]);
    for(int i=1;i<n;i++)
    {
        if(eq2(x[i])>Max)
            Max=eq2(x[i]);
    }
    ratingIntegration=Max*pow(b-a,3)/(24.*pow(n,2));
    marker=true;
    return ratingIntegration;
}
double Operations::RatingIntegration()
{
    if(marker==true)
        return ratingIntegration;
    else
    {
        cout<<"Don't know rating!!!\a"<<endl;
        return NULL;
    }
}
