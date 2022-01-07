#include <iostream>

using namespace std;
///P1.1a In cate zerouri se termina produsul numerelor x[1]*...*x[n], fara a calcula efectiv
///        produsul.

///Idee: Un zero final este dat de 2*5, deci trebuie calculat min{2^Exp2,5^Exp5}
///      adica de cate ori toti factorii se divid cu 2 si 5.

void CitireDate(int &DimX, long X[]){
    cout <<"da numarul de factori:";
    cin  >>DimX;
    for (int i=1;i<=DimX;i++) {
        cout<<"X["<<i<<"]=";
        cin >> X[i];
    }
}

void DetExp2Exp5(int DimX, long X[], long &Exp2, long &Exp5){
    Exp2=0;
    Exp5=0;
    for(int i=1;i<=DimX;i++)
       { long aux=X[i];                 ///pentru a nu pierde valoare lui X[i] se foloseste o variabila auxiliara
         while (aux % 2==0) {
                Exp2++;
                aux/=2;                 ///aux se imparte cu 2
               }
         while (aux % 5==0) {
                Exp5++;
                aux/=5;                 ///aux se imparte cu 5
                }
       }
}
void Afisare(long Exp2, long Exp5){
    if(Exp2<Exp5) cout<<" produsul se termina in "<<Exp2<< " zerouri";
    else          cout<<" produsul se termina in "<<Exp5<< " zerouri";
}

int main()
{   long        X[100];
    int         n;
    long        Exp2,Exp5;
    CitireDate  (n,X);
    DetExp2Exp5 (n,X,Exp2,Exp5);
    Afisare     (Exp2,Exp5);
    cout <<     endl << "Program terminat" << endl;
    return 0;
}
