#include <iostream>
#include <iomanip>
using namespace std;

///P1.2. Sa se tipareasca toate tripletele (i,j,k) de numere naturale
///      care verifica conditiile:
///       i^2+j^2=k^2
///        i<j<k<=n (n dat)
///     Idee: se imbrica 3 cicluri dupa i, j si k si se verifica conditiile
///           teoremei lui Pitagora
///          -se scrie putin dar complexitatea este O(n^3)!!!

void CitireDate(long &n){
    cout << "da limita n=";
    cin  >> n;
}

void Pitagora(long n){
    long Cont=0;                         ///Cont este contor pentru triplete
    for(long i=3;i<=n-2;i++)             ///tripletele pitagorice incep cu 3,4,5
        for(long j=i+1;j<=n-1;j++)
            for(long k=j+1;k<=n;k++)
                if(i*i+j*j==k*k)
                    cout<<setw(5)<<++Cont<<"."<<setw(5)<<i<<setw(5)<<j<<setw(5)<<k<<endl;

}

int main()
{   long        n;
    CitireDate (n);
    Pitagora   (n);
    cout <<     "Program terminated" << endl;
    return 0;
}
