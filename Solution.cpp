#include"Solution.h"
#include"Matrix.h"
#include"Vector.h"
#include<stdio.h>
#include<windows.h>

Solution::Solution(Matrix*S)
{
    sol3=new Matrix(*S);
    result=3;
}
Solution::Solution(Vector* S)
{
    sol2=new Vector(*S);
    result=2;
}
Solution::Solution(double S)
{
    sol1=S;
    result=1;
}
Matrix*Solution::ReturnResultMatrix()
{
    if(result=3)
        return sol3;
    else
    {
        printf("Wrong data type!\a");
        exit(0);
    }
}
Vector*Solution::ReturnResultVector()
{
    if(result=2)
        return sol2;
    else
    {
        printf("Wrong data type!\a");
        exit(0);
    }
}
double Solution::ReturnResultFigure()
{
    if(result=1)
        return sol1;
    else
    {
        printf("Wrong data type!\a");
        exit(0);
    }
}
Solution::~Solution()
{
    if(result=1)
        sol1=NULL;
    if(result=2)
    {
        delete sol2;
        sol2=NULL;
    }
    if(result=3)
    {
        delete sol3;
        sol3=NULL;
    }
    result=NULL;
}
ostream&operator<<(ostream&s,Solution*sol)
{
    if(sol->result==1)
        s<<sol->sol1;
    if(sol->result==2)
        s<<sol->sol2;
    if(sol->result==3)
        s<<sol->sol3;
    return s;
}
ofstream&operator<<(ofstream&s,Solution*sol)
{
    if(sol->result==1)
        s<<sol->sol1;
    if(sol->result==2)
        s<<sol->sol2;
    if(sol->result==3)
        s<<sol->sol3;
    return s;
}
