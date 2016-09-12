#include"C:\VisoGor\MyMath.h"
#ifndef INTERPOLATION_H_INCLUDED
#define INTERPOLATION_H_INCLUDED
#include"SystemOfEquations.h"

class Interpolation: public Operations, public SystemOfEquations
{
    protected:
        Vector*x,*y,*IntPol;///набор точек; знчения функиции в этих точках; интерполяционный полином
        int N;///количество точек
        int A,B;///начало/конец отрезка
        double H;///шаг между точками
    public:
        Interpolation(double (*fX)(double),int a,int b);
        Interpolation(double (*fX)(double),int a,double h,int n);
        Interpolation(double (*fX)(double),Vector*s,int n);
        virtual Vector&SolveInterpolant(int l)=0;
        virtual~Interpolation();
    /** fX
        s - набор точек
        n - количество точек на отрезке
        a - начало отрезка
        b - конец отрезка
        l - степень интерполянты
    */
};

#endif // INTERPOLATION_H_INCLUDED

class interpolation
{
public:
	interpolation();
	~interpolation();
};
