#include"MathComponents.h"
#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

class Solution
{
    private:
        int result;
        double sol1;
        Vector*sol2;
        Matrix*sol3;
    public:
        Solution(Matrix* S);
        Solution(Vector* S);
        Solution(double S);
        Matrix*ReturnResultMatrix();
        Vector*ReturnResultVector();
        double ReturnResultFigure();
        ~Solution();
        friend ofstream&operator<<(ofstream&s,Solution*sol);
        friend ostream&operator<<(ostream&s,Solution*sol);
};

#endif // SOLUTION_H_INCLUDED
