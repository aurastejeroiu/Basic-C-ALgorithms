#include <iostream>

using namespace std;
//P1.6 Sa se calculeze si sa se afiseze primii n termeni din sirul Fibonacci sir definit astfel:
//     F(0)=F(1)=1, F(n)=F(n-1)+F(n-2) pentru n>=2

long F(long n){                             //recursiv, mai lenta
    if(n==0 || n==1) return 1;
    else             return F(n-1)+F(n-2);
}

void FF(long n){   //mai rapid              //iterativ, mai rapida
    long i,a,b,Suma;                        //a,b=doi termeni consecutivi
    a=b=1;                                  //Suma=urmatorul termen
    cout<<a<<" "<<b<<" ";
    for (i=3;i<=n;i++)
        {Suma=a+b;
         cout<<Suma<<" ";
         a=b;
         b=Suma;
        }
}
int main()
{   long i,n;
    cout << "cati termeni vrei:";
    cin  >> n;
    for(i=0;i<n;i++)
        cout<<F(i)<<" ";
    cout<<endl;
    FF(n);
    cout << "Program terminat" << endl;
    return 0;
}
