//#include"C:\VisoGor\MyMath.h"
#ifndef FUNCTIONLAPLAS_H_INCLUDED
#define FUNCTIONLAPLAS_H_INCLUDED
#include"SystemOfEquations.h"
#include"Operations.h"

class FunctionLaplas:public SystemOfEquations,public Operations
{
    private:
        Matrix*u;

    public:
        FunctionLaplas(Matrix*a,double (*eq)(double,double),int n,int m);
        FunctionLaplas(Matrix*a,double (*eq)(double),int n);

        FunctionLaplas(double (*eq)(double,double),int n,int m,double h);
        FunctionLaplas(Matrix*a);
        FunctionLaplas(Matrix*a,Matrix*bc);

        FunctionLaplas(double (*eq)(double),int n,double h);
        virtual ~FunctionLaplas(){delete u;};

        virtual Matrix&Operator(Matrix*u);///оператор Лапласса
        double Operator(double**u,int i,int j,double h);

        void CountElements(int&n,int&m,int&l){n=N;m=M;l=L;}
        void CountElements(int&n,int&m){n=N;m=M;}
        void CountElements(int&n){n=N;}

        virtual Matrix&InputMatrix();
        //virtual void MBoundaryConditions(double a,double b);
    /** eq - функция (например: sin(x)+x)
    */
};

#endif // FUNCTIONLAPLAS_H_INCLUDED
