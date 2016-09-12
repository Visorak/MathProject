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
        double H(){return h;}///какой шаг;
        double GetElement(int ei)const;///получить элемент
        void SetElement(int ei,double d);///задать элемент
        int CountElements()const;///количество элементов
        double Norm()const;///норма вектора
        double Norm(const Vector&c)const;///норма вектора
        bool Comparison (const Vector&c)const;///сравнение векторов
        Vector&operator+(const Vector&c)const;///сумма векторов
        Vector&operator-(const Vector&c)const;///разность векторов
        double operator*(const Vector&c)const;///произведение векторов
        double AngleBetweenVectors(const Vector&c)const;///угол между векторами
        Vector&operator+(double d)const;///сумма вектора и числа
        Vector&operator-(double d)const;///разность вектора и числа
        Vector&operator*(double d)const;///умножение вектора на число
        Vector&operator/(double d)const;///деление ветора на число
        ///double MaxElement(int&ei);///максимальный элемент в векторе
        ///double MinElement(int&ei);///минимальный элемент в векторе
        bool MoveElement(int ei0,int ei);
        ///bool FindElement(int&ei,double d);///поиск элемента в векторе
        double operator[](int i);
        friend istream&operator>>(istream&s,Vector&c);
        friend ostream&operator<<(ostream&s,Vector&c);
        friend istream&operator>>(istream&s,Vector*c);
        friend ostream&operator<<(ostream&s,Vector*c);
};

#endif // VECTOR_H_INCLUDED
