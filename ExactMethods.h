#ifndef EXACTMETHODS_H_INCLUDED
#define EXACTMETHODS_H_INCLUDED
#include"Methods.h"

class ExactMethods:Methods
{
    public:
        ExactMethods(){};
        virtual Solution*Solve()=0;
        virtual~ExactMethods(){};
};

#endif // EXACTMETHODS_H_INCLUDED
