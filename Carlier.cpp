#include "Carlier.h"

using namespace std;

Carlier::Carlier() {}
Carlier::~Carlier() {}

int Carlier::carlier(Carlier &car)
{
     a=0;b=0,c=-1;
     U=0;
     UB=INT_MAX;
     LB=0;

     int r_new_for_c=INT_MAX;
     int p_sum=0;
     int q_new_for_c=INT_MAX;
     int r_c=0;
     int q_c=0;
     int nr_c=0;
     int i=0;

     car.U = car.Schrage_without();

     if(car.U < car.UB)
     {
          car.UB = car.U;
		for (i = 0; i < number_of_tasks; i++)
		{
			car.tab2[i] = car.tab[i];
		}
     }

     a = car.find_a(a,b);
     b = car.find_b(b);
     c = car.find_c(a,b);

     if(c==-1)
     {
          return car.U;
     }

     for(i=c+1; i<=b; i++)
     {
          r_new_for_c = min(r_new_for_c, car.tab[i].r);
          q_new_for_c = min(q_new_for_c, car.tab[i].q);
          p_sum+= tab[i].p;
     }


          nr_c = car.tab[c].task_number;
          r_c = car.tab[c].r;


     car.tab[c].r = max(car.tab[c].r, r_new_for_c + p_sum);

     LB= car.Schrage_with();

     if(LB < car.UB)
     {
         car.UB=car.carlier(car);
     }
     for (i = 0; i < number_of_tasks; i++)
	{
		if (nr_c == car.tab[i].task_number)
			car.tab[i].r = r_c;
	}

          q_c = tab[c].q;


	car.tab[c].q= max(car.tab[c].q, q_new_for_c + p_sum);

     LB = car.Schrage_with();

     if(LB < car.UB)
     {
          U = car.carlier(car);
     }

     for(i=0; i<number_of_tasks; i++)
     {
          if(nr_c == car.tab[i].task_number)
          {
               car.tab[i].q = q_c;
          }
     }

     return car.U;
}

int Carlier::find_a(int &a, int &b)
{
     int sum = 0;
     int i;

     for(a=0; a<b; a++)
     {
          for(i=a; i<=b; i++)
          {
               sum += tab[i].p;
          }
          if(Cmax_without == tab[a].r + sum + tab[b].q)
          {
               return a;
          }
     }
     return a;
}


int Carlier::find_b(int &b)
{
     int i=0;
     b=0;
     for(i=number_of_tasks-1; i>0; i--)
     {
          if(Cmax_without == tab[i].C + tab[i].q)
          {
               b=i;
               break;
          }
     }
     return b;
}

int Carlier::find_c(int a, int b)
{
     c=-1;
     int i;
     for(i=b; i>=a; i--)
     {
          if(tab[i].q < tab[b].q)
          {
               c=i;
               break;
          }
     }

     return c;
}



