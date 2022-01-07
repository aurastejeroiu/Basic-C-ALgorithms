#include <iostream>

using namespace std;

//1.5 Doua numere diferite x si y sunt "prietene" daca suma divizorilor numarului x este egala
//    cu suma divizorilor numarului y. Sa se gaseasca numerele "prietene" din intervalul [a,b]

//Idee: se va verifica cate numere din [a,b] au aceeasi suma a divizorilor S
//      S va parcurge multimea {a+1,a+2,...b*(b+10)/8}

long SumDiv(long n)
{ long S=n+1;
  for(long d=2; d*d<=n; d++)		//O(rad(n))
    if( n%d==0)   			        //S+=i+n/i;
        if(d==n/d) S+=d;
        else       S+=d+n/d;
  return S;
}

void AfisPrietene(long a, long b)
{   int cnt,Nr=0;		        ///cont=contorul numerelor prietene
    long Pr[100];		        ///Nr=numarul multimilor de numere prietene
    for(long i=a;i<=b;i++)
    {  cnt=0;
       for(long S=a+1;S<=SumDiv(i);S++)
             if(i==SumDiv(S)) Pr[++cnt]=i;  ///in tabloul Pr se retin numerele prietene
       if(cnt>1) {			                ///deci cele care au aceeasi suma S a divizorilor
            cout<<++Nr<<". "<<"suma "<<i<<" are:";///Afisare multime de numere prietene
            for(int k=1;k<=cnt;k++)
                cout<<Pr[k]<<" ";
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
