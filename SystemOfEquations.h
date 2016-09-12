#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include<stdio.h>

class Matrix;
class Vector;
class SystemOfEquations
{
    protected:
        int marker;
        int N,M,L;
        double h;
        int dimension;
        Matrix*F,*BC;
    public:
        double H(){return h;};
        int Dimension(){return dimension;};
        double (*FunctionOfXYZ)(double,double,double);///функция точного решения зависящая от трёх переменных
        double (*FunctionOfXY)(double,double);///функция точного решения зависящая от двух переменных
        double (*FunctionOfX)(double);///функция точного решения зависящая от одной переменной
        SystemOfEquations(){dimension=0;};
        SystemOfEquations(double (*eq)(double,double,double),int n,int m,int l,double h);
        SystemOfEquations(double (*eq)(double,double),int n,int m,double h);
        SystemOfEquations(double (*eq)(double),int n,double h);
        SystemOfEquations(Matrix*a);
        SystemOfEquations(Matrix*a,Matrix*bc);
        virtual void RightPart(Matrix*A);
        virtual void RightPart(Vector*A){};
        virtual void BoundaryConditions(Matrix*bc);
        /*Function(double (*eq)(double,double));
        Function(double (*eq)(double));*/
        virtual void CountElements(int&n,int&m,int&l){n=N;m=M;l=L;}
        virtual void CountElements(int&n,int&m){n=N;m=M;}
        virtual void CountElements(int&n){n=N;}
        virtual double Operator(Matrix*u,int i,int j,double h){};
        virtual Matrix&Operator(Matrix*u){};
        virtual double Operator(Vector*x,int i){};
        virtual Vector&Result(){};
        virtual Vector&Solution(){};
        virtual Matrix&InputMatrix(){};
        virtual ~SystemOfEquations(){if(marker==1){delete F;delete BC;}/*printf("Errorrrrrrrrr1!\n");*/};
    /** eq - функция (например: sin(x)+x)
    */
};
#endif // FUNCTION_H_INCLUDED
