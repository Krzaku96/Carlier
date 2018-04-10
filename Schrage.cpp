#include "Schrage.h"

using namespace std;

int Schrage::Schrage_with(int n)
{
	int number_of_tasks;
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
		     G.push(e); // zadanie zaczyna siê wykonywaæ
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
   }
return Cmax;
}

int Schrage::Schrage_without(int n)
{

	int number_of_tasks;
	int Cmax=0;
	int t=0;
	int k=0;
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
	}
	return Cmax;
}

bool Schrage::Read(int n, int number_of_tasks)
{
	ifstream file;
	file.open( "SCHRAGE1.DAT", ios::in);
	file >> n;
//	tab=new Quest[n+1];
	number_of_tasks=n+1;
	for(int i=1;i<=n;i++)
	    file >> tab[i];
	file.close();
	tab[0].r=number_of_tasks;
	return true;
}

int Schrage::Sort(int number_of_tasks)
{
	for( int i = 0; i < number_of_tasks; i++ )
		for(int j=0; j<number_of_tasks-1; j++)
			if( tab[j].r > tab[j+1].r )
				swap(tab[j], tab[j+1]);
	return int(tab);
}

void Schrage::Display(int number_of_tasks)
{
	for(int i=1;i<number_of_tasks;i++)
		cout << tab[i];
}

Schrage::Schrage(){}
Schrage::~Schrage() {}
