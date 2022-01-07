#include <iostream>
#include <string.h >
#include <math.h >

using namespace std;

struct Numar {
  int L;            ///nr de cifre
  int cif[2000];   ///spatiul de memorare al cifrelor, 123 se memoreaza ca 321
};

void EliminZero(Numar& N){
    int i=N.L;
    while(N.cif[i]==0) i--;  ///cifrele 0 nesemnificative se elimina
    N.L=i+1  ;
}

bool MaiMicEgal(Numar X, Numar Y){
    if(X.L<Y.L) return true;        ///daca lungim lui X < lungimea lui Y => X<Y
    if(X.L>Y.L) return false;       ///invers X>Y

    int i=X.L-1;                            /// aici au lungimi egale
    while(i>=0 && X.cif[i]==Y.cif[i]) i--;  /// se inainteaza pe cifre egale
    if(i<0) return true;                    ///daca toate cifrele sunt egale
    if(X.cif[i]<Y.cif[i]) return true;
                          return false;
}

bool MaiMic(Numar X, Numar Y){
    if(X.L<Y.L) return true;            ///daca lungim lui X < lungimea lui Y => X<Y
    if(X.L>Y.L) return false;           ///invers X>Y
    int i=X.L-1;                        /// aici au lungimi egale
    while(i>=0 && X.cif[i]==Y.cif[i]) i--;  /// se inainteaza pe cifre egale
    if(i<0) return false;               ///daca toate cifrele sunt egale
    if(X.cif[i]<Y.cif[i]) return true;
                          return false;
}

void AfisNumar(Numar X)
{
    for(int i=X.L-1;i>=0;i--)
        cout<<X.cif[i];
    cout<<" si are "<<X.L<<" cifre\n";
}

void Aduna(Numar A, Numar B, Numar& Suma){///numerele A si B au aceeasi lungime, algoritmul se simplifica
    int i,Transport=0;
    Suma.L=A.L;
    for(i=0;i<A.L;i++){
      Suma.cif[i]=A.cif[i]+B.cif[i]+Transport;
      Transport  =Suma.cif[i]/10;
      Suma.cif[i]%=10;
    }
    if(Transport>0){
        Suma.cif[Suma.L]=Transport;
        Suma.L++;
    }
}
void Medie(Numar A, Numar B, Numar& M){
    Numar Suma;
    Aduna(A,B,Suma);
    ///cout<<"\n         Suma=";
    ///AfisNumar(Suma);
    int Lung=M.L=Suma.L;
    int i,Transport=0,D=0;
    if (Suma.cif[Lung]==1) {
            Transport=1;
            M.L=Lung-1;
            Lung--;
    }
    for (i=Lung-1;i>=0;i--){
        int D = Transport*10+ Suma.cif[i];
        M.cif[i]=D/2;
        Transport=D-M.cif[i]*2;
   }

   EliminZero(M);
   ///cout<<"         Media=";
   ///AfisNumar(M);
   ///cout<<endl;

}

void Scade1(Numar N, Numar& NM1){
    NM1=N;
    if(N.cif[0]>0)              ///daca ultima cifra >0 se scade din ea 1
        NM1.cif[0]--;
    else{
        int i=0;
        while(N.cif[i]==0) {    /// toate cifrele se inlocuiesc cu 9
             NM1.cif[i]=9;
             i++;
        }
        NM1.cif[i]--;
        EliminZero(NM1);
    }

}
void Aduna1(Numar N, Numar& NP1){
    int i,Transport;
    NP1.L=N.L;
    NP1.cif[0]=N.cif[0]+1;
    Transport=NP1.cif[0]/10;
    NP1.cif[0]%=10;
    for(i=1;i<N.L;i++){
      NP1.cif[i]=N.cif[i]+Transport;
      Transport=NP1.cif[i]/10;
      NP1.cif[i]%=10;
    }
    if(Transport>0){
        NP1.cif[NP1.L]=Transport;
        NP1.L++;

    }
}


void Multiply(Numar a, Numar b, Numar& p){
  int i,j,Transport;
  p.L=a.L + b.L;            ///nr maxim de cifre ale produsului este suma nr de cifre
                            ///ale lui a si b;
  for (i=0; i< p.L; i++)    ///initializare cifre produs cu 0
     p.cif[i]=0;

  for (i=0; i< a.L;i++)
    for (j=0; j< b.L;j++)
           {p.cif[i+j]  +=a.cif[i]*b.cif[j];    ///se aduna la poz i+j a.cif[i]*b.cif[j]
            Transport    =p.cif[i+j] / 10;	    ///se determina transportul
            p.cif[i+j]   =p.cif[i+j] % 10;	    ///se retine in p.c[i+j] doar modulo 10
            p.cif[i+j+1]+=Transport;  		    ///aduna transportul pozitiei urmatoare
           }
  EliminZero(p);                                ///eliminare 0 nesemnificativ
 }

void Citire (char Sir[],Numar& M)
{   char	Nr[2000];
    cout<<	Sir;
    cin >>	Nr;
    int     lung=strlen(Nr);
    for(int i=lung-1;i>=0;i--)
        M.cif[lung-i-1]=(int)(Nr[i]-'0');          ///se scade codul lui '0' care este 48
    M.L=lung;
    cout<<"numarul citit:";AfisNumar(M);
}


void Radical10(Numar X, Numar& Prefix){
    long long Radi=0;
    int lung=X.L-1;           ///se construieste numarul in oglinda
    ///cout<<"\n lungime este:"<<X.L<<endl;
    int lungP=Prefix.L-1;
    while(lungP>=0){
         Radi=Radi*10 + X.cif[lung];
         lung--;
         lungP--;
    }
    cout<<"numarul de 9/10 cifre:"<<Radi<<endl;
    Radi=floor(sqrt(Radi*1.0));     ///se extrage radicalul
    cout<<Radi<<endl;               ///se afiseaza pentru control
                                    ///se construieste numarul Rad din Radi
    lung=0;
    while(Radi){
         Prefix.cif[lung]=Radi%10;
         Radi/=10;
         lung++;
    }
    Prefix.L=lung;
    ///cout<<"\nPrefix.L="<<Prefix.L<<endl;
}

