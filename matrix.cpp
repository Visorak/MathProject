#include"matrix.h"
#include<time.h>
Matrix :: Matrix()
{
    //srand(time(0));
    N=10;
    M=10;
    h=1;
    Determin=0;
    Maximum=0;
    Minimum=0;
    int i;
    mx=new double*[N];
    for(i=0;i<N;i++)
        mx[i]=new double[M];
    for(i=0;i<N;i++)
        for(int j=0;j<M;j++)
            mx[i][j]=0;
}
Matrix::Matrix(Matrix&a)
{
    a.CountElements(N,M);
    h=a.H();
    Determin=0;
    Maximum=0;
    Minimum=0;
    int i;
    mx=new double*[N];
    for(i=0;i<N;i++)
        mx[i]=new double[M];
    for(i=0;i<N;i++)
        for(int j=0;j<M;j++)
            mx[i][j]=a.GetElement(i,j);

}
Matrix::Matrix(int n)
{
    Matrix(n,n);
}
Matrix::Matrix(int n,int m)
{
    N=n;
    M=m;
    h=1.;
    Determin=0;
    Maximum=0;
    Minimum=0;
    int i;
    mx=new double*[N];
    for(i=0;i<N;i++)
        mx[i]=new double[M];

    for(i=0;i<N;i++)
        for(int j=0;j<M;j++)
            mx[i][j]=0;
}
Matrix::Matrix(int n,int m,bool random)
{
    srand(time(NULL));
    N=n;
    M=m;
    h=1;
    Determin=0;
    Maximum=0;
    Minimum=0;
    int i;
    mx=new double*[N];
    for(i=0;i<N;i++)
        mx[i]=new double[M];
    if(random==0.)
        for(i=0;i<N;i++)
            for(int j=0;j<M;j++)
                mx[i][j]=0;
    else if(random==1.)
        for(i=0;i<N;i++)
            for(int j=0;j<M;j++)
                mx[i][j]=rand()%10;
}
Matrix :: Matrix(int n,int m,char*path)
{
    N=n;
    M=m;
    h=1;
    Determin=0;
    Maximum=0;
    Minimum=0;
    int i;
    mx=new double*[N];
    for(i=0;i<N;i++)
        mx[i]=new double[M];
    ifstream fin(path);
    char eos='a',eosN='\r\n';
    /*cout<<eos<<endl;
    //eos=0x0A '\r\n';
    cout<<eosN;*/
    for(i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            fin>>mx[i][j];
            /*if(j==M-1)
            {while(eos=10 && !fin.eof())
                {fin>>eos;if(eosN==eos)cout<<"Нашёл!"<<endl;cout<<eos;system("PAUSE");}}*/
        }
}
Matrix :: Matrix(int n,int m,double h,char*path)
{
    N=n;
    M=m;
    this->h=h;
    Determin=0;
    Maximum=0;
    Minimum=0;
    int i;
    mx=new double*[N];
    for(i=0;i<N;i++)
        mx[i]=new double[M];
    ifstream fin(path);
    char eos='a',eosN='\r\n';
    /*cout<<eos<<endl;
    //eos=0x0A '\r\n';
    cout<<eosN;*/
    for(i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            fin>>mx[i][j];
            /*if(j==M-1)
            {while(eos=10 && !fin.eof())
                {fin>>eos;if(eosN==eos)cout<<"Нашёл!"<<endl;cout<<eos;system("PAUSE");}}*/
        }
}
Matrix :: Matrix(int n,int m,double hh)
{
    N=n;
    M=m;
    h=hh;
    Determin=0;
    Maximum=0;
    Minimum=0;
    int i;
    mx=new double*[N];
    for(i=0;i<N;i++)
        mx[i]=new double[M];
    for(i=0;i<N;i++)
        for(int j=0;j<M;j++)
            mx[i][j]=0;
}
Matrix :: Matrix(double**c,int n,int m)
{
    Matrix(c,n,m,1.0);
}
Matrix :: Matrix(double**c,int n,int m,double hh)
{
    N=n;
    M=m;
    h=hh;
    Determin=0;
    Maximum=0;
    Minimum=0;
    int i;
    mx=new double*[N];
    for(i=0;i<N;i++)
        mx[i]=new double[M];
    for(i=0;i<N;i++)
        for(int j=0;j<M;j++)
            mx[i][j]=c[i][j];
}
Matrix::~Matrix()
{
    //cout<<N<<" "<<M<<endl;
    for(int i=0;i<M;i++)
        delete mx[i];
    delete []mx;
    mx=NULL;
}
Matrix&Matrix::operator=(double d)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            mx[i][j]=d;
    return*this;
}
Matrix&Matrix::operator=(Matrix&c)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            mx[i][j]=c.GetElement(i,j);
    return *this;
}
Matrix&Matrix::operator=(Matrix*c)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            mx[i][j]=c->GetElement(i,j);
    return *this;
}
Matrix&Matrix::operator=(double**c)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            mx[i][j]=c[i][j];
    return *this;
}
bool Matrix::Squere()
{
    if(N==M)
        return true;
    return false;
}
double Matrix::GetElement(int ei,int ej)const
{
    return mx[ei][ej];
}
void Matrix::SetElement(int ei,int ej,double d)
{
    mx[ei][ej]=d;
    if(d>Max)
        Max=d;
    if(d<Min)
        Min=d;
    Determin=0;
    return;
}
bool Matrix :: SetMatrix(Vector**v,char coast)
{
    if(coast=='v')
    {
        for(int i=0;i<N;i++)
        {
            this->SetColumn(i,v[i]);
        }
        return 0;
    }
    else if(coast=='h')
    {
        for(int i=0;i<M;i++)
        {
            this->SetString(i,v[i]);
        }
        return 0;
    }
    else
    {
        cout<<"Error symbol"<<endl;
        exit(0);
    }
}
int Matrix::CountElements(int &n,int &m)const
{
    n=N;
    m=M;
    return N*M;
}
double Matrix::Norm()const
{
    return NormMax();
}
double Matrix::Norm(double**c,int n,int m,double h)const
{
    double t=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            t+=pow(c[i][j],2)*pow(h,2);
    return sqrt(t);
}
double Matrix::NormMax()const
{
    double Max=fabs(mx[0][0]);
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(Max<fabs(mx[i][j]))
                Max=fabs(mx[i][j]);
        }
    return Max;
}
double Matrix::NormSqrt()const
{
    double t=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            t+=pow(mx[i][j],2);//*pow(h,2);
    return sqrt(t);
}
bool Matrix::Comparison(const Matrix&c)const
{
    int n,m;
    CountElements(n,m);
    if(n!=N || m!=M)
    {
        cout<<N<<" "<<n<<" and "<<M<<" "<<m<<endl;
        cout<<"Vectors of different dimensions!"<<endl;
        return 0;
    }
    return 1;
}
bool Matrix::IsSimmetrial()
{
    if(!Squere())
    {
        cout<<"Error! Matrix "<<N<<"x"<<M<<"!\a"<<endl;
        return false;
    }
    bool result=true;
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
            if(mx[i][j]!=mx[j][i])
            {
                result=false;
                break;
            }
        if(!result)
            break;
    }
    return result;
}
Matrix&Matrix::operator+(const Matrix&c)const
{
    if(!Comparison(c))
        exit(777);
    Matrix&res=*(new Matrix(N,M,h));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            res.SetElement(i,j,mx[i][j]+c.GetElement(i,j));
    return res;
}
Matrix& Matrix :: operator-(const Matrix&c)const
{
    if(!Comparison(c))
        exit(777);
    Matrix*res=(new Matrix(N,M,h));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            {res->SetElement(i,j,mx[i][j]-c.GetElement(i,j));/* cout<<mx[i][j]<<" "<<c.GetElement(i,j)<<" "<<res->GetElement(i,j)<<endl;*/}
    return *res;
}
Matrix&Matrix::operator*(const Matrix&c)const
{
    int n,m,i,j,l;
    c.CountElements(n,m);
    if(n!=M)
    {
        cout<<"Error! Matrixes "<<N<<"x"<<M<<" and "<<n<<"x"<<m<<"!\a"<<endl;
        exit(777);
    }
    double s;
    Matrix&res=*(new Matrix(N,m,h));
    for(i=0; i<N; i++)
    {
        for(l=0; l<m; l++)
        {
            s = 0;
            for(j=0;j<m;j++)
            {
                s+=mx[i][j]*c.GetElement(j,l);
            }
            res.SetElement(i,l,s);
        }
    }
    return res;
}
double Matrix::operator%(const Matrix*c)const
{
    int n,m;
    c->CountElements(n,m);
    if(n!=N || m!=M)
    {
        cout<<"Error! Matrixes "<<N<<"x"<<M<<" and "<<n<<"x"<<m<<"!\a"<<endl;
        exit(777);
    }
    double s=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            s+=(mx[i][j]*(c->GetElement(i,j)));
    return s;
}
double Matrix::operator%(const Matrix&c)const
{
    int n,m;
    c.CountElements(n,m);
    if(n!=N || m!=M)
    {
        cout<<"Error! Matrixes "<<N<<"x"<<M<<" and "<<n<<"x"<<m<<"!\a"<<endl;
        exit(777);
    }
    double s=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            s+=(mx[i][j]*(c.GetElement(i,j)));
    return s;
}
double Matrix::Skalyar(const Matrix*c)const
{
    int n,m;
    c->CountElements(n,m);
    if(n!=N || m!=M)
    {
        cout<<"Error! Matrixes "<<N<<"x"<<M<<" and "<<n<<"x"<<m<<"!\a"<<endl;
        exit(777);
    }
    double s=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            s+=(mx[i][j]*(c->GetElement(i,j)));
    return s;
}
Vector&Matrix::operator*(const Vector&c)const
{
    double bt;
    Vector &b=*(new Vector(N));
    for(int i=0;i<N;i++)
    {
        bt=0;
        for(int j=0;j<M;j++)
            bt+=mx[i][j]*c.GetElement(j);
        b.SetElement(i,bt);
    }
    return b;
}
Matrix&Matrix::operator+(double d)const
{
    Matrix&res=*(new Matrix(N,M,h));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        res.SetElement(i,j,mx[i][j]+d);
    return res;
}
Matrix&Matrix::operator-(double d)const
{
    Matrix&res=*(new Matrix(N,M,h));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        res.SetElement(i,j,mx[i][j]-d);
    return res;
}
Matrix&Matrix::operator*(double d)const
{
    Matrix&res=*(new Matrix(N,M,h));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            res.SetElement(i,j,mx[i][j]*d);
    return res;
}
Matrix&Matrix::operator/(double d)const
{
    if(d==0 || d==0.0)
    {
        cout<<"Division by zero is forbidden!\a"<<endl;
        exit(777);
    }
    Matrix&res=*(new Matrix(N,M,h));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        res.SetElement(i,j,mx[i][j]/d);
    return res;
}
Matrix&Matrix::operator!()const
{
    if(N!=M)
    {
        cout<<"Error! Matrix "<<N<<"x"<<M<<"!\a"<<endl;
        exit(777);
    }
    Matrix&res=*(new Matrix(N,N,h));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            res.SetElement(j,i,mx[i][j]);
    return res;
}
Matrix&Matrix::Reverse()const
{
    double a,b,coef;

    Matrix*CONST=new Matrix(N,N);
    Matrix*A=new Matrix(N,N);
    Matrix*A1=new Matrix(*A);

    Vector*B=new Vector(N);
    Vector*B1=new Vector(*B);

    Vector*X=new Vector(N);

    Matrix&res=*(new Matrix(N,M,0.));

    for(int t=0;t<N;t++)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                CONST->SetElement(i,j,mx[i][j]);
        A=CONST;
        A1=CONST;
        *B=0;
        B->SetElement(t,1);
        B1=B;
        //cout<<"A:\n"<<A<<endl;
        //cout<<"B:\n"<<B<<endl;
        for(int i=0;i<N-1;i++)
        {
            for(int k=i+1;k<N;k++)
            {
                coef=(-1)*A->GetElement(k,i)/A->GetElement(i,i);
                for(int j=i;j<N;j++)
                    A1->SetElement(k,j,(A->GetElement(k,j)+A->GetElement(i,j)*coef));
                B1->SetElement(k,(B->GetElement(k)+B->GetElement(i)*coef));
            }
            A=A1;
            B=B1;
        }
        for(int i=N-1;i>=0;i--)
        {
            a=B->GetElement(i);
            b=A->GetElement(i,i);
            for(int j=0;j<N;j++)
            {
                if(j>i)
                    a-=A->GetElement(i,j)*X->GetElement(j);
            }
            if(a==0||b==0)
                X->SetElement(i,0);
            else
                X->SetElement(i,a/b);
        }
        //cout<<"X:\n"<<X<<endl;
        res.SetColumn(t,X);
        //cout<<endl<<res<<endl;
    }
    //cout<<"CONST:\n"<<CONST<<endl;
    return res;
}
double Matrix::DeterminateToGauss()
{
    if(N!=M)
    {
        cout<<"Error! Matrix "<<N<<"x"<<M<<"!\a"<<endl;
        return 0;
    }
    int i,j,n,m;
    double**mx0,**mx1,coef;
    mx0=new double*[N];
    for(i=0;i<N;i++)
        mx0[i]=new double[N];
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            mx0[i][j]=mx[i][j];
    mx1=new double*[N];
    for(i=0;i<N;i++)
        mx1[i]=new double[N];
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            mx1[i][j]=mx[i][j];

    for(i=0;i<N-1;i++)
    {
        for(int k=i+1;k<N;k++)
        {
            coef=(-1)*mx0[k][i]/mx0[i][i];
            for(j=i;j<N;j++)
                mx1[k][j]=mx0[k][j]+mx0[i][j]*coef;
        }
        for(n=0;n<N;n++)
            for(m=0;m<N;m++)
                mx0[n][m]=mx1[n][m];
    }
    Determin=1;
    Det=1;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(i==j)
                Det*=mx1[i][j];
    return Det;
}
double Matrix::Determinate()
{
    return DeterminateToGauss();
}
int Matrix::Rotation(double eps)
{
    int result=1;
    int i,j,k;
    int maxI,maxJ;
    double max,fi;
    double**mxOfTurn,**temp,**sol;
    mxOfTurn=new double*[N];
    coeffs=new double*[N];
    temp=new double*[N];
    sol=new double*[N];
    for(i=0;i<N;i++)
    {
        mxOfTurn[i]=new double[N];
        coeffs[i]=new double[N];
        temp[i]=new double[N];
        sol[i]=new double[N];
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            sol[i][j]=0;
            coeffs[i][j]=mx[i][j];
        }
        sol[i][i]=1;
    }
    double fault=0.0;
    for(i=0;i<N;i++)
        for(j=i+1;j<N;j++)
            fault=fault+pow(coeffs[i][j],2);
    fault=sqrt(2*fault);
    while(fault>eps)
    {
        max=0.0;
        for(i=0;i<N;i++)
            for(j=i+1;j<N;j++)
                if(coeffs[i][j]>0 && coeffs[i][j]>max)
                {
                    max=coeffs[i][j];
                    maxI=i;
                    maxJ=j;
                }
                else if(coeffs[i][j]<0 && -coeffs[i][j]>max)
                {
                    max=-coeffs[i][j];
                    maxI=i;
                    maxJ=j;
                }

        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
                mxOfTurn[i][j]=0;
            mxOfTurn[i][i]=1;
        }
        if(coeffs[maxI][maxI]==coeffs[maxJ][maxJ])
        {
            mxOfTurn[maxI][maxI]=mxOfTurn[maxJ][maxJ]=mxOfTurn[maxJ][maxI]=sqrt(2.0)/2.0;
            mxOfTurn[maxI][maxJ]=-sqrt(2.0)/2.0;
        }
        else
        {
            fi=0.5*atan((2.0*coeffs[maxI][maxJ])/(coeffs[maxI][maxI]-coeffs[maxJ][maxJ]));
            mxOfTurn[maxI][maxI]=mxOfTurn[maxJ][maxJ]=cos(fi);
            mxOfTurn[maxI][maxJ]=-sin(fi);
            mxOfTurn[maxJ][maxI]=sin(fi);
        }
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                temp[i][j]=0.0;
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                for(k=0;k<N;k++)
                    temp[i][j]+=mxOfTurn[k][i]*coeffs[k][j];
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                coeffs[i][j]=0.0;
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                for(k=0;k<N;k++)
                    coeffs[i][j]+=temp[i][k]*mxOfTurn[k][j];
        fault=0.0;
        for(i=0;i<N;i++)
            for(j=i+1;j<N;j++)
                fault+=pow(coeffs[i][j],2);
        fault=sqrt(2*fault);

        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                temp[i][j]=0.0;
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                for(k=0;k<N;k++)
                    temp[i][j]+=sol[i][k]*mxOfTurn[k][j];
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                sol[i][j]=temp[i][j];
        result++;

    }
    return result;
}
bool Matrix::EigenValues(Vector&ei,double eps)
{
    /*if(!IsSimmetrial())
    {
        cout<<"Matrix non simmetrix"<<endl;
        return false;
    }
    else*/
    {
        int steps=Rotation(eps);
        //cout<<"Reshenie:\n";
        /*for(i=0;i<size;i++)
        {
            cout<<"Собственный вектор k "<<i+1<<":\n";
            for(j=0;j<size;j++)
            {
                cout<<sol[j][i]<<"\n";
            }
        }*/
        //cout<<"Собственные значения:\n";
        for(int i=0;i<N;i++)
        {
            ei.SetElement(i,coeffs[i][i]);
            //cout<<coeffs[i][i]<<"\n";
        }
        for(int i=0;i<M;i++)
            delete coeffs[i];
                delete []coeffs;
        //cout<<"Общее число шагов: "<<steps;
    }
    return true;
}
void Matrix::Transposition()
{
    if(N!=M)
    {
        cout<<"Error! Matrix "<<N<<"x"<<M<<"!\a"<<endl;
        return;
    }
    Matrix&temp=*(new Matrix(N,N,0.));
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            temp.SetElement(j,i,mx[i][j]);
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            mx[i][j]=temp.GetElement(i,j);
}
double Matrix::PublicDeterminate(int n,double**c)
{
    ///Старый метод(через миноры)
    int i,j,k,l;
    double det=1,g;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1;j++)
        {
            if(i==j)
                for(k=i+1;k<n;k++)
                {
                    g=c[k][j];
                    for(l=j;l<n;l++)
                        if((c[i][j]>=0 && c[i][0]>=0)||(c[i][j]<0 && c[i][0]<0))
                            c[k][l]=c[k][l]*(-c[i][j]) + c[i][l]*g;
                        else
                            c[k][l]=c[k][l]*c[i][j] + c[i][l]*g;
                }
                /*for(int e=0;e<n;e++)
                    {for(int f=0;f<n;f++)
                        cout<<mx[e][f]<<"  ";cout<<endl;}*/

            g=0;
        }

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(i==j)
                    if(c[i][j]!=0)
                        if(c[n-1][n-1]!=0)
                            if((c[i][j]>=0 && c[i][0]>=0)||(c[i][j]<0 && c[i][0]<0))
                                det*=c[i][j]/pow(-c[i][j],n-1-i);
                            else
                                det*=c[i][j]/pow(c[i][j],n-1-i);
                        else
                            det=0;
    return det;
}
double Matrix::DeterminateToMinors()
{
    if(Determin==1)
        return Det;
    if(N!=M)
    {
        cout<<"Error! Matrix "<<N<<"x"<<M<<"!\a"<<endl;
        return 0;
    }
    Det=PublicDeterminate(N,mx);
    Determin=1;
    return Det;
}
Matrix&Matrix::ApproximateMatrix()
{

    ///Старый метод
    double **b,**d,**res,D;
    int h,q,i,j,t,p, n=N;
    d=new double*[n];
    for(i=0;i<n;i++)
        d[i]=new double[n];
    b=new double*[n-1];
    for(i=0;i<n-1;i++)
        b[i]=new double[n-1];
    res=new double*[n];
    for(i=0;i<n;i++)
        res[i]=new double[n];

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            t=0;
            for(q=0;q<n;q++)
            {
                p=0;
                if((q!=i)&&(h!=j))
                {
                    for(h=0;h<n;h++)
                        if((q!=i)&&(h!=j))
                        {
                            b[t][p]=res[q][h];
                            p++;
                        }
                        t++;
                }
            }

            D=PublicDeterminate(n-1,b);
            d[i][j]=(pow(-1,i+j))*D;
        }
    for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                res[j][i]=d[i][j];

    for(i=0;i<n;i++)
    {
        delete []b[i];
        delete []d[i];
    }
    delete []b;
    delete []d;
    return ConversionInClass(res);
}
double Matrix::MaxElement(int&ei,int&ej)
{
    if(Maximum==1)
        return Max;
    Max=mx[0][0];ei=0;ej=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(Max<mx[i][j])
            {
                Max=mx[i][j];
                ei=i;ej=j;
            }
        }
    Maximum==1;
    return Max;
}
double Matrix::MaxElementStringFrom(int ei,int from,int&ej)
{
    double Max=mx[ei][from];
    ej=from;
    for(int j=from+1;j<M;j++)
        if(mx[ei][j]>Max)
        {
            Max=mx[ei][j];
            ej=j;
        }
    return Max;
}
double Matrix::MaxElementString(int ei,int&ej)
{
    return MaxElementStringFrom(ei,0,ej);
}
double Matrix::MaxElementColumnFrom(int ej,int from,int&ei)
{
    double Max=mx[from][ej];
    ei=from;
    for(int i=from+1;i<N;i++)
        if(mx[i][ej]>Max)
        {
            Max=mx[i][ej];
            ei=i;
        }
    return Max;
}
double Matrix::MaxElementColumn(int ej,int&ei)
{
    return MaxElementColumnFrom(ej,0,ei);
}
double Matrix::MinElement(int&ei,int&ej)
{
    if(Minimum==1)
        return Max;
    Min=mx[0][0];ei=0;ej=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(Min>mx[i][j])
            {
                Min=mx[i][j];
                ei=i;ej=j;
            }
        }
    Minimum==1;
    return Min;
}
double Matrix::MinElementStringFrom(int ei,int from,int&ej)
{
    double Min=mx[ei][from];
    ej=from;
    for(int j=1;j<M;j++)
        if(mx[ei][j]<Min)
        {
            Min=mx[ei][j];
            ej=j;
        }
    return Min;
}
double Matrix::MinElementString(int ei,int&ej)
{
    return MinElementStringFrom(ei,0,ej);
}
double Matrix::MinElementColumnFrom(int ej,int from,int&ei)
{
    double Min=mx[from][ej];
    ei=from;
    for(int i=from+1;i<N;i++)
        if(mx[i][ej]<Min)
        {
            Min=mx[i][ej];
            ei=i;
        }
    return Min;
}
double Matrix::MinElementColumn(int ej,int&ei)
{
    return MinElementColumnFrom(ej,0,ei);
}
double Matrix::SetString(int ei,Vector*v)
{
    for(int j=0;j<N;j++)
        mx[ei][j]=v->GetElement(j);
}
double Matrix::SetColumn(int ej,Vector*v)
{
    for(int i=0;i<N;i++)
        mx[i][ej]=v->GetElement(i);
}
void Matrix::CopyBoundCond(Matrix*mat)
{
    double**temp;
    temp=new double*[N];
    for(int i=0;i<N;i++)
        temp[i]=new double[M];
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            temp[i][j]=mx[i][j];
            mx[i][j]=mat->GetElement(i,j);
        }
    for(int i=1;i<N-1;i++)
        for(int j=1;j<M-1;j++)
            mx[i][j]=temp[i][j];

}
/*const double*Matrix::operator[](int i)const
{
    if(i>=0 && i<N)
    {
        /*NM=1;
        int j=*mx[i][5];
        cout<<mx[0]<<" "<<(mx[i])<<" "<<mx[N-1]<<endl<<endl;

        for(int k=0;k<N;k++)
        {
            for(int l=0;l<M;l++)
                cout<<&mx[k][l]<<" ";
            cout<<endl;
        }
        cout<<i<<" "<<j<<endl;*/
        //if(mx[0]<=mx[i] && mx[i]<=mx[N-1])
        /*cout<<(*mx[i])<<endl;
            return mx[i];
        /*else
        {
            cout<<"Error index j!\a"<<endl;
            exit(0);
        }*/
    /*}
    else
    {
        cout<<"Error index i!\a"<<endl;
        exit(0);
    }
}*/
/*double*Matrix::operator[](int j)
{
    if(j>=0 && j<M)
        return mx[j];
    else
    {
        cout<<"Error index j!\a"<<endl;
        exit(0);
    }
}*/
double Matrix::operator()(int i,int j)
{
    if(i>=0 && i<N && j>=0 && j<M)
        return mx[i][j];
    else
    {
        cout<<"Error index!\a"<<endl;
        exit(0);
    }
}
void Matrix::ResetProperties(bool D,bool f,bool sup,bool inf)
{
    if(D==1)
        Determin=0;
    if(f==1)
    {
        /*for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                mx[i][j]=first[i][j];*/
        Determin=0;
        Maximum=0;
        Minimum=0;
    }
    if(sup==1)
    {
        Maximum=0;
    }
    if(inf==1)
    {
        Minimum=0;
    }
    return;
}
void Matrix::IdentityMatrix()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            if(i==j)
                mx[i][j]=1;
            else
                mx[i][j]=0;
        }
}
Matrix&Matrix::ConversionInClass(double**c)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            mx[i][j]=c[i][j];
        return *this;
}
void Matrix::ConversionInStandart(double**c)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            c[i][j]=mx[i][j];
    return;
}
bool Matrix::FindElement(int&ei,int&ej,double d)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(mx[i][j]==d)
            {
                ei=i;ej=j;
                return 0;
            }
    return 1;
}
bool Matrix::MoveString(int ei0,int ei)
{
    if(ei0<0 || ei<0 || ei0>=M || ei>=M)
        return 1;
    double a;
    for(int j=0;j<M;j++)
    {
        a=mx[ei][j];
        mx[ei][j]=mx[ei0][j];
        mx[ei0][j]=a;
    }
    return 0;

}
bool Matrix::MoveColumn(int ej0,int ej)
{
    if(ej0<0 || ej<0 || ej0>=N || ej>=N)
        return 1;
    double a;
    for(int i=0;i<N;i++)
    {
        a=mx[i][ej];
        mx[i][ej]=mx[i][ej0];
        mx[i][ej0]=a;
    }
    return 0;
}
bool Matrix::MoveElement(int ei0,int ej0,int ei,int ej)
{
    if(ei0<0 || ei<0 || ei0>=M || ei>=M || ej0<0 || ej<0 || ej0>=N || ej>=N)
        return 1;
    double a=mx[ei0][ej0];
    mx[ei0][ej0]=mx[ei][ej];
    mx[ei][ej]=a;
    return 0;
}
double Matrix::EigenValue(int m)
{
    if(!Squere())
    {
        cout<<"Matrix non squere"<<endl;
        exit(0);
    }
    double Sum = 0;
    double Lmb = 0;
    double* Y = new double [N+1];
    double* Ay_next = new double [N+1];
    double* Ay = new double [N+1];
    double* K = new double [N+1];
    for(int i=0;i<=N;i++)
    {
        Y[i] = 1;
        Ay_next[i]=0;
    }

    for(int l=1;l<=m;l++)
    {


        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                Ay_next[i]+=mx[i][j]*Y[j];
            }
        }

        for(int i=0;i<N;i++)
        {
            Ay[i] = Y[i];
            Y[i] = Ay_next[i];
            Ay_next[i] = 0;
        }
        /*for(int i=0;i<N;i++)
        {
            Ay_next[i] = 0;
        }*/
    }

    /*for(int i=0;i<N;i++)
    {
        printf("Y:%lf  Ay:%lf\n",Y[i],Ay[i]);
    }*/
    ///Находим вектор отношений
    for(int i=0;i<N;i++)
    {
        K[i] = Y[i]/Ay[i];
    }
    ///Считаем среднеарифм
    for(int i=0;i<N;i++)
    {
        Sum+=K[i];
        //cout<<K[i]<<endl;
    }
    ///Находим ламбду
    Lmb = Sum/N;
    return Lmb;
}
bool Matrix::Flip(char t)
{
    double a;
    if(t=='h'||t=='H')
    {
        for(int i=0;i<N/2;i++)
            for(int j=0;j<M;j++)
            {
                a=mx[i][j];
                mx[i][j]=mx[N-1-i][j];
                mx[N-1-i][j]=a;
            }
        return true;
    }
    if(t=='v'||t=='V')
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<M/2;j++)
            {
                a=mx[i][j];
                mx[i][j]=mx[i][M-1-j];
                mx[i][M-1-j]=a;
            }
        return true;
    }
    return false;
}
istream&operator>>(istream&s,Matrix&c)
{
    double el;
    int n,m;
    c.CountElements(n,m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            s>>el;
            c.SetElement(i,j,el);
        }
    return s;
}
ostream&operator<<(ostream&s,Matrix&c)
{
    int n,m;
    c.CountElements(n,m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            //s.precision(3);
            //s.setf(ios::fixed);
            s<<setw(7)<<c.GetElement(i,j);
            if(j==m-1 && i<n-1)
                s<<endl;
        }
    return s;
}
istream&operator>>(istream&s,Matrix*c)
{
    double el;
    int n,m;
    c->CountElements(n,m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            s>>el;
            c->SetElement(i,j,el);
        }
    return s;
}
ostream&operator<<(ostream&s,Matrix*c)
{
    int n,m;
    c->CountElements(n,m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            //s.precision(3);
            //s.setf(ios::fixed);
            s<<c->GetElement(i,j)<<" ";
            if(j==m-1 && i<n-1)
                s<<endl;
        }
    return s;
}
ifstream&operator>>(ifstream&s,Matrix&c)
{
    cout<<"HELLO1"<<endl;
    double el;
    int n,m;
    char eos='a';
    c.CountElements(n,m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            s>>el;
            c.SetElement(i,j,el);
            if(j==m-1)
                while(eos!='\n')
                {s>>eos;cout<<eos;}
        }
    return s;
}
ofstream&operator<<(ofstream&s,Matrix&c)
{
    int n,m;
    c.CountElements(n,m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            //s.precision(3);
            s.setf(ios::fixed);
            s<<setw(6)<<c.GetElement(i,j)<<" ";
            if(j==m-1 && i<n-1)
                s<<endl;
        }
    return s;
}
ifstream&operator>>(ifstream&s,Matrix*c)
{
    cout<<"HELLO2"<<endl;
    double el;
    int n,m;
    char eos='a';
    c->CountElements(n,m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            s>>el;
            c->SetElement(i,j,el);
            if(j==m-1)
                while(eos!='\n')
                {s>>eos;cout<<eos;}
        }
    return s;
}
ofstream&operator<<(ofstream&s,Matrix*c)
{
    int n,m;
    c->CountElements(n,m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            //s.precision(3);
            s.setf(ios::fixed);
            s<<setw(6)<<c->GetElement(i,j)<<" ";
            if(j==m-1 && i<n-1)
                s<<endl;
        }
    return s;
}
