#ifndef CARLIER_H_INCLUDED
#define CARLIER_H_INCLUDED

#include "Schrage.h"

using namespace std;


class Carlier : public Schrage
{
     public:
     Quest tab2[1000];
     int U;
     int UB;
     int LB;
     int a,b,c;


     int carlier(Carlier &car);
     int find_a(int &a, int &b);
     int find_b(int &b);
     int find_c(int a, int b);

     Carlier();
     ~Carlier();
};



#endif // CARLIER_H_INCLUDED
