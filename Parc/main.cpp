#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>


using namespace std;

int i0,j0,ifin,jfin;              ///(i0,j0) pornirea iar (ifin,jfin) iesirea

void AfisLab(int n,int A[20][20]){
   cout<<endl<<"Matricea parcului"<<endl;
   cout<<"  "; for(int j=1; j<=n;j++) cout<<setw(3)<<j;
   cout<<endl;
   for(int i=1;i<=n; i++)
     {cout<<setw(2)<<i;
      for(int j=1;j<=n; j++)
        if(A[i][j]==0)
           cout<<setw(3)<<'_';
        else
            if(A[i][j]==-1) cout<<setw(3)<<'X';
            else            cout<<setw(3)<<A[i][j];
      cout<<endl;
     }
}

void CitLabirint(int& n, int& i0, int& j0,int& ifin, int& jfin, int A[20][20]){
   int x,y,m;
   ifstream Fin("alee.in");
   Fin>>n>>m;
   for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
           A[i][j]=0;

   for(int i=1;i<=m;i++)
       {Fin>>x>>y; cout<<x<<" "<<y<<endl;
        A[x][y]=-1;
       }
       AfisLab(n,A);

       Fin>>i0>>j0>>ifin>>jfin;
       cout<<i0<<" "<<j0<<" "<<ifin<<" "<<jfin<<endl;

}

int FinalJ(int j,int jfin, bool& Ok){
    if(j==jfin) {Ok=true; return jfin;} ///daca j==jfin se termina totul
    return       j;
}

int FinalI(int i,int ifin, bool& Ok){
    if(i==ifin) {Ok=true;  return ifin;}
    return       i;
}
void Iesire(int n,int i0, int j0,int& ifin, int& jfin,int A[20][20]){

   A[i0][j0]=1;
   int k=1;
   cout<<"("<<i0<<","<<j0<<")\n";
   AfisLab(n,A);
   getch();                        ///4-vecinii lui A[i][j]=k se pun pe k+1 (4-vecinii egali cu 0)
                                   ///se vor crea siruri strict crescatoare spre iesire
   int If=i0,Jf=j0;                ///If,Jf indici care se apropie spre punctul de iesire
                                    ///iesirea este data de expresia Finis definita cu #define
   int i,j;
   bool Ok=false;                    /// Ok=true am ajuns la final
   while (!(If==ifin && Jf== jfin)) {
    for (i=1;i<=n && !Ok ;i++)
      for (j=1; j<=n && !Ok; j++)

         if(A[i][j]==k){
            if(i>1){
              if(A[i-1][j]==0) {              ///pentru 4-vecinul de sus
                 A[i-1][j]=k+1;
                 if((i-1)==ifin)
                    { If=ifin;                  ///stabilirea iesirii pe linia de sus
                      Jf=FinalJ(j,jfin,Ok);     ///daca j==jfin se termina totul
                    }
              }
            }
            if(i<n){
              if(A[i+1][j]==0) {            ///pentru 4-vecinul de jos
                 A[i+1][j]=k+1;
                 if((i+1)==ifin)            ///stabilirea iesirii pe linia de jos
                    { If=ifin;
                      Jf=FinalJ(j,jfin,Ok);  ///daca j==jfin se termina totul
                    }
              }
            }

            if(j>1){
              if(A[i][j-1]==0) {              ///pentru 4-vecinul din stanga
                 A[i][j-1]=k+1;
                 if((j-1)==jfin)
                      { Jf=jfin;              ///stabilirea iesirii pe coloana din stanga
                        If=FinalI(i,ifin,Ok); ///daca i== ifin se termina totul
                       }
              }
            }
            if(j<n){
               if(A[i][j+1]==0) {              ///pentru 4-vecinul de dreapta
                  A[i][j+1]=k+1;
                  if((j+1)==jfin) {
                        Jf=jfin;                ///stabilirea iesirii pe coloana din dreapta
                        If=FinalI(i,ifin,Ok);   ///daca i== ifin se termina totul
                  }
            }
          }
    }
      k++;
      AfisLab(n,A);
      cout<<If<<" "<<Jf<<endl;
      getch();
  }
   cout<<k<<endl;            ///afisarea coordonatelor de iesire
  }

int main()
{   int n;
    int i0,j0,ifin,jfin;              ///(i0,j0) pornirea iar (ifin,jfin) iesirea
    int A[20][20];
    CitLabirint (n,i0,j0,ifin,jfin,A);
    Iesire(n,i0,j0,ifin,jfin,A);
    cout <<endl<<"Program terminated" << endl;
    return 0;
}
