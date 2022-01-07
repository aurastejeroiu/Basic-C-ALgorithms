#include <iostream>
#include <iomanip>

using namespace std;
/* Se dau a din N si un sir X de n elemente intregi.
   Sa se elimine din sirul X, elementele mai mici decat a
*/

int ElimA(int &n, int a, int X[])
{   int  i=1;
    while(i<=n)         //se parcurge sirul X de la 1 la n
    { if(X[i]<=a)       //trebuie eliminat x[i]
        { int j=i;      //toate elemntele de la j=i,...n-1 se muta la stanga cu o pozitie
          while(j<n)
            {  X[j]=X[j+1];
               j++;
            }
            n--;        //scade dimensiunea lui X cu o unitate
        }
        else i++;       //se mareste i doar cand x[i]>a
    }
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
    if(n>0){                                    //se afiseaza dor daca sirul X este nevid
      cout<<"numerele mai mari ca "<<a<<" sunt:";
      for(int i=1; i<=n;i++) cout<<setw(5)<<X[i];
    }
    else cout<<"sirul este vid";
    cout<<endl;
}

int main(){
    int X[100];
    int n,a;
    Citire (n,a,X);         //apel citire date
    ElimA  (n,a,X);         //apel eliminare x[i]<a
    Afisare(n,a,X);         //afisare sir ramas
    return 0;
}


