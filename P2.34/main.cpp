#include    <iostream>
#include    <iomanip>
#include    <cmath>
using namespace std;
/* Se dau a, n din N si sirul X de n elemente. Sortati X crescator in functia
    de distanta fiecarui element fata de a
*/

void BubbleABS(int n, int a, int x[])
{
   int i,j,aux,ok,poz;
   j=n-1;                           //pozitia pana la care se compara
   do{
    ok=0;                           //Ok=0, inseamna ca nu am inca interschimbari
    for(i=1;i<=j;i++)
        if(abs(a-x[i])>abs(a-x[i+1]))
            {   aux     =x[i];
                x[i]    =x[i+1];
                x[i+1]  =aux;
                ok      =1;             //Ok=1, am facut cel putin o interschimbare
                poz     =i;             //in poz se retine pozitia de interschimbare
            }
    j=poz;                              //in j se retine ultim pozitie de interschimbare
   }while(ok);

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
    cout<<"sirul ordonat dupa distanta fata de "<<a<<":";
      for(int i=1; i<=n;i++) cout<<setw(5)<<X[i];
    cout<<endl;
}

int main()
{   int X[100];
    int n,a;
    Citire      (n,a,X);
    BubbleABS   (n,a,X);
    Afisare     (n,a,X);
    return 0;
}

