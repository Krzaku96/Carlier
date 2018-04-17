#include "Carlier.h"

using namespace std;

Carlier::Carlier() {}
Carlier::~Carlier() {}

int Carlier::carlier()
{
     U=0;
     UB=INT_MAX;
     LB=0;
     a=0,b=0,c=-1;
     int r_new_for_c=INT_MAX;
     int p_sum=0;
     int q_new_for_c=INT_MAX;
     int r_c=0;
     int q_c=0;
     int nr_c=0;
     int i=0;

     U = Schrage_without();

     if(U < UB)
     {
          UB = U;
		for (i = 0; i < number_of_tasks; i++)
		{
			tab2[i] = tab[i];
		}
     }

     a = find_a();
     b = find_b();
     c = find_c();

     if(c==-1)
     {
          return U;
     }

     for(i=c+1; i<=b; i++)
     {
          r_new_for_c = min(r_new_for_c, tab[i].r);
          q_new_for_c = min(q_new_for_c, tab[i].q);
          p_sum+= tab[i].p;
     }


          nr_c = tab[c].task_number;
          r_c = tab[c].r;


     tab[c].r = max(tab[c].r, r_new_for_c + p_sum);

     LB= Schrage_with();

     if(LB < UB)
     {
         UB=carlier();
     }
     for (i = 0; i < number_of_tasks; i++)
	{
		if (nr_c == tab[i].task_number)
			tab[i].r = r_c;
	}

          q_c = tab[c].q;


	tab[c].q= max(tab[c].q, q_new_for_c + p_sum);

     LB = Schrage_with();

     if(LB < UB)
     {
          U = carlier();
     }

     for(i=0; i<number_of_tasks; i++)
     {
          if(nr_c == tab[i].task_number)
          {
               tab[i].q = q_c;
          }
     }

     return U;
}

int Carlier::find_a()
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


int Carlier::find_b()
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

int Carlier::find_c()
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



