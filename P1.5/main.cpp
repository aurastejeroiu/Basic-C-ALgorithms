#include <iostream>
#include <math.h>
using namespace std;

///1.5 Doua numere diferite x si y sunt "prietene" daca suma divizorilor numarului x este egala
///    cu suma divizorilor numarului y. Sa se gaseasca numerele "prietene" din intervalul [a,b]

///Idee: se va verifica cate numere din [a,b] au aceeasi suma a divizorilor S
///      S va parcurge multimea {a+1,a+2,...(2*b*rad(b)-b+rad(b))/2}

long SumDiv(long n)
{ long S=n+1;
  for(long d=2; d*d<=n; d++)		//O(rad(n))
    if( n%d==0)   			        //S+=i+n/i;
        if(d==n/d) S+=d;
        else       S+=d+n/d;
  return S;
}

void AfisPrietene(long a, long b)
{   int cnt,Nr=0;		                ///cont=contorul numerelor prietene pentru suma S
    long Pr[100];		                ///Nr=numarul multimilor de numere prietene
    long LimB=b*(b+10)/8;               ///(b*sqrt(b)+b-sqrt(b))/2;  b*(b+10)/8;	    //LimB=limita superioara a lui S
    for(long S=a+1; S<=LimB; S++)
    {  cnt=0;
       for(long i=a;i<=b;i++)
             if(S==SumDiv(i)) Pr[++cnt]=i;  ///in tabloul Pr se retin numerele prietene
       if(cnt>1) {			                ///deci cele care au aceeasi suma S a divizorilor
            cout<<++Nr<<". "<<"suma "<<S<<" are:";///Afisare multime de numere prietene
            for(int i=1;i<=cnt;i++)
                cout<<Pr[i]<<" ";
            cout<<"prietene \n";
       }
    }
}

int main()
{   long a,b;
    cout<<"da a:"; cin>>a;  //citire interval
    cout<<"da b:"; cin>>b;
    AfisPrietene(a,b);
    cout << "Program terminat" << endl;
    return 0;
}
