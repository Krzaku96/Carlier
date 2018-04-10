#ifndef SCHRAGE_H_INCLUDED
#define SCHRAGE_H_INCLUDED

#include "Quest.h"

using namespace std;


class Schrage
{
public:

Quest tab[1000];

     priority_queue<Quest,vector<Quest>,Nset> N;
	priority_queue<Quest,vector<Quest>,Gset> G;

friend bool operator<(const Quest& q1, const Quest& q2);
//struct Nset;
//struct Gset;

bool Read(int n, int number_of_tasks);
int Sort(int number_of_tasks);
void Display(int number_of_tasks);
int Schrage_without(int n);
int Schrage_with(int n);


 Schrage();
 ~Schrage();
};


#endif // SCHRAGE_H_INCLUDED
