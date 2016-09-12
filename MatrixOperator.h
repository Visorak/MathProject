#include"C:\VisoGor\MyMath.h"
#ifndef MATRIXOPERATOR_H_INCLUDED
#define MATRIXOPERATOR_H_INCLUDED
//#include"SystemOfEquations.h"

class MatrixOperator:public SystemOfEquations//,public Operations
{
    private:
        Vector*F,*X;
        Matrix*A;
    public:
        MatrixOperator(Matrix*a,Vector*x);
        virtual void MBoundaryConditions(double a,double al1,double al2,double b,double gm1,double bt1,double bt2,double gm2);
        virtual double Operator(Matrix*A,int i);///��������� ��������
        virtual double Operator(Vector*x,int i);///��������� ��������
        virtual double Operator(Matrix*A,int i,int j,double h);///��������� ��������
        virtual Matrix&InputMatrix();///��������� �������
        virtual void CountElements(int&n,int&m);
        virtual Vector&Result();///�������������� ������
        virtual Vector&Solution();///�������������� ������
        virtual~MatrixOperator();
    /** eq - ������� (��������: sin(x)+x)
    */
};

#endif // MATRIXOPERATOR_H_INCLUDED
