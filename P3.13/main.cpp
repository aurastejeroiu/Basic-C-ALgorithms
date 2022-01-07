#include <iostream>

using namespace std;


struct Numar{           ///reprezentarea numarului in vector, in oglinda
   int C[100]={0};
   int lung=0;
};

void Afisare (Numar S){
   //cout<<"lung="<<S.lung<<endl;
   for(int k=0;k<(15-S.lung);k++) ///afisare spatii pentru alinierea numerelor
      cout<<' ';
   for(int i=S.lung-1; i>=0; i-- ){
     cout<<S.C[i];
   }

  cout<<endl;
}

void InVector(long N, Numar& X){ //tranferare cifrele lui N in oglinda pe vector
  int i=0;
  while(N>0){
    X.C[i++]=N%10;
    N/=10;
  }
  X.lung=i;
}
void Suma(int b, Numar X, Numar Y, Numar& S)  {
  int i;                 ///cel mai mic (scurt) se compleaza cu 0
  if(X.lung<Y.lung)                 ///se adauga 0-uri la cel mai scurt numar
     {for(i=X.lung; i<Y.lung; i++)  ///daca X e mai scurt
          X.C[i]=0;
      X.lung=Y.lung;
      }
  else                             ///daca y e mai scurt
      {for(i=Y.lung; i<X.lung; i++)
          Y.C[i]=0;
       Y.lung=X.lung;
      }
   S.lung=X.lung;
   int T=0;                        ///suma cu transport
   for(i=0; i<X.lung;i++)
      { int Suma=T+X.C[i]+Y.C[i];
        S.C[i]=Suma % b;
        T=Suma/b;
      }
    if(T>0) { S.C[S.lung]=T;
              S.lung++;
            }
  }

 void EliminZero(Numar &D){
   while(D.C[D.lung-1]==0) D.lung--;
 }

 void Dif(int b, Numar X, Numar Y, Numar& D) ///X e mai lung ca Y
   { {for(int i=Y.lung; i<X.lung; i++)      ///se completeza cel mai scurt Y cu 0
          Y.C[i]=0;
       Y.lung=X.lung;
      }
     D.lung=X.lung;
     for(int i=0;i<X.lung; i++){
        if(X.C[i]>=Y.C[i]) D.C[i]=X.C[i]-Y.C[i];
        else { D.C[i]=b+X.C[i]-Y.C[i];
               X.C[i+1]--;
             }
     }
     EliminZero(D);
}

int main()
{   Numar X, Y, S,D;
    long x=127;
    long y=77777;
    int b=8;
    InVector(x,X);
    cout<<"X=";Afisare(X);
    InVector(y,Y);
    cout<<"Y=";Afisare(Y);
    Suma(b,X,Y,S);
    cout<<"S=";Afisare(S);
    cout<<endl;
    cout<<"Y=";Afisare(Y);
    cout<<"X=";Afisare(X);
    Dif(b,Y,X,D);
    cout<<"D=";Afisare(D);
    cout<<endl;

    cout << "\nProgram terminat" << endl;
    return 0;
}
