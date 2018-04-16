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

     int r_new_for_c;
     int p_sum;
     int q_new_for_c;

     int r_c;
     int q_c;
     int nr_c;

     int carlier();
     int find_a();
     int find_b();
     int find_c();

     Carlier();
     ~Carlier();
};



#endif // CARLIER_H_INCLUDED
