#include <iostream>
#include <iomanip>
using namespace std;
/*
long CNK(long n, long k){
    if(k>n)          return 0;
    if(k==0 || n==k) return 1;
    /*else           return CNK(n-1,k-1)+CNK(n-1,k);
}
*/

long CNK(long n, long k){
    if(k>n)          return 0;
    if(k==0 || n==k) return 1;
    /*else*/         return CNK(n-1,k-1)*n/k;
}


void TrPascal(int m, long P[][30]){
   for(int n=0;n<=m;n++)               ///initializare matrice,
     for(int k=0;k<=m;k++)
        P[n][k]=0;

   for(int n=0;n<=m;n++)               ///creere trunghi Pascal
     for(int k=0;k<=n;k++)
        P[n][k]=CNK(n,k);               ///creare element P[n][k]
}

void Afisare(int m, long P[][30]){
    for(int n=0;n<=m;n++)
    { cout<<setw(2)<<n<<".  1";
      for(int k=1;k<=n;k++)
         cout<<setw(8)<<P[n][k];
      cout<<endl;
    }
}
void Citire(int &m){
        cout <<"da dim Triunghiului:";
        cin  >>m;
}

int main()
{   int     m;
    long    P[30][30];
    Citire(m);
    TrPascal(m,P);
    Afisare (m,P);
    cout     <<"Program terminat:";
    return 0;
}

