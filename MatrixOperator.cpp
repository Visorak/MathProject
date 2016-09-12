#include"MatrixOperator.h"

MatrixOperator::MatrixOperator(Matrix*a,Vector*f):SystemOfEquations()
{
    dimension=2;
    F=new Vector(*f);
    A=new Matrix(*a);
    X=new Vector(*f);
    *X=0;
    /*F=new Vector(X->CountElements(),0.);
    *F=*A*(*X);*/
}
void MatrixOperator::MBoundaryConditions(double a,double al1,double al2,double gm1,double b,double bt1,double bt2,double gm2)
{

}
Matrix&MatrixOperator::InputMatrix()
{
    return*A;
}
double MatrixOperator::Operator(Matrix*a,int i,int j,double h)
{
    return Operator(a,i);
}
double MatrixOperator::Operator(Matrix*a,int i)
{
    return F->GetElement(i);
}
double MatrixOperator::Operator(Vector*x,int i)
{
    return F->GetElement(i);
}
Vector&MatrixOperator::Result()
{
    return *F;
}
Vector&MatrixOperator::Solution()
{
    return *X;
}
void MatrixOperator::CountElements(int&n,int&m)
{
    A->CountElements(n,m);
    return;
}
MatrixOperator::~MatrixOperator()
{
    delete F;
    delete A;
    delete X;
    F=NULL;
    A=NULL;
    X=NULL;
}
