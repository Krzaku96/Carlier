#include "Carlier.h"

using namespace std;

Carlier::Carlier() {}
Carlier::~Carlier() {}



int Carlier::carlier()
{
     int n;
     U = Schrage_without();

     if(U < UB)
     {
          UB = U;
		for (int i = 0; i < n; i++)
		{
			tab2[i] = tab[i];
		}
     find_a();
     find_b();
     find_c();
     }
     if(c==0)
     {
          return U;
     }

     for(int i=c+1; i<b; i++)
     {
          r_new_for_c = min(r_new_for_c, tab[i].r);
          q_new_for_c = min(q_new_for_c, tab[i].q);
          p_sum+= tab[i].p;
     }

     tab[c].r = max(tab[c].r, r_new_for_c + p_sum);

     LB= Schrage_with();

     if(LB < UB)
     {
         UB=carlier();
     }
     for (int i = 0; i < n; i++)
	{
		if (nr_c == tab[i].task_number)
			tab[i].r = r_c;
	}

	tab[c].q= max(tab[c].q, q_new_for_c + p_sum);

     LB = Schrage_with();

     if(LB < UB)
     {
          UB = carlier();
     }

     for(int i=0; i<n; i++)
     {
          if(nr_c == tab[i].task_number)
          {
               tab[i].q = q_new_for_c;
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
     int n;
     for(int i=n-1; i>0; i--)
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
     for(int i=b; i>=a; i--)
     {
          if(tab[i].q < tab[b].q)
          {
               c=i;
               break;
          }
     }
     return c;
}


