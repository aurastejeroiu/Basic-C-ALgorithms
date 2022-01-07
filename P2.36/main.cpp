#include <iostream>
#include <iomanip>

using namespace std;
///Se dau a,b cu  a<b din N si un sir X de n elemente intregi.
///Sa se elimine din sirul X, elementele dn intervalul [a,b]


void ElimA(int &n, int X[],int a, int b, int &k,int Y[])
{   k=0;
    int  i=1;
    for(i=1;i<=n;i++)
      { if(X[i]>=a && X[i]<=b )  Y[++k]=X[i]; ///trebuie pus x[i] in Y
      }
}

void Citire(int&n,  int X[],int&a, int&b){
    cout<<"cate numere dai:";
    cin >>n;                    ///citeste dimensiunea sirului
    for (int i=1;i<=n;i++)      ///citeste elementele sirului
    { cout<<"X["<<i<<"]=";
      cin >>X[i];
    }
    cout << "da capatul a:";    ///citeste valoarea a
    cin  >> a;
    cout << "da capatul b:";    ///citeste valoarea b
    cin  >> b;

}
void Afisare(int k, int Y[],int a, int b){
    if(k>0){                                    ///se afiseaza dor daca sirul X este nevid
      cout<<"numerele in intervalul ["<<a<<","<<b<<"] sunt:";
      for(int i=1; i<=k;i++) cout<<setw(5)<<Y[i];
    }
    else cout<<"sirul este vid";
    cout<<endl;
}

int main(){
    int     X[100],Y[100];
    int     n,a,b,k;
    Citire (n,X,a,b);         ///apel citire date
    ElimA  (n,X,a,b,k,Y);     ///apel mutare in Y x[i]>=a && x[i]<=b
    Afisare(k,Y,a,b);         ///afisare sir Y ramas
    return 0;
}


