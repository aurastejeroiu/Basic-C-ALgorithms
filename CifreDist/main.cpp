#include <iostream>

using namespace std;

void Cifre(long n,int VF[10])
{ int i;
  int Uc;

  for(i=0;i<10;i++) // initializare tablou frecventa cifre
     VF[i]=0;

  while(n>0)
  {Uc=n%10;
   VF[Uc]=VF[Uc]+1;// VF[Uc] ++;p pozitia cifrei Uc se aduna 1
   n=n/10;
  }

  }




int main()
{ long n;
  int V[10];
  int i;
  cout<<"da numarul natural ";
  cin>>n;
  Cifre(n,V);
  cout<<"numarul are urmatoarele cifre:\n";
  for(i=0;i<10;i++)
       if(V[i]>0) cout<<"cifra "<<i<<" de "<<V[i]<<" ori \n";

    return 0;
}
