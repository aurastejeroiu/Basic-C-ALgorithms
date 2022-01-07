#include <iostream>

using namespace std;
/*  Se dau a,n naturale si sirul X de n elemente. Sa se rearanjeze elementele astfel incat
    toate numerele <a sa fie inaintea tuturor celor >= a, far a ordona tot sirul.

*/

void FataDeA(int n, int a,int x[])
{ int i,j, aux;
  for(i=1; i<=n;i++)
    if(x[i]>=a)                         //daca x[i]>a atunci se cauta de la el inspre dreapta primul
        { j=i+1;                        //numar <a, cu care il interschimb
          while(j<=n && x[j]>=a) j++;   //gaseste primul x[j] <=a
          if(x[j]<a) { aux  =x[i];
                       x[i] =x[j];
                       x[j] =aux;
                     }
         }
                                        // se trece la urmatorul indice i pentru x[i]<a
}

void Citire(int&n, int&a,int X[]){
    cout<<"cate numere dai:";
    cin >>n;                    //citeste dimensiunea sirului
    for (int i=1;i<=n;i++)      //citeste elementele sirului
    { cout<<"X["<<i<<"]=";
      cin >>X[i];
    }
    cout << "da reperul a:";    //citeste valoarea a
    cin  >> a;

}
void Afisare(int n, int a, int X[]){
    cout<<"elementel aranjate in functie de a:";
    for(int i=1; i<=n;i++)
        cout<<X[i]<<" ";
    cout<<endl;
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
