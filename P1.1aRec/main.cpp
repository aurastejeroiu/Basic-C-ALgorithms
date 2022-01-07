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
long DetP(long Aux, long p, long ExpP){              ///Determina recursiv de cate ori Aux=X[i] se divide cu p
    if(Aux % p ==0) return DetP(Aux/p, p, ExpP+1);   ///Recusrsivitatea se face pentru Aux/p si incrementarea lui ExpP
    /* else*/       return ExpP;
}

long DetExpP(int DimX, long X[], long p, long ExpP){ ///Determina recursiv Exponentul lui p^ExpP
     if(DimX>0){                                     ///trecrea la urmatorul element din X
                long Aux=X[DimX];                    ///se face recursiv
                ExpP=DetP(Aux,p,ExpP);
                return DetExpP(DimX-1, X, p, ExpP);
     }
     /* else*/  return ExpP;
}

void Afisare(long Exp2, long Exp5){
    if(Exp2<Exp5) cout<<" produsul se termina in "<<Exp2<< " zerouri";
    else          cout<<" produsul se termina in "<<Exp5<< " zerouri";
}

int main()
{   long        X[100];
    int         n;
    long        Exp2=0, Exp5=0;
    CitireDate  (n,X);
    long        p=2;
    Exp2        =DetExpP(n,X,p,Exp2);
    p           =5;
    Exp5        =DetExpP(n,X,p,Exp5);
    Afisare     (Exp2,Exp5);
    cout <<     endl << "Program terminat" << endl;
    return 0;
}
