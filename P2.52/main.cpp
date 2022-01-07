#include <iostream>
/* Se dau n>0, natural si X,Y din R^n, respectv R^m. Sa se determine pozitiile
   I0 si J0 cu urmatoarea proprietate: exista m componente consecutive din cei
   doi vectori incepand cu pozitiile I0, respectiv J0 si M este cel mai mare
   posibil. In cazul ca nu exista pozitii cu aceasta proprietate, I0 si J0 vor
   avea  valoarea n+1, rescpectiv m+1.
 
  Cu alte cuvinte se cauta cele mai lungi secvente consecutive care
   coincid din cei 2 vectori
 
  X={11,21,31,41,51,61,71,81,6,301,41}; n=11
   Y={20,81,6,7,8,81,6,301,40}; m=9
   => I0=8, J0=7 iar lung=3
   O secventa consecutiva de numere o vom nota cu (i,j), perechi de indici
   de inceput si sfarsit
*/
using namespace std;

void CitireVectori(int&n, int X[], char S){
  cout<<"da dim. vectorului:";
  cin >>n;
  for (int i=1;i<=n;i++){
    cout<<S<<"["<<i<<"]=";
    cin >>X[i];
  }
}

int CeaMaiLunga(int n, int X[], int m, int Y[], int i, int j){
        //X[i]=Y[j]si intoarece un indice JL din Y pentru care
        //secventele (i,i+JL-j) din X si (j,JL) din Y coincid
    while(i<=n && j<=m && X[i]==Y[j]){
        i++;
        j++;
    }
    if(i>n) return j;           //daca s-a epuizat X, retur pozitia din Y
    if(j>m) return m;           //daca s-a epuizat Y, retur dim lui Y
    if(X[i]!=Y[j]) return j-1;  //altfel retur o pozitie mai la stanga

}



void Identica(int n, int X[], int m, int Y[], int&I0, int&J0, int&M){
   int FinX,FinY,i,j,JL=0;
   FinX=FinY=-1;
   i=1;
   while(i<=n)
   { j=JL+1;
     while(j<=m && X[i]!=Y[j])j++;//sare peste valorile din y, diferite de x[i].
     cout<<"i="<<i<<endl;
     if(j<m)                      //daca am gasit o valoare egala
       { JL=CeaMaiLunga(n,X,m,Y,i,j);
         cout<<"j="<<j<<" Jfin="<<JL<<endl;
         if( JL-j>FinY-J0){
            J0=j;           //retinere noua secventa din Y
            FinY=JL;
            I0=i;           //retinere noua secventa din X
            FinX=i+JL-j;
            j=JL;
         }
       }
     else {i++;
           JL=1;
       }
   }
   M=FinX-I0+1;
}

int main()
{  int n=5,m=8;
   int X[]={0,1,2,4,5,6};
   int Y[]={0,4,5,11,13,4,5,6,7};
   int I0=1,J0=1,M;
   //citeste X,Y
   Identica(n,X,m,Y,I0,J0,M);
   if(M>0)
     { cout<<"exista secventa comuna de lungime "<<M<<"\n";
       for(int i=I0;i<=I0+M-1;i++)
         cout<<X[i]<<" ";
       cout<<endl;
       for(int j=J0;j<=J0+M-1;j++)
         cout<<Y[j]<<" ";
       cout<<endl;
     }
   else cout<<" nu exista secventa comuna";
   cout << "\nProgram terminat" << endl;
   return 0;
}
