//#include"C:\VisoGor\MyMath.h"
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

//template <class double>
class Vector
{
    private:
        int N;
        double*vr,h;
    public:
        Vector();
        Vector(Vector&v);
        Vector(int n);
        Vector(int n,bool random);
        Vector(int n,char*path);
        Vector(double*c,int n);
        ~Vector();
        Vector&operator=(double constant);
        Vector&operator=(const Vector&c);
        double H(){return h;}///����� ���;
        double GetElement(int ei)const;///�������� �������
        void SetElement(int ei,double d);///������ �������
        int CountElements()const;///���������� ���������
        double Norm()const;///����� �������
        double Norm(const Vector&c)const;///����� �������
        bool Comparison (const Vector&c)const;///��������� ��������
        Vector&operator+(const Vector&c)const;///����� ��������
        Vector&operator-(const Vector&c)const;///�������� ��������
        double operator*(const Vector&c)const;///������������ ��������
        double AngleBetweenVectors(const Vector&c)const;///���� ����� ���������
        Vector&operator+(double d)const;///����� ������� � �����
        Vector&operator-(double d)const;///�������� ������� � �����
        Vector&operator*(double d)const;///��������� ������� �� �����
        Vector&operator/(double d)const;///������� ������ �� �����
        ///double MaxElement(int&ei);///������������ ������� � �������
        ///double MinElement(int&ei);///����������� ������� � �������
        bool MoveElement(int ei0,int ei);
        ///bool FindElement(int&ei,double d);///����� �������� � �������
        double operator[](int i);
        friend istream&operator>>(istream&s,Vector&c);
        friend ostream&operator<<(ostream&s,Vector&c);
        friend istream&operator>>(istream&s,Vector*c);
        friend ostream&operator<<(ostream&s,Vector*c);
};

#endif // VECTOR_H_INCLUDED