void Radical(Numar X, Numar& Rad){
                                    ///se determina numarul  initial pentru inceputul calcului
                                    ///daca numarul X este <= 9.999.999.999 se calculeaza direct
                                    ///daca numarul X are lungime para >10, prefixul numarului initial este radical
                                    ///din primele (10 cifre), urmat de un numar de 0 egal cu (X.L-10)/2
                                    ///daca numarul X are lungime impara>9, prefixul numarul initial este radical
                                    ///din primele (9 cifre) urmat de un numar de  0 egal cu (X.L-9)/2
     Numar Prefix,Initial;
     if(X.L<=10)                    ///calcul direct
        { Initial.L=X.L;
          Radical10(X,Initial);
          Rad=Initial;
          return;
        }
     else{
          Numar Prod,Prod1;
          Numar Initial=X;            ///se detemina Prefixul din primele 9 sau 10 cifre a lui X
          Prefix.L = (X.L%2)? 9:10;
          int Lung = (X.L-Prefix.L)/2;///se pun Lung zerouri la sfarstul numarului Prefix
          cout<<"Lungimea numarului initial:"<<Initial.L<<endl;
          Radical10(Initial,Prefix);
          cout<<"Lungimea radical prefix:"<<Prefix.L<<endl;
          cout<<"Lungimea de zerouri supliment la radical prefix:"<<Lung<<endl;

          for(int i=0;i<Lung;i++)
              {for(int j=Prefix.L-1;j>=i;j--)
                  Prefix.cif[j+1]=Prefix.cif[j]; ///am construit numarul Prefix0..0, cu un numar de cifre adecvat
               Prefix.cif[i]=0;
               Prefix.L++;
              }
          Numar Mare=Prefix;
          for(int i=0;i<Lung;i++)
             Mare.cif[i]=9;                     ///am construit marginea dreapta Prefix9..9, cu un numar de cifre adecvat
          cout<<endl<<"Limita  stanga=";
          AfisNumar(Prefix);
          cout<<"Limita dreapta=";
          AfisNumar (Mare);

          Numar St=Prefix;
          Numar Dr=Mare;
          Numar StPlus1,DrPlus1,Patrat,Patrat1;

          Multiply(St,St,Patrat);               ///verificam pe capatul stanga
          Aduna1  (St,StPlus1);
          Multiply(StPlus1,StPlus1,Patrat1);
          if (MaiMicEgal(Patrat,X)&& MaiMic(X,Patrat1)){
             Rad=St;
             return;
          }

          Multiply(Dr,Dr,Patrat);               ///verificam pe capatul dreapta
          Aduna1  (Dr,DrPlus1);
          Multiply(DrPlus1,DrPlus1,Patrat1);
          if (MaiMicEgal(Patrat,X)&& MaiMic(X,Patrat1)){
             Rad=Dr;
             return;
          }
                                                ///cautare binara, St=Prefix, Dr=Mare
          Numar M;


          while (MaiMic(St,Dr)){
              Numar MPlus1,MMinus1,MProd,MProd1;
              Medie(St,Dr,M);                       /// M=(St+Dr)/2
              Multiply(M,M, MProd);
              Aduna1(M,MPlus1);
              Multiply(MPlus1,MPlus1,MProd1);
              if(MaiMicEgal(MProd,X)&& MaiMic(X,MProd1)){
                cout<<"\nM^2:      ";AfisNumar(MProd);cout<<"<< X=     ";AfisNumar(X);cout<<"<(M+1)^2=";AfisNumar(MProd1);cout<<endl;
                cout<<"Lungimea lui M^2:"<<MProd.L<<endl;
                cout<<"Lungimea lui X:"<<X.L<<endl;
                cout<<"Lungimea lui (M+1)^2:"<<MProd1.L<<endl;
                cout<<endl;
                Rad=M;
                return;
               }
              if(MaiMicEgal(MProd,X)) {
                    Aduna1(M,MPlus1);
                    St=MPlus1;
                    cout<<"Limita  stanga=";
                    AfisNumar(St);
                    cout<<"Limita dreapta=";
                    AfisNumar(Dr);
              }
              else{
                    Scade1(M,MMinus1);
                    Dr=MMinus1;
                    cout<<"Limita  stanga=";
                    AfisNumar(St);
                    cout<<"Limita dreapta=";
                    AfisNumar(Dr);

              }

              Medie(St,Dr,M);                   ///recalculam media cu noile valori St si Dr
          }
          Rad=St;
          return;
     }

}

int AfisMeniu(){

    int Opt;
    cout<<"\n1.Citeste numar lung";
    cout<<"\n2.Calcul Radical";
    cout<<"\n0.Terminare program";
    cout<<"\nOptiunea ta(0,1,2,3):";
    cin >>Opt;
    return Opt;
}

int main()
{
    int Opt=AfisMeniu();
    while(Opt){
        switch (Opt){
            case 1: Numar M,Rad;
                    Citire("da un numar natural:",M);
                    break;
            case 2: Radical(M,Rad);
                    cout<<endl<<"radical din ";
                    AfisNumar(M);
                    cout<<"=";
                    AfisNumar(Rad);
                    cout<<endl;
                    break;
            default:cout<<"\nAi gresit optiunea!!!";
        }
       Opt=AfisMeniu();
    }
    cout <<"\nProgram terminat\n";
    return 0;
}
