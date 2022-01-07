#include <iostream>

using namespace std;
///  Se dau a,n naturale si sirul X de n elemente. Sa se rearanjeze elementele astfel incat
///  toate numerele <a sa fie inaintea tuturor celor >= a, fara a ordona tot sirul.
///

void Schimb (int &a, int &b){
 int aux = a;
     a   = b;
     b   = aux;
}
void Afisare(int n, int a, int X[]){
    cout<<"elementele aranjate in functie de a:";
    for(int i=1; i<=n;i++)
        cout<<X[i]<<" ";
    cout<<endl;
}

void FataDeA(int n, int a,int x[])
{
    int start=1, finish=n;
    while(start<finish){
        while(x[start]<a) start++;   ///cautarea unui element mai mare decat a
        while(x[finish]>a) finish--; ///cautarea unui element mai mic decat a
        if(start<finish){            ///interschimbarea valorilor
            int aux=x[start];
            x[start]=x[finish];
            x[finish]=aux;
            start++;
            finish--;
        }
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


int main()
{   int X[100];
    int n,a;
    Citire  (n,a,X);
    FataDeA (n,a,X);
    Afisare (n,a,X);
    cout<<endl;
    return 0;
}
