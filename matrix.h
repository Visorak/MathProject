#include"Vector.h"
#include<iostream>
#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

class Matrix
{
    private:
        bool Determin,Maximum,Minimum;
        int N,M;
        double **coeffs,Det,Max,Min,h;
        double PublicDeterminate(int n,double**c);///определитель для двумерного массива
        double**mx;
    public:
        Matrix();
        Matrix(Matrix&a);
        Matrix(int n,int m);
        Matrix(int n);
        Matrix(int n,int m,bool random);
        Matrix(int n,int m,char*path);
        Matrix(int n,int m,double h,char*path);
        Matrix(int n,int m,double hh);
        Matrix(double**c,int n,int m);
        Matrix(double**c,int n,int m,double hh);
        ~Matrix();
        Matrix&operator=(double**c);
        Matrix&operator=(Matrix&c);
        Matrix&operator=(Matrix*c);
        Matrix&operator=(double d);
        bool Squere();
        double GetElement(int ei,int ej)const;///получить элемент
        double GE(int ei,int ej)const{return this->GetElement(ei,ej);}///получить элемент
        void SetElement(int ei,int ej,double d);///задать элемент
        void SE(int ei,int ej,double d){this->SetElement(ei,ej,d);};///задать элемент
        bool SetMatrix(Vector**v,char coast);///задать матрицу из массива векторов
        int CountElements(int &n,int &m)const;///количество элементов и размерность матрицы
        bool WhatIndex(int i,int j)const;///проверка допустимости индексов
        void H(double h){this->h=h;}///задать шаг;
        double H(){return h;}///какой шаг;
        double Norm()const;///Норма матрицы
        double NormMax()const;///Норма матрицы
        double NormSqrt()const;///Норма матрицы
        double Norm(double**c,int n,int m,double h)const;///норма двумерного массива
        bool Comparison (const Matrix&c)const;///сравнение размерностей матриц
        bool IsSimmetrial();///Проверка на симметричность
        Matrix&operator+(const Matrix&c)const;///сумма матриц
        Matrix&operator-(const Matrix&c)const;///разность матриц
        Matrix&operator*(const Matrix&c)const;///векторное произведение матриц
        double operator%(const Matrix*c)const;///скалярное произведение матриц(1)
        double operator%(const Matrix&c)const;///скалярное произведение матриц(2)
        double Skalyar(const Matrix*c)const;
        Vector&operator*(const Vector&c)const;///умножение матрицы на вектор
        Matrix&operator+(double d)const;///сумма матрицы и числа
        Matrix&operator-(double d)const;///разность матрицы и числа
        Matrix&operator*(double d)const;///произведение матрицы и числа
        Matrix&operator/(double d)const;///деление матрицы на число
        Matrix&operator!()const;///Транспонирование матрицы
        Matrix&Reverse()const;///Обратная матрица(метод Гаусса)
        //Matrix&Reverse(Matrix&c);///Обратная матрица(через миноры)
        void Transposition();///Транспонирование матрицы класса
        double DeterminateToMinors();///вычислить определитель через миноры матрицы
        double DeterminateToGauss();///вычислить определитель методом Гаусса
        double Determinate();///вычислить определитель(методом Гаусса)
        int Rotation(double eps);///вращение матрицы для определения собственных значений и векторов
        bool EigenValues(Vector&ei,double eps);///собственные вектора и значения(для сим. матрицы), реализовано методом Якоби(вращение матрицы)
        double EigenValue(int m);///максимальное собственное значение(итерационный метод)
        Matrix&ApproximateMatrix();///приближенная матрица
        double MaxElement(int&ei,int&ej);///максимальный элемент матрицы
        double MaxElementString(int ei,int&ej);///максимальный элемент строки
        double MaxElementStringFrom(int ei,int from,int&ej);///максимальный элемент строки начиная с...
        double MaxElementColumn(int ej,int&ei);///максимальный элемент столбца
        double MaxElementColumnFrom(int ej,int from,int&ei);///максимальный элемент столбца начиная с...
        double MinElement(int&ei,int&ej);///минимальный элемент матрицы
        double MinElementString(int ei,int&ej);///минимальный элемент строки
        double MinElementStringFrom(int ei,int from,int&ej);///минимальный элемент строки начиная с...
        double MinElementColumn(int ej,int&ei);///минимальный элемент столбца
        double MinElementColumnFrom(int ej,int from,int&ei);///минимальный элемент столбца начиная с...
        double SetString(int ei,Vector*v);///задать строку
        double SetColumn(int ej,Vector*v);///задать столбец
        void CopyBoundCond(Matrix*mat);
        const double*operator[](int i)const;
        double*operator[](int j);
        double operator()(int i,int j);
        bool FindElement(int&ei,int&ej,double d);///найти элемент матрицы
        bool MoveString(int ei0,int ei);///поменять строки местами
        bool MoveColumn(int ej0,int ej);///поменять столбцы местами
        bool MoveElement(int ei0,int ej0,int ei,int ej);
        bool Flip(char t);
        //bool MultOfString(int ei, double d);///умножение строки на число
        //bool MultOfColumn(int ej, double d);///умножение столбца на число
        friend istream&operator>>(istream&s,Matrix&mat);
        friend ostream&operator<<(ostream&s,Matrix&mat);
        friend istream&operator>>(istream&s,Matrix*mat);
        friend ostream&operator<<(ostream&s,Matrix*mat);
        friend ifstream&operator>>(ifstream&s,Matrix&mat);
        friend ofstream&operator<<(ofstream&s,Matrix&mat);
        friend ifstream&operator>>(ifstream&s,Matrix*mat);
        friend ofstream&operator<<(ofstream&s,Matrix*mat);
        void ResetProperties(bool D,bool first,bool sup,bool inf);///обнулить свойства матрицы(определитель, вернуть первоначальную, максимум, минимум)
        void IdentityMatrix();///единичная матрица
        Matrix&ConversionInClass(double**c);///конвертирование двумерного массива в класс
        void ConversionInStandart(double**c);///конвертирование класса в двумерный массив
};
#endif // MATRIX_H_INCLUDED
