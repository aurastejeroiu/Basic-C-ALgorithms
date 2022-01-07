#include <iostream>

using namespace std;
///  Se dau a,n naturale si sirul X de n elemente. Sa se creze vecorul Z astfel incat
///



void CreeZ(int n, int a, int X[], int Z[])
{ int Suma=0;
  int Max =X[1];
  for( int i=1;i<=n;i++){
     Suma+=X[i];
     if(X[i]>Max) Max=X[i];
     if(X[i]>a) Z[i]=Suma;
     else       Z[i]=Max;
  }
}

void Citire(int&n, int&a,int X[]){
    cout<<"cate numere dai:";
    cin >>n;                    ///citeste dimensiunea sirului
    for (int i=1;i<=n;i++)      ///citeste elementele sirului
    { cout<<"X["<<i<<"]=";
      cin >>X[i];
    }
    cout << "da reperul a:";    ///citeste valoarea a
    cin  >> a;

}
void Afisare(int n,int Z[]){
    cout<<"vectorul Z:";
    for(int i=1; i<=n;i++)
        cout<<Z[i]<<" ";
    cout<<endl;
}

int main()
{   int X[100],Z[100];
    int n,a;
    Citire  (n,a,X);
    CreeZ   (n,a,X,Z);
    Afisare (n,Z);
    cout<<endl;
    return 0;
}
