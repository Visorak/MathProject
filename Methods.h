//#include"C:\VisoGor\MyMath.h"
#ifndef METHODS_H_INCLUDED
#define METHODS_H_INCLUDED
#include"Solution.h"

class Methods
{
    public:
        Methods(){};
        virtual Solution*Solve()=0;
        virtual ~Methods(){};
};
#endif // METHODS_H_INCLUDED
