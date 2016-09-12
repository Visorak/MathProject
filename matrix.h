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
        double PublicDeterminate(int n,double**c);///������������ ��� ���������� �������
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
        double GetElement(int ei,int ej)const;///�������� �������
        double GE(int ei,int ej)const{return this->GetElement(ei,ej);}///�������� �������
        void SetElement(int ei,int ej,double d);///������ �������
        void SE(int ei,int ej,double d){this->SetElement(ei,ej,d);};///������ �������
        bool SetMatrix(Vector**v,char coast);///������ ������� �� ������� ��������
        int CountElements(int &n,int &m)const;///���������� ��������� � ����������� �������
        bool WhatIndex(int i,int j)const;///�������� ������������ ��������
        void H(double h){this->h=h;}///������ ���;
        double H(){return h;}///����� ���;
        double Norm()const;///����� �������
        double NormMax()const;///����� �������
        double NormSqrt()const;///����� �������
        double Norm(double**c,int n,int m,double h)const;///����� ���������� �������
        bool Comparison (const Matrix&c)const;///��������� ������������ ������
        bool IsSimmetrial();///�������� �� ��������������
        Matrix&operator+(const Matrix&c)const;///����� ������
        Matrix&operator-(const Matrix&c)const;///�������� ������
        Matrix&operator*(const Matrix&c)const;///��������� ������������ ������
        double operator%(const Matrix*c)const;///��������� ������������ ������(1)
        double operator%(const Matrix&c)const;///��������� ������������ ������(2)
        double Skalyar(const Matrix*c)const;
        Vector&operator*(const Vector&c)const;///��������� ������� �� ������
        Matrix&operator+(double d)const;///����� ������� � �����
        Matrix&operator-(double d)const;///�������� ������� � �����
        Matrix&operator*(double d)const;///������������ ������� � �����
        Matrix&operator/(double d)const;///������� ������� �� �����
        Matrix&operator!()const;///���������������� �������
        Matrix&Reverse()const;///�������� �������(����� ������)
        //Matrix&Reverse(Matrix&c);///�������� �������(����� ������)
        void Transposition();///���������������� ������� ������
        double DeterminateToMinors();///��������� ������������ ����� ������ �������
        double DeterminateToGauss();///��������� ������������ ������� ������
        double Determinate();///��������� ������������(������� ������)
        int Rotation(double eps);///�������� ������� ��� ����������� ����������� �������� � ��������
        bool EigenValues(Vector&ei,double eps);///����������� ������� � ��������(��� ���. �������), ����������� ������� �����(�������� �������)
        double EigenValue(int m);///������������ ����������� ��������(������������ �����)
        Matrix&ApproximateMatrix();///������������ �������
        double MaxElement(int&ei,int&ej);///������������ ������� �������
        double MaxElementString(int ei,int&ej);///������������ ������� ������
        double MaxElementStringFrom(int ei,int from,int&ej);///������������ ������� ������ ������� �...
        double MaxElementColumn(int ej,int&ei);///������������ ������� �������
        double MaxElementColumnFrom(int ej,int from,int&ei);///������������ ������� ������� ������� �...
        double MinElement(int&ei,int&ej);///����������� ������� �������
        double MinElementString(int ei,int&ej);///����������� ������� ������
        double MinElementStringFrom(int ei,int from,int&ej);///����������� ������� ������ ������� �...
        double MinElementColumn(int ej,int&ei);///����������� ������� �������
        double MinElementColumnFrom(int ej,int from,int&ei);///����������� ������� ������� ������� �...
        double SetString(int ei,Vector*v);///������ ������
        double SetColumn(int ej,Vector*v);///������ �������
        void CopyBoundCond(Matrix*mat);
        const double*operator[](int i)const;
        double*operator[](int j);
        double operator()(int i,int j);
        bool FindElement(int&ei,int&ej,double d);///����� ������� �������
        bool MoveString(int ei0,int ei);///�������� ������ �������
        bool MoveColumn(int ej0,int ej);///�������� ������� �������
        bool MoveElement(int ei0,int ej0,int ei,int ej);
        bool Flip(char t);
        //bool MultOfString(int ei, double d);///��������� ������ �� �����
        //bool MultOfColumn(int ej, double d);///��������� ������� �� �����
        friend istream&operator>>(istream&s,Matrix&mat);
        friend ostream&operator<<(ostream&s,Matrix&mat);
        friend istream&operator>>(istream&s,Matrix*mat);
        friend ostream&operator<<(ostream&s,Matrix*mat);
        friend ifstream&operator>>(ifstream&s,Matrix&mat);
        friend ofstream&operator<<(ofstream&s,Matrix&mat);
        friend ifstream&operator>>(ifstream&s,Matrix*mat);
        friend ofstream&operator<<(ofstream&s,Matrix*mat);
        void ResetProperties(bool D,bool first,bool sup,bool inf);///�������� �������� �������(������������, ������� ��������������, ��������, �������)
        void IdentityMatrix();///��������� �������
        Matrix&ConversionInClass(double**c);///��������������� ���������� ������� � �����
        void ConversionInStandart(double**c);///��������������� ������ � ��������� ������
};
#endif // MATRIX_H_INCLUDED
