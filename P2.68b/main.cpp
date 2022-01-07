#include <iostream>
using namespace std;

long OrdinalK(long k){
  long N,NN,n,Val,d;                ///n indice in sirul cerut, N este indicele in sirul nr. naturale
  if(k<=3)  return k;               ///NN este clona a lul N, Val este valoarea elem. din sirul cerut
  N=3;                              ///d este divizorul curent, d=2,3,...N  sau NN daca N nu e prim
  n=3;
  while(n<k){
    N++;
    d=2;
    NN=N;
    while(n<k && d<=NN){           ///divizorii d trebuie sa fie <=NN
        if(NN%d==0){
            while(NN%d==0) NN/=d;   ///NN se imparte cu d cat se poate
            Val=d;
            if(d<N) n+=d;           ///daca d<N atunci N nu este prim, n creste cu d
            else    n++;            ///daca d>=N atunci N este prim
        }
        if(d==2) d=3;
        else     d+=2;
      }
    }
    return Val;
}

int main()
{   long k;
    cout <<"da pozitia:";                   ///k>=1
    cin  >>k;
    cout <<"elem. de pe poz:"<<k<<" este "<<OrdinalK(k);
    cout << "\nProgram terminated" << endl;
    return 0;
}
