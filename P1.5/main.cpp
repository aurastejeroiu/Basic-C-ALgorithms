#include <iostream>

using namespace std;

//1.5 Doua numere diferite x si y sunt "prietene" daca suma divizorilor numarului x este egala
//    cu suma divizorilor numarului y. Sa se gaseasca numerele "prietene" din intervalul [a,b]

//Idee: se va verifica cate numere din [a,b] au aceeasi suma a divizorilor S
//      S va parcurge multimea {a+1,a+2,...b*(b+20)/16}

long SumDiv(long n)
{ long S=n+1;
  for(long i=2; i*i<=n; i++)		//O(rad(n))
    if( n%i==0)   			        //S+=i+n/i;
        if(i==n/i) S+=i;
        else       S+=i+n/i;
  return S;
}

void Prieten(long a, long b)
{   int cont,Nr=0;		        //cont=contorul numerelor prietene
    long P[100];		        //Nr=numarul multimilor de numere prietene
    long LimSup=b*(b+20)/16;	//LimSup=limita superioara a lui S
    for(long S=a+1; S<=LimSup; S++)
    {  cont=0;
       for(long i=a;i<=b;i++)
             if(S==SumDiv(i)) P[++cont]=i;  //in tabloul P se retin numerele prietene
       if(cont>1) {			                //deci cele care au aceeasi suma S a divizorilor
            cout<<++Nr<<". "<<"suma "<<S<<" are:";//Afisare multime de numere prietene
            for(int j=1;j<=cont;j++)
                cout<<P[j]<<" ";
            cout<<"prietene\n";
       }
    }

}
int main()
{   long a,b;
    cout<<"da a:"; cin>>a;  //citire interval
    cout<<"da b:"; cin>>b;
    Prieten(a,b);

    cout << "Program terminat" << endl;
    return 0;
}
