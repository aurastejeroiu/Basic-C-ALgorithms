#include <iostream>
#include <iomanip>
using namespace std;

void TrPascal(int m, long P[][20]){
   for(int i=0;i<=m;i++)               //initializare matrice,
     for(int k=0;k<=m;k++)
        P[i][k]=0;
   for(int i=0;i<=m;i++)               //initializare matrice,
     for(int k=0;k<=i;k++)
        if(k==0 || i==k) P[i][k]=1;
        else             P[i][k]=P[i-1][k-1]+P[i-1][k];//creare triunghi Pascal
}
void Afisare(int m, long P[][20]){
    for(int i=0;i<=m;i++)
    { for(int k=0;k<=i;k++)
         cout<<setw(5)<<P[i][k];
      cout<<endl;
    }
}
int main()
{   int     m;
    long    P[20][20];
    cout    <<"da dim Triunghiului:"; cin  >>m;
    TrPascal(m,P);
    Afisare (m,P);
    cout     <<"Program terminat:";
    return 0;
}

