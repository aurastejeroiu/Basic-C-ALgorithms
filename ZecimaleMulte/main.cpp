#include <iostream>
//1.	Să se realizeze un program care determină primele n cifre din scrierea fracţiei subunitare k/m = 0.c1c2c3...
//      pentru k şi m numere naturale date (k<m).
//      Exemplu: pentru n=50 iar k=2 şi m=7 reprezentarea este: 0.285714285714285

using namespace std;

int main()
{   int cont,k,m,n;
    cout<<"da k:"; cin>>k;
    cout<<"da m:"; cin>>m;
    cout<<"cate zecimale:";cin>>n;
    cout<<"0.";
    cont=1;
    while(cont<=n){
        cout<< (k*10)/m;
        k=((k*10)%m);
        cont++;
    }
    cout << "Hello world!" << endl;
    return 0;
}
