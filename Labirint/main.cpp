#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>


#define Finis ((iFin<=1) || (iFin>=m) || (jFin<=1) || (jFin>=n))

using namespace std;

struct Cuplu{
   int i;
   int j;
};

void CitLab(int& m, int& n, int A[20][20]){
   ifstream Fin("Labirint.txt");
   Fin>>m>>n;
   for(int i=1;i<=m; i++)
    for(int j=1;j<=n; j++)
        Fin>>A[i][j];
}

void AfisLab(int m, int n, int A[20][20]){
   cout<<endl<<"Matricea labirintului"<<endl;
   cout<<"  "; for(int j=1; j<=n;j++) cout<<setw(3)<<j;
   cout<<endl;
   for(int i=1;i<=m; i++)
     {cout<<setw(2)<<i;
      for(int j=1;j<=n; j++)
        if(A[i][j]==-1)
            if(i==1 || i==m) cout<<setw(3)<<'=';
            else             cout<<setw(3)<<'|';
        else
            if(A[i][j]==0) cout<<setw(3)<<'O';
            else           cout<<setw(3)<<A[i][j];
      cout<<endl;
     }
}

void Iesire(int m, int n, int A[20][20]){
   int i0,j0,iFin,jFin;            ///(i0,j0) pornirea iar (iFin,jFin) coordonatele de iesire
   bool Start;
   do{  Start=true;
        cout<<"\ncitirea coord initiale"<<endl;
        cout<<"lin:";cin>>i0;           ///validam
        cout<<"col:";cin>>j0;
        if(A[i0][j0]==-1){
            cout<<"locul de start e invalid";
            Start=false;
        }
   }

   while (!Start);

   iFin=i0; jFin=j0;
   A[i0][j0]=1;
   int k=1;
   cout<<"("<<i0<<","<<j0<<")\n";
   AfisLab(m,n,A);
   getch();                        ///4-vecinii lui A[i][j]=k se pun pe k+1 (4-vecinii egali cu 0)
                                   ///se vor crea siruri strict crescatoare spre iesire
                                   ///iesirea este data de expresia Finis definita cu #define
   while (!Finis) {
    for (int i=1;i<=m;i++)
      for (int j=1; j<=n; j++)
        if(A[i][j]==k){
            if(A[i-1][j]==0) {              ///pentru 4-vecinul de sus
                A[i-1][j]=k+1;
                if(i==2) {iFin=1; jFin=j;}; ///stabilirea iesirii pe linia de sus
            }
            if(A[i+1][j]==0) {              ///pentru 4-vecinul de jos
                A[i+1][j]=k+1;
                if(i==m-1) {iFin=m; jFin=j;}///stabilirea iesirii pe linia de jos
            }
            if(A[i][j-1]==0) {              ///pentru 4-vecinul din stanga
                A[i][j-1]=k+1;
                if(j==2)  {jFin=1; iFin=i;} ///stabilirea iesirii pe coloana din stanga
            }
            if(A[i][j+1]==0) {              ///pentru 4-vecinul de dreapta
                A[i][j+1]=k+1;
                if(j==n-1) {jFin=n;iFin=i;} ///stabilirea iesirii pe coloana din dreapta
            }
        }
   k++;
   AfisLab(m,n,A);
   getch();
  }
  cout<<"("<<iFin<<","<<jFin<<")\n";            ///afisarea coordonatelor de iesire
  Cuplu Sir[100];
  cout<<"k="<<k<<endl;
  int lung=k;
  int i=iFin,j=jFin;
  Sir[k].i=iFin;           ///in sirul de cupluri se pune dinspre coada spre inceput,deci de la k la 1
  Sir[k].j=jFin;           ///k se foloseste ca indice in Sir
  while(i!=i0 || j!=j0){
       if(A[i][j]==k)
          if (A[i-1][j]==k-1) {  ///unul din 4-vecini care are valoare k-1 este urmatorul
            k--;                 ///element in sir
            Sir[k].i=--i;
            Sir[k].j=j;
          }
          else
            if(A[i+1][j]==k-1) {
              k--;
              Sir[k].i=++i;
              Sir[k].j=j;
            }
            else
              if(A[i][j-1]==k-1){
                k--;
                Sir[k].i=i;
                Sir[k].j=--j;
              }
              else
                if(A[i][j+1]==k-1){
                  k--;
                  Sir[k].i=i;
                  Sir[k].j=++j;
           }
  }
  for (int l=1;l<=lung;l++)                       ///afisarea vectorul Sir
     cout<<"("<<Sir[l].i<<","<<Sir[l].j<<"),";
}

int main()
{   int m,n;
    //for(int i=0;i<256;i++)
    //    cout<<setw(3)<<(char)i<<setw(3)<<i;
    int A[20][20];
    CitLab (m,n,A);
    AfisLab(m,n,A);
    Iesire (m,n,A);
    cout <<endl<<"Program terminated" << endl;
    return 0;
}
