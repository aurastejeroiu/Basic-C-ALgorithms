#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

///  P1.2. Sa se tipareasca toate tripletele (i,j,k) de numere naturale
///        care verifica conditiile:
///         i^2+j^2=k^2
///         i<j<k< =n (n dat)
///  Idee: se imbrica 2 cicluri dupa i, j si se verifica conditiile teoremei lui Pitagora
///          -se scrie mai mult dar complexitatea este O(n^2)!!!
///          -patratul lui i se calculeaza doar o singura data pentru fiecare i

void CitireDate(long long &n){
    cout << "da limita n=";
    cin  >> n;
}

void Pitagora(long long n){
    long long   i,j;
    long        Cont=0;
    long        NPeRad2 =n/sqrt(2);
    for(i=3;i<=NPeRad2;i++){         ///i<=[n/sqrt(2)], de ce?
        long long iLa2=i*i;
        j        =i+1;
        while (j<=n-1){
            long long SumaPatrate=iLa2+j*j;
            long long k=sqrt(SumaPatrate);
            if(k<=n && k*k==SumaPatrate)
                    cout<<setw(5)<<++Cont<<"."<<setw(5)<<i<<setw(5)<<j<<setw(5)<<k<<endl;
            j++;
        }
   }
}

int main()
{   long long n;
    CitireDate  (n);
    Pitagora    (n);
    cout << "Program terminated" << endl;
    return 0;
}
