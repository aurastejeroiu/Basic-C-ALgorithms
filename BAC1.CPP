#include <stdio.h>
#include <string.h>
#include <fstream.h>
#include <iostream.h>
#include <conio.h>


int main(void)
{ char prefix[10];
  char cuvant[100],*ptr;
  int n,contor;
  clrscr();
  ifstream f("bac.txt");
  f>>n;
  cout<<"n="<<n<<endl;
  f>>prefix;
  cout<<"prefixul="<<prefix<<endl;
  contor=0;
  while (!f.eof() || n>1)
   {f>>cuvant;
    if((ptr=strstr(cuvant,prefix))==cuvant) {contor++;
					     cout<<cuvant<<endl;
					    }
    n--;
    //cout<<contor<<endl;
    //cout<<"n="<<n<<endl;
   }
  cout<<contor;
  getch();

}
