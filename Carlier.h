#ifndef CARLIER_H_INCLUDED
#define CARLIER_H_INCLUDED

#include "Schrage.h"

using namespace std;


class Carlier : public Schrage
{
     public:
     Carlier();
     ~Carlier();
     Quest tab2[3000];
     int U;
     int UB;
     int LB;
     int a,b,c;


     int carlier();
     int find_a();
     int find_b();
     int find_c();


};



#endif // CARLIER_H_INCLUDED
