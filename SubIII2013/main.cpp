#include <iostream>

using namespace std;
struct Cuplu{
    long y;
    long f;
};

///Descr.- citeste valorile unui vector
///In  -
///Out - X[i],i=1...n, si n

void Citire(long x[],int &n)
{
    n=0;                            ///se citeste o valoare v
    long v=0;
    do{
        cout<<"da valoare:";
        cin>>v;
        if(v>0) x[++n]=v;           ///daca v este pozitiv se introduce in vector
    }while(v!=0);
}
///Descr, -Determina primalitatea unui numar
///In  -x
///Out -true daca x e prim
///    -false daca x nu e prim

bool Prim(long x)
{
    if(x<2) return false;                   ///se verifica divizibilitatea cu 3,5,...rad(x)
    if(x>2 && x%2==0) return false;
    for(long i=3;i*i<=x;i=i+2)
        if(x%i==0)  return false;
    return true;
}

///Descr. -Det. suma cifrelor unui numar
///In -n nat
///Out-suma cifrelor lui n
long SumCif(long n)
{
    long s=0;
    while(n)                    ///se aduna cifra cu cifra incepand de la ultima
    {
        s=s+n%10;
        n=n/10;
    }
    return s;
}

///Descr. Verifica daca o valoare v se afla/nu se afla in vectorul Y
///In  -Y,vectorul de valori si frecvente
///    -k lungimea lui Y
///    -v valoarea de cautare
///Out -poz>0, s-a gasit v in Y
///    -poz=0, v nu este in Y
int Exista(Cuplu Y[],int k,int v)
{
    for(int i=1;i<=k;i++)              ///cautare secventiala
        if(v==Y[i].y) return i;
    return 0;
}

///Descr. -Adauga crescator valoarea v in Y
///In -Y,vectorul de valori si frecvente, ordonat crescator dupa valori
///   -k, lungimea lui Y
///   -v valoarea ce se adauga
///Out-Y,vectorul de valori si frecvente, ordonat crescator dupa valori

void Adauga(Cuplu Y[],int &k,int v)
{
    int j=k;
    while(j>0 && v<Y[j].y)
    {
        Y[j+1].y=Y[j].y;        ///Se parcurge Y de la k,k-1,...,1 si se adauga v pe poz corespunzatoare
        Y[j+1].f=Y[j].f;        ///se muta si valoarea si frecventa lui Y[j] pe  pozitia urmatoare
        j--;
    }
    Y[j+1].y=v;
    Y[j+1].f=1;
    k++;
}

///Descr. -Creeaza vectorul Y de valori si frecventa
///In  -x[i],i=1,...,n si n lungimea
///Out -Y[i],i=1,...,k si k
void Creare(long x[],int n, Cuplu Y[],int &k)
{
    k=0;
    for(int i=1;i<=n;i++)
      {if(Prim(SumCif(x[i])))
          {
            int poz=Exista(Y,k,x[i]);
            if(poz>0)   Y[poz].f++;
            else        Adauga(Y,k,x[i]);

          }
      }
}
///Descr. -Afiseaza vectorul Y de valori si frecventa
///In  -Y si k lungimea
///Out -se afiseaza pe ecran cuplurile(val,frec)

void AfisareY(Cuplu Y[], int k)
{   cout<<endl;
    cout<<"Vectorul de val si frec este Y=(";
    for(int i=1;i<=k-1;i++ )
        cout<<"("<<Y[i].y<<","<<Y[i].f<<"),";
    cout<<"("<<Y[k].y<<","<<Y[k].f<<"))"<<endl<<endl;
}


int main()
{
   int   n, k;                    /// n lungime lui x, k lungime lui Y
   long  x[100];                 /// vectorul x ce se va citi
   Cuplu Y[100];                /// vectorul Y de cupluri ce se va crea
   Citire(x,n);
   Creare(x,n,Y,k);
   AfisareY(Y,k);
   cout<<"Program terminat";
   return 0;
}
