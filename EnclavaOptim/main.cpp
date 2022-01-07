#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#define Contur (i==1 ||i==m ||j==1 ||j==n)  ///definirea comditia de contur a matricii
///definirea celor 4-vecini, pentru simplificarea scrierii in continuare
#define Vecini() { el=A[i][j]; sus=A[i-1][j]; dr =A[i][j+1]; jos=A[i+1][j]; st =A[i][j-1]; }
int A[20][20];
int m,n,Max;

void CitMatrice(){                  ///citirea matricii cu tarile vecine
   ifstream Fin("enclave.in");
   Fin>>m>>n;
   Max=0;                           ///Max va indica numarul de tari din matrice
   for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
           {Fin>>A[i][j];
            if(A[i][j]>Max) Max=A[i][j];
           }
   cout<<"nr de tari:"<<Max<<endl;
}
void AfisMatrice(){                 ///afisarea matricii cu tarile vecine
    for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++)
           cout<<setw(3)<<A[i][j];
      cout<<endl;
    }
}
bool EsteInM(int LM, int M[], int val){
    for(int i=0;i<LM;i++){
        if(val==M[i]) return true;
    }
    return false;
}
int NrVecini(int s,int d,int j,int st, int el){
  int V[5]={s,d,j,st,el};           //V trebuie facut multime in M
  int M[5];
  int LM=0;
  ///M[0]=V[0]; LM=1;
  for(int i =0;i<5;i++){
     if(!EsteInM(LM,M,V[i]))  M[LM++]=V[i];
  } ///cout<<el<<" nr vec:"<<lM<<endl;
  return LM;
}
void Enclave(){                     ///gasirea numarului de enclave si a perimetrului maxim
   int nrEnc=0;
   int Enc[20];                     ///vectorul care indica fiecare enclava
   bool ok=true;                    ///ok flag pentru tara, daca tara e pe contur
                                    ///adica are iesire la Ocean => ok=false
   for (int tara=1;tara<=Max;tara++)///tara e numarul de ordine al tarilor
      { ok=true;                    ///ok=false, iesire fortata din cele 2 for-uri
        for(int i=1;i<=m &&ok;i++)  ///tara nu e enclava
          for(int j=1;j<=n &&ok; j++)
            if(A[i][j]==tara )      ///daca A[i][j]==tara si tara e pe contur nu e enclava
               {if(Contur) ok=false;/// si se pune ok pe false
                  else {              ///daca A[i][j]==tara se contorizeza nr de 4-vecini, diferiti
                    int nrvec=0;    ///la fiecare element A[i][j] se calculeaza vecinii
                    int sus,dr,jos,st,el;
                    Vecini();
                    if(NrVecini(sus,dr,jos,st,el)>2) ok=false;
                  }//end else
                }//end if
         if(ok) { Enc[++nrEnc]=tara;    ///la iesirea din matrice si ok==true => tara e enclava
                                        ///si se adauga in vectorul de enclave
                  cout<<"enclava:"<<Enc[nrEnc]<<endl;///afisare enclavele
                }
        }
   cout<<nrEnc<<endl;
   int Perim[20],PerMax=0;              ///determinarea perimetrului maxim
   for(int tara=1;tara<=nrEnc;tara++){
      Perim[tara]=0;                     ///perimetrele se retin in tabloul Perim
      for(int i=1;i<=m;i++)
       for(int j=1;j<=n;j++){
        if(A[i][j]==Enc[tara]){
          int sus,dr,jos,st,el;             ///definirea celor 4-vecini, pentru simplificarea
          Vecini();                         ///scrierii in continuare
          if(el!=sus) Perim[tara]++;        ///se adauga cate 1 km pentru fiecare 4-vecin
          if(el!=dr) Perim[tara]++;         ///diferit de tara (de el insusi)
          if(el!=jos) Perim[tara]++;
          if(el!=st) Perim[tara]++;
       }
      }
      if( Perim[tara]>Max) Max=Perim[tara];
      //cout<<Perim[tara]<<endl;
   }
   cout<<Max<<endl;
}
int main()
{   CitMatrice();
    AfisMatrice();
    Enclave();
    cout << "Program terminat" << endl;
    return 0;
}
