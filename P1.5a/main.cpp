#include <iostream>

using namespace std;

//1.5 Doua numere diferite x si y sunt "semiprietene" daca suma divizorilor numarului x este egala
//    cu suma divizorilor numarului y. Sa se gaseasca numerele "semiprietene" din intervalul [a,b]

//Idee: se va verifica cate numere din [a,b] au aceeasi suma a divizorilor S
//      S va parcurge multimea {a+1,a+2,...b*(b+10)/8}

long SDR(long n,long d)  //apel SDR(n,2)
{ if(d*d>n) return 1+n;
  if(n%d==0)   			        ///S+=i+n/i;
        {if(d==n/d) return d+SDR(n,d+1);
         /*else*/   return d+n/d +SDR(n,d+1);
        }
  return SDR(n,d+1);
}

void AfisPrietene(long a, long b)
{   int cnt,Nr=0;		        ///cont=contorul numerelor semiprietene
    long Pr[1000];		        ///Nr=numarul multimilor de numere semiprietene
    long LimSup=b*(b+30)/18;    ///b*(b+10)/8;LimSup=limita superioara a lui S
    for(long S=a+1; S<=LimSup; S++)
    {  cnt=0;
       for(long i=a;i<=b;i++)
             if(S==SDR(i,2)) Pr[++cnt]=i;  ///in tabloul P se retin numerele semiprietene
       if(cnt>1) {			               ///deci cele care au aceeasi suma S a divizorilor
            cout<<++Nr<<". "<<"suma "<<S<<" are:";///Afisare multime de numere semiprietene
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
