#include <iostream>
#include <math.h>
using namespace std;

///P1.8 Fie a>0 un numar natural. Sa se scrie un algoritm pentru calculul mediei aritmetice, geometrice
///     si armonice ale tuturor divizorilor lui a.

void Div(long n, long D[], long& NrDiv){
   long d;
   NrDiv=0;
   for (d=1; d*d<n;d++)
    if(n%d==0) { D[++NrDiv]=d;
                 D[++NrDiv]=n/d;
               }
    if(d==n/d) D[++NrDiv]=d;


   }


long SumDiv(long D[], long NrDiv){
    long S=0;
    for(long i=1;i<=NrDiv;i++)
        S=S+D[i];
    return S;
}

double SumInvDiv(long D[], long NrDiv){
    double F=0;
    for(long i=1;i<=NrDiv;i++)
        F=F+1.0/D[i];    //F=F+ (double)1/D[i];
    return F;
}

long Prod(long D[], long NrDiv){
    long P=1;
    for(long i=1;i<=NrDiv;i++)
        P=P*D[i];
    return P;
}


int main()
{   float Mh,Mg,Ma,InvSuma;
    long  n,NrDiv;
    long  D[100];
    cout << "da un natural(>0):";
    cin  >> n;
    Div(n,D,NrDiv);
    Mh=NrDiv/SumInvDiv(D,NrDiv);
    Mg=pow(Prod(D,NrDiv), 1.0/NrDiv);
    Ma=((double)SumDiv(D,NrDiv))/NrDiv;
    cout<<"Media Armonica="<<Mh<<" Media Geom="<<Mg<<" Media aritmetca="<<Ma;


    cout << endl << "Program terminat" << endl;
    return 0;
}
