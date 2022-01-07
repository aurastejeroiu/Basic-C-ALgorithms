#include <iostream>
#include <string.h>
using namespace std;

int main()
{  string Zile[7]={"duminica","luni","marti","miercuri","joi","vineri","sambata"};
   int incep,curent;
   cout<< "in ce zi a sapt. a fost 1 ian.:";
   cin >> incep;
   cout<< " da nr de ordine (din an) al zilei  curente :";
   cin >> curent;
   cout<< Zile[(curent+1-incep)%7];
   return 0;
}
