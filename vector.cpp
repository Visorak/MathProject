#include "vector.h"

//template <class Type>
Vector::Vector()
{
    //srand(time(0));
    N=10;
    vr=new double[N];
    for(int i=0;i<N;i++)
        vr[i]=0;
}
Vector::Vector(Vector&v)
{
    N=v.CountElements();
    vr=new double[N];
    for(int i=0;i<N;i++)
        vr[i]=v.GetElement(i);
}
//template <class Type>
Vector::Vector(int n)
{
    N=n;
    vr=new double[N];
    for(int i=0;i<N;i++)
        vr[i]=0;
}

Vector::Vector(int n,bool random)
{
    N=n;
    vr=new double[N];
    for(int i=0;i<N;i++)
        vr[i]=0;
}
Vector::Vector(int n,char*path)
{
    N=n;
    ifstream fin(path);
    vr=new double[N];
    for(int i=0;i<N;i++)
        fin>>vr[i];
}
Vector :: Vector(double*c,int n)
{
    N=n;
    vr=new double[N];
    for(int i=0;i<N;i++)
        vr[i]=c[i];
}
//template <class Type>
Vector :: ~Vector()
{
    //delete []vr;
    //vr=NULL;
}
//template <class Type>
Vector& Vector :: operator=(double constant)
{
    for(int i=0;i<N;i++)
        vr[i]=constant;
    return *this;
}
//template <class Type>
Vector&Vector :: operator=(const Vector&c)
{
    if(!Comparison(c))
        exit(777);
    double t;
    for(int i=0;i<N;i++)
        vr[i]=c.GetElement(i);
    return *this;
}
//template <class Type>
double Vector :: GetElement(int ei)const
{
    //cout << vr[ei] << endl;
    return vr[ei];
}
//template <class Type>
void Vector::SetElement(int ei,double d)
{
    vr[ei]=d;
    return;
}
//template <class Type>
int Vector::CountElements()const
{
    return N;
}
//template <class Type>
double Vector::Norm()const
{
    double t=0;
    for(int i=0;i<N;i++)
        t+=pow(vr[i],2);
    return sqrt(t);
}
double Vector::Norm(const Vector&c)const
{
    double t=0;
    for(int i=0;i<N;i++)
        t+=pow(c.GetElement(i),2);
    return sqrt(t);
}
//template <class Type>
bool Vector :: Comparison(const Vector&c)const
{
    if(N!=c.CountElements())
    {
        cout<<N<<" "<<c.CountElements()<<endl;
        cout<<"Vectors of different dimensions!"<<endl;
        return 0;
    }
    return 1;
}
//template <class Type>
Vector&Vector::operator+(const Vector&c)const
{
    if(!Comparison(c))
        exit(777);
    Vector &res=*(new Vector(N,0.));
    for(int i=0;i<N;i++)
        res.SetElement(i,vr[i]+c.GetElement(i));
    return res;
}
//template <class Type>
Vector&Vector::operator-(const Vector&c)const
{
    if(!Comparison(c))
        exit(777);
    Vector &res=*(new Vector(N,0.));
    for(int i=0;i<N;i++)
        res.SetElement(i,vr[i]-c.GetElement(i));
    return res;
}
//template <class Type>
double Vector :: operator*(const Vector&c)const
{
    if(!Comparison(c))
        return 1;
    double l=0;
    for(int i=0;i<N;i++)
        l+=vr[i]*c.GetElement(i);
    return l;
}
//template <class Type>
double Vector :: AngleBetweenVectors(const Vector&c)const
{
    if(!Comparison(c))
        return 1;
    int i;
    double t1=0,t2=0,a=0,cc;
    for(i=0;i<N;i++)
    {
        cc=c.GetElement(i);
        a+=vr[i]*cc;
        t1+=pow(vr[i],2);
        t2+=pow(cc,2);
    }
    return a/(sqrt(t1)*sqrt(t2));

}
//template <class Type>
/**Vector<Type>&Vector<Type> :: operator|(const Vector&c)
{
    Vector res(*y*(*c.z)-*z*(*c.y),*z*(*c.x)-*x*(*c.z),*x*(*c.y)-*y*(*c.x));
    return res;
}*/
//template <class Type>
Vector&Vector::operator+(double d)const
{
    Vector &res=*(new Vector(N,0.));
    for(int i=0;i<N;i++)
        res.SetElement(i,vr[i]+d);
    return res;
}
//template <class Type>
Vector&Vector :: operator-(double d)const
{
    Vector &res=*(new Vector(N,0.));
    for(int i=0;i<N;i++)
        res.SetElement(i,vr[i]-d);
    return res;
}
//template <class Type>
Vector&Vector :: operator*(double d)const
{
    Vector &res=*(new Vector(N,0.));
    for(int i=0;i<N;i++)
        res.SetElement(i,vr[i]*d);
    return res;
}
//template <class Type>
Vector&Vector::operator/(double d)const
{
    if(d==0 || d==0.0)
    {
        cout<<"Division by zero is forbidden!\a"<<endl;
        exit(777);
    }
    Vector &res=*(new Vector(N,0.));
    for(int i=0;i<N;i++)
        res.SetElement(i,vr[i]/d);
    return res;
}
bool Vector::MoveElement(int ei0,int ei)
{
    if(ei0<0 || ei<0 || ei0>=N || ei>=N)
        return 1;
    double a=vr[ei0];
    vr[ei0]=vr[ei];
    vr[ei]=a;
    return 0;
}
double Vector::operator[](int i)
{
    if(i>=0 && i<N)
        return vr[i];
    else
    {
        cout<<"Error index i!\a"<<endl;
        exit(0);
    }
}
//template <class Type>
istream&operator>>(istream&s,Vector&c)
{
    double el;
    bool b=0;
    for(int i=0;i<c.CountElements();i++)
    {
        s>>el;
        c.SetElement(i,el);
    }
    return s;
}
//template <class Type>
/*ostream&operator<<(ostream&s,Vector&c)
{
    s<<"(";
    for(int i=0;i<c.CountElements();i++)
    {
        s<<c.GetElement(i);
        if(i!=c.CountElements()-1)
            s<<",";
        else
            return s<<")";
    }
}*/
ostream&operator<<(ostream&s,Vector&c)
{
    for(int i=0;i<c.CountElements();i++)
    {
        s<<c.GetElement(i)<<" ";
    }
    return s;
}
istream&operator>>(istream&s,Vector*c)
{
    double el;
    bool b=0;
    for(int i=0;i<c->CountElements();i++)
    {
        s>>el;
        c->SetElement(i,el);
    }
    return s;
}
ostream&operator<<(ostream&s,Vector*c)
{
    for(int i=0;i<c->CountElements();i++)
    {
        s<<c->GetElement(i)<<" ";
    }
    return s;
    /*s<<"(";
    for(int i=0;i<c->CountElements();i++)
    {
        s<<c->GetElement(i);
        if(i!=c->CountElements()-1)
            s<<",";
        else
            return s<<")";
    }*/
}
