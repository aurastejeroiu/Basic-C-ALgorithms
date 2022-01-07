#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Patrat{              ///Fieccare element din matrice de linii are 4 borduri
                            ///si nrB=de borduri
    int sus, dr, jos, st,
        nrBete;
};

Patrat A[100][100];
int m,n;

void AfisMatrice(int m, int n){
   for(int i=1;i<m;i++){
    for(int j=1;j<n;j++)
        cout<<A[i][j].sus<<A[i][j].dr<<A[i][j].jos<<A[i][j].st<<A[i][j].nrBete<<" ";
    cout<<endl;
   }
}
void CitBiscuit(){
   ifstream Fin("biscuit.in");
   Fin>>m>>n;
   for(int i=1;i<m;i++)         ///init matrice cu 0
      for(int j=1;j<n;j++)
          A[i][j].sus=A[i][j].dr=A[i][j].jos=A[i][j].st=A[i][j].nrBete=0;

   char linie[m-1];             ///linie este sir de 0101010
   for(int i=1;i<m;i++)         ///citire m-1 linii cu borduri sus
       { Fin>>linie;
         for(int j=0;j<strlen(linie);j++)
            { if(linie[j]=='1') {
                 A[i][j+1].sus=1; A[i][j+1].nrBete++;      ///bordura sus pentru fiecare linie
                 if(i>1 && i<m)   {  A[i-1][j+1].jos=1; ///pentru prima linie si
                                     A[i-1][j+1].nrBete++; ///ultima linie nu se face
                                                        ///pentru borduri jos
                                  }
              }
            }
       }
    Fin>>linie;                 ///citire ultima linie, bordura jos
    for(int j=0;j<strlen(linie);j++)
            if(linie[j]=='1') {A[m-1][j+1].jos=1;A[m-1][j+1].nrBete++;}
                                ///citire borduri verticale
    for(int i=1;i<m;i++){
        Fin>>linie;
        for(int j=0;j<strlen(linie);j++)
        { if(linie[j]=='1') {
                 A[i][j+1].st=1; A[i][j+1].nrBete++;
                 if(j>0 && j<n)   {  A[i][j].dr=1;
                                     A[i][j].nrBete++;
                                  }
              }
        }
    }
    AfisMatrice(m,n);
}
void NrPatrate(){
    bool ok;
    int nrP=0;                       ///contor de patrate
    m--;n--;
    do {
      ok=false;                      ///ok=false; daca exista nrB==3, atunci ok=true
      for(int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if(A[i][j].nrBete==3){
              ok=true;
              nrP++;
              if(A[i][j].sus==0)                    ///daca sus==0, trebuie bordat sus
                 {A[i][j].sus=1; A[i][j].nrBete++;     ///si se inchide patratul
                  if(i>1) { A[i-1][j].jos=1;        ///daca nu-i prima linie sus-ul ei
                            A[i-1][j].nrBete++;        ///este jos-ul liniei i-1
                            if (A[i-1][j].nrBete==4) nrP++;///daca nrB==4, (s-a mai inchis un patrat)
                          }                             ///si se contorizeaza
                 }
              if(A[i][j].jos==0)
                 {A[i][j].jos=1; A[i][j].nrBete++;
                  if(i<m) { A[i+1][j].sus=1;
                            A[i+1][j].nrBete++;
                            if (A[i+1][j].nrBete==4) nrP++;
                          }
                 }
               if(A[i][j].st==0)
                  {A[i][j].st=1; A[i][j].nrBete++;
                   if(j>1) { A[i][j-1].dr=1;
                             A[i][j-1].nrBete++;
                             if (A[i][j-1].nrBete==4) nrP++;
                           }
                  }
               if(A[i][j].dr==0)
                  {A[i][j].dr=1; A[i][j].nrBete++;
                   if(j<n) { A[i][j+1].st=1;
                             A[i][j+1].nrBete++;
                             if (A[i][j+1].nrBete==4) nrP++;
                           }
                  }

            }
            cout<<endl;
             AfisMatrice(m+1,n+1);
             cout<<endl;
    }
    while(ok);
    m++;n++;
    cout<<endl;
    AfisMatrice(m,n);
    cout<<endl<<nrP;
}
int main()
{   CitBiscuit();
    NrPatrate();
    cout <<endl<<"Program terminated" << endl;
    return 0;
}
