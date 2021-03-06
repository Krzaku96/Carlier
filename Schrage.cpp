#include "Schrage.h"
#include "Carlier.h"

using namespace std;

int Schrage::Schrage_with()
{
//	int number_of_tasks;
	int Cmax=0;
	int t=0;
	number_of_tasks=tab[0].r;
	tab[0].r=0;
	Quest l,e; //aktualnie wykonywane zadanie

  	l.q=1000;
	for (int i=1; i<number_of_tasks; i++)
	{
		N.push(tab[i]);
	}

	while(!G.empty() || !N.empty())
   {
		while (!N.empty() && N.top().r<=t)
		{
		     e=N.top();
		     G.push(e); // zadanie zaczyna si� wykonywa�
		     N.pop();
               if(e.q > l.q)
               {
                    l.p=t-e.r;
                    t=e.r;
                    if(l.p > 0)
                    {
                         G.push(l);
                    }
               }
		}

		if(G.empty())
			t=N.top().r;
		else
		{
		    e=G.top();
		    G.pop();
		    l=e;
			t=t+e.p;
			Cmax=max(Cmax, t+e.q);
		}
		Cmax_with = Cmax;
   }
	return Cmax;
}

int Schrage::Schrage_without()
{

	//int number_of_tasks;
	int Cmax=0;
	int t=0;
//	int k=0;
	number_of_tasks=tab[0].r;
	tab[0].r=0;

	for (int i=1; i<number_of_tasks; i++)
	{
		N.push(tab[i]);
	}
	while(!G.empty() || !N.empty())
	{
		while (!N.empty() && N.top().r<=t)
		{
			G.push(N.top());
			N.pop();
		}
		if(G.empty())
			t=N.top().r;
		else
		{

			t=t+G.top().p;
			Cmax=max(Cmax, t+G.top().q);
			G.pop();
		}
		Cmax_without = Cmax;
	}
	return Cmax;
}

bool Schrage::Read()
{
	ifstream file;
	file.open( "SCHRAGE9.DAT", ios::in);
     int n;
	file >> n;
	number_of_tasks=n+1;
	for(int i=1;i<=n;i++)
	    file >> tab[i];
	file.close();
	tab[0].r=number_of_tasks;
	return true;
}

void Schrage::Sort()
{
	for( int i = 0; i < number_of_tasks; i++ )
		for(int j=0; j<number_of_tasks-1; j++)
			if( tab[j].r > tab[j+1].r )
				swap(tab[j], tab[j+1]);
}

void Schrage::Display()
{
	for(int i=1;i<number_of_tasks;i++)
		cout << tab[i];
}

Schrage::Schrage(){}
Schrage::~Schrage() {}
