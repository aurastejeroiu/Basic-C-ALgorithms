#include <iostream>

using namespace std;

void Frec(long n,long x[]){
  while(n>0){
     x[n%10]++;
     n=n/10;
  }
}

long Maxim(long n,long x[]){
  long Max=0;
  for(int i=9;i>=0;i--)
     while(x[i]>0){
        Max=Max*10+i;
        x[i]--;
     }
  return Max;
}

long Minim(long n,long x[]){
  long Min=0,imin=1;
  int i=1;                  ///determinarea primei cifre nenule imin
  while(i<=9 && x[i]==0)i++;
  imin=i;
  Min=Min*10+i;             ///punerea cifrei minime in Min
  x[i]--;
  while(x[0]>0){            ///golirea cifrelor 0 in Min, daca exista
    Min=Min*10;
    x[0]--;
  }
  for(i=imin;i<=9;i++)      ///adaugarea crescatoare a cifrelor ramase
    while(x[i]>0){
      Min=Min*10+i;
      x[i]--;
  }
  return Min;
}



int main()
{long n,x[10]={0};
 cin>>n;
 Frec(n,x);
 cout<<Maxim(n,x);
 Frec(n,x);
 cout<<" "<<Minim(n,x)<<endl;
 cout << "Hello world!" << endl;
 return 0;
}
