#ifndef DE_H
#define DE_H

#include "../include/Rand.h"

class De
{
    public:
        //De();
        unsigned int valeur(void) const { return value ; } ;
        unsigned int lance(void)  {
        return value = Rand(6) ;} ;
        De(void) { lance(); };
    protected:
    private:
        unsigned int value = lance() ;
};

#endif // DE_H
