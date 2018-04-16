#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <queue>
#include <vector>
#include "Carlier.h"

using namespace std;

int n=0;


int main()
{
      Carlier ob;
      ob.Read();
      ob.Sort();
      ob.Schrage_without();
      ob.Display();

     cout << "U: " << ob.U << "UB: " << ob.Cmax_without << "LB: " << ob.Cmax_with;
/*
	Schrage schrage;
	schrage.Read();
	cout << schrage.Schrage_with() << endl;
	*/
	return 0;
}
/*
int Calier(int n, priority_queue<Quest,vector<Quest>,Nset> N, priority_queue<Quest,vector<Quest>,Gset> G, int UB)
{
	int U=schrage(n, N, G);
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
*/

