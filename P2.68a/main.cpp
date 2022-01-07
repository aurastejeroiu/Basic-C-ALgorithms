#include <iostream>

using namespace std;

bool Prim(long n){
   if(n<2)      return false;
   if(n>3 && n%2==0)   return false;
   long d;
   for(d=3;d*d<=n;d+=2)
     if(n%d==0) return false;
   return       true;

}

long OrdinalK(long k){
  long N,n,Val,d;
  if(k<=3)  return k;
  N=3;
  n=3;
  while(n<k){
    N++;
    if(Prim(N)) {n++;               ///daca N e prim atunci Val=N
                 Val=N;
                }
    else{                           ///cand N nu este prim si se verifca divizori
      d=2;
      while(n<k && d<=N/2){         ///divizorii d trebuie sa fie <=N/2
        if(N%d==0 && Prim(d)){
            n+=d;
            Val=d;
        }
        d++;
      }
      if(n>=k) return Val;          ///iesire cand se verifica ca d e divizor
    }
  }
  return Val;                       ///iesire cand n==k
}

int main()
{   long k;
    cout <<"da pozitia:";                   ///k>=1
    cin  >>k;
    cout <<"elem. de pe poz:"<<k<<" este "<<OrdinalK(k);
    cout << "\nProgram terminated" << endl;
    return 0;
}
