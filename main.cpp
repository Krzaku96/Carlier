#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct Quest
{
public:
	int r,p,q;
	int task_number;
};

struct Nset
{
	bool operator()(Quest& a, Quest& b)
	{
		return a.r > b.r;
	}
};

struct Gset
{
	bool operator()(Quest& a, Quest& b)
	{
		return a.q < b.q;
	}
};

istream& operator >> (istream& enter, Quest& request)
{
	enter >> request.r >> request.p >> request.q;
	return enter;
}

ostream& operator << (ostream& exit, Quest& request)
{
	cout << request.r << " " << request.p << " " << request.q << endl;
	return exit;
}

Quest* Read(int n, int number_of_tasks, Quest* tab);
Quest* Sort(int number_of_tasks, Quest *tab);
void Display(int number_of_tasks, Quest *tab);
int Schrage(int n, priority_queue<Quest,vector<Quest>,Nset> N, priority_queue<Quest,vector<Quest>,Gset> G);
int Calier(int n, priority_queue<Quest,vector<Quest>,Nset> N, priority_queue<Quest,vector<Quest>,Gset> G, int UB);

int a=0, b=0, c=0;
priority_queue<Quest,vector<Quest>,Gset> Gcopy;
vector<Quest> Ghelp;

int main()
{
	int n;
	//Display(number_of_tasks, tab);
	priority_queue<Quest,vector<Quest>,Nset> N;
	priority_queue<Quest,vector<Quest>,Gset> G;
	
	int UB=10000000;	

	Calier(n, N, G, UB);
	//cout << "cmax " << Cmax << endl;
	return 0;
}

int Calier(int n, priority_queue<Quest,vector<Quest>,Nset> N, priority_queue<Quest,vector<Quest>,Gset> G, int UB)
{
	int U=Schrage(n, N, G);
	if(!Gcopy.empty())
	{
		Ghelp.push_back(Gcopy.top());
		Gcopy.pop();
	}
	
	if (U<UB)
		UB=U;
	//abc
	cout << b << endl;
	cout << Ghelp[b].q << endl;
	if (c==0)
		return U;
}

Quest* Read(int n, int number_of_tasks, Quest* tab)
{
	ifstream file;
	file.open( "SCHRAGE1.DAT", ios::in);
	file >> n;
	tab=new Quest[n+1];
	number_of_tasks=n+1;
	for(int i=1;i<=n;i++)
	    file >> tab[i];
	file.close();
	tab[0].r=number_of_tasks;
	return tab;
}

Quest* Sort(int number_of_tasks, Quest *tab)
{
	for( int i = 0; i < number_of_tasks; i++ )
		for(int j=0; j<number_of_tasks-1; j++)
			if( tab[j].r > tab[j+1].r )
				swap(tab[j], tab[j+1]);
	return tab;
}

void Display(int number_of_tasks, Quest *tab)
{
	for(int i=1;i<number_of_tasks;i++)
		cout << tab[i];
}

int Schrage(int n, priority_queue<Quest,vector<Quest>,Nset> N, priority_queue<Quest,vector<Quest>,Gset> G)
{
	Quest *tab;
	int number_of_tasks;
	int Cmax=0;
	int t=0;
	int k=0;
	tab=Read(n, number_of_tasks, tab);
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
			Gcopy.push(N.top());
			N.pop();
		}
		if(G.empty())
			t=N.top().r;
		else 
		{
			
			t=t+G.top().p;
			k=k+1;
			//Cmax=max(Cmax, t+G.top().q);
			if(Cmax<=(t+G.top().q))
			{
				Cmax=t+G.top().q;
				b=k;
			}
			G.pop();
		}
	}
	return Cmax;
}