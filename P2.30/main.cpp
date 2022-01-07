#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
/* Se dau a din N si un sir X de n elemente intregi.
   Sa se determine indicele i (cel mic) pentru care X[i] este cel mai apropiat de a
*/

void GasireIndice(int n, int a, int X[], int&IMic)
{   IMic=1;                     ///initializare IMic cu 1
    for (int i=2;i<=n;i++)      ///se parcurge sirul X de la 2 la n
       if(abs(X[i]-a)<abs(X[IMic]-a)) IMic=i;


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
void Afisare(int a, int X[], int indice){
    cout<<"numarul cel mai apropiat de "<<a<<" este "<<X[indice]<<" pe pozitia:"<<indice;
    cout<<endl;
}

int main(){
    int X[100];
    int n,a,Ind;
    Citire      (n,a,X);        //apel citire date
    GasireIndice(n,a,X,Ind);    //Aflare cel mai mic indice
    Afisare     (a,X,Ind); //Afisare pozitia
    return 0;
}
