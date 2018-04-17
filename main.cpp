#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <queue>
#include <vector>
#include "Carlier.h"

using namespace std;



int main()
{
      Carlier ob;
      ob.Read();
      ob.Sort();
      ob.Display();
    //  ob.Schrage_without();
      //ob.Schrage_with();
      ob.carlier();


     cout << "U: " << ob.U;
     //<< " UB: " << ob.Cmax_without << " LB: " << ob.Cmax_with;
/*
	Schrage schrage;
	schrage.Read();
	cout << schrage.Schrage_with() << endl;
	*/
	return 0;
}

