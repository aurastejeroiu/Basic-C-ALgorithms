#include <iostream>

using namespace std;
bool CifraInB(short Cifra, long Numar){
  while (Numar>0 && (Cifra!=(Numar%10)))
     Numar=Numar/10;
  if(Numar==0) return false;
               return true;
}

bool CifreAinB(long A, long B){
    short UcifA;
    while (A>0) {
      UcifA = A % 10;
      if (!CifraInB(UcifA,B)) return false;
      A=A /10;
    }
    return true;
}
 bool Asemenea(long X, long Y){
   	if (CifreAinB(X,Y) && CifreAinB(Y,X)) return true;
                                          return false;
 }

int main()
{   long A,B;
    cout<<"Da primul numar:";
    cin >>A;
    cout<<"Da al 2-lea numar:";
    cin >>B ;
    if (Asemenea(A,B)) cout<<"Numerele sunt asemenea!";
    else               cout<<"Numerele nu sunt asemenea!";
    cout << "\nProgram terminat" << endl;
    return 0;
}
