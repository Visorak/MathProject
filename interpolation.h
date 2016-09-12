#include"C:\VisoGor\MyMath.h"
#ifndef INTERPOLATION_H_INCLUDED
#define INTERPOLATION_H_INCLUDED
#include"SystemOfEquations.h"

class Interpolation: public Operations, public SystemOfEquations
{
    protected:
        Vector*x,*y,*IntPol;///����� �����; ������� �������� � ���� ������; ���������������� �������
        int N;///���������� �����
        int A,B;///������/����� �������
        double H;///��� ����� �������
    public:
        Interpolation(double (*fX)(double),int a,int b);
        Interpolation(double (*fX)(double),int a,double h,int n);
        Interpolation(double (*fX)(double),Vector*s,int n);
        virtual Vector&SolveInterpolant(int l)=0;
        virtual~Interpolation();
    /** fX
        s - ����� �����
        n - ���������� ����� �� �������
        a - ������ �������
        b - ����� �������
        l - ������� ������������
    */
};

#endif // INTERPOLATION_H_INCLUDED

class interpolation
{
public:
	interpolation();
	~interpolation();
};
