#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

/*class Matrix;
class Vector;*/
#include"C:\VisoGor\MyMath.h"
class SystemOfEquations;
class Operations
{
    private:
        enum WayIntegration{Trapezoid=1,Simpson=2,Int3D8=3,Gauss=4};
        double der(double **u,int i,int j,double h);///�����������

        double IntegrationTrapezoid(double*y,double h,int n);
        double RatingTrapezoid(double *x,double h,int n,double b,double a,double (*eq2)(double));
        double IntegrationSimpson(double*y,double h,int n);
        double RatingSimpson(double *x,double h,int n,double b,double a,double (*eq4)(double));
        double Integration3D8(double*y,double h,int n);
        double Rating3D8(double *x,double h,int n,double b,double a,double (*eq4)(double));
        double IntegrationGauss(double a,double b,double (*eq)(double));
        double IntegrationLeftRectangle(double*y,double h,int n);
        double RatingLeftRectangle(double *x,double h,int n,double b,double a,double (*eq1)(double));
        double IntegrationRightRectangle(double*y,double h,int n);
        double RatingRightRectangle(double *x,double h,int n,double b,double a,double (*eq1)(double));
        double IntegrationCentralRectangle(double*y,double h,int n);
        double RatingCentralRectangle(double *x,double h,int n,double b,double a,double (*eq2)(double));
        double ratingIntegration; bool marker;

        SystemOfEquations*func;
    public:
        Operations(){marker=false;};
        Operations(double (*eq)(double,double));
        Operations(double (*eq)(double));

        double DerivativePoint(double**u,int i,int j,int dN,double h,int n,int m);///������� ����������� dN-�� �������(��������� ������)
        double DerivativePoint(Matrix*u,int i,int j,int dN,double h);///������� ����������� dN-�� �������(�����)
        void DerivativeMatrix(double**u,double**du,int dN,double h,int n,int m);
        double DerivativeBorder(double X,double*x,double*y,int n);

        double Integration(double a,double b,int n,double (*eq)(double),double (*eqd)(double),int WI);
        //double Integration(double a,double b,double (*eq)(double),double (*eqd)(double));
        double RatingIntegration();
        //double Integration(double a,double b,Function*eq,WayIntegration WI);
        //double Integration(double a,double b,Function*eq);

        //double Evalf(Matrix*u,int i,int j,int dN,double h);
        double A(double**u,int i,int j,double h);///�������� ��������(������� ������ ����������)
        double Norm(int n,int m,double**rn,double h);///����� �������
        /*template <int n, int m>
        double Norm(double (&rn)[n][m],double h);*/

        double DerivativePoint(double*u,int i,int dN,double h);///������ ����������� dN-�� �������(��������� ������)
        double DerivativePoint(Vector*u,int i,int dN,double h);///������ ����������� dN-�� �������(�����)

        virtual~Operations(){};
};

#endif // OPERATIONS_H_INCLUDED
