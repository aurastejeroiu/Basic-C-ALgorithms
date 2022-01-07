#include <iostream>
#include <math.h>
using namespace std;

//P1.8 Fie a>0 un numar natural. Sa se scrie un algoritm pentru calculul mediei aritmetice, geometrice
//     si armonice ale tuturor divizorilor lui a.

void SumeProdDiv(long n, long& Cont, long& Sd, long& Prod, float& InvSuma){    //retur 1 daca n este perfect, 0 altfel
     long d;        //Cont=numarul divizorilor; Sd=suma divizorilor
     if(n==1)  {    //Prod=produsul divizorilor; InvSuma=suma inverselor divizorilor
        Sd=1;
        Prod=1;
        InvSuma=1.0;
        Cont=1;
        return;
     }
     Sd=n+1;
     Prod=1*n;
     InvSuma=1.0+1.0/n;
     Cont=2;
     d=2;
     while (d*d<=n){                //O(rad(n))
       if(n%d==0)
            if(d==n/d) {Sd+=d;
                        Prod*=d;
                        InvSuma+=1.0/d;
                        Cont++;
            }
            else       {Sd+=d+n/d;
                        Prod*=d*n/d;
                        InvSuma+=1.0/d+1.0/(n/d);
                        Cont=Cont+2;
            }
       d++;
     }
}

int main()
{   float Mh,Mg,Ma,InvSuma;
    long  n,Sd,Prod,Cont;
    cout << "da un natural(>0):";
    cin  >> n;
    SumeProdDiv(n,Cont,Sd,Prod,InvSuma);
    Mh=Cont/InvSuma;
    Mg=pow(Prod,1.0/Cont);
    Ma=Sd/Cont;
    cout<<"Media Armonica="<<Mh<<" Media Geom="<<Mg<<" Media aritmetca="<<Ma;


    cout << endl << "Hello world!" << endl;
    return 0;
}
