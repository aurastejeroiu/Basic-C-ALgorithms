#include <iostream>

using namespace std;

void CitireDate(int&n, int X[], int &a){
   cout<<"cate elem:"; cin>>n;
   for(int i=1;i<=n;i++){
      cout<<"x["<<i<<"]=";
      cin >>X[i];
   }
   cout<<"Da a=";
   cin >>a;
}

int DeterminaR (int n, int X[], int a, int &cont ){
    int r=0;
    cont=0;
    for(int i=1;i<=n;i++)
        {if(X[i]>=a) cont++;             ///se determina cate valori sunt mai mari a
         if(r==0 && X[i]==a) r=i;        ///primul indice r, (r=i) pentru care x[i]=a
        }
    return r;

}

int main()
{   int n, X[100], a, r;
    CitireDate(n,X,a);
    r=DeterminaR(n, X, a);
    if(r==0) cout<<"nu exista nici o valoare mai mare ca "<<a;
    else     cout<<r<<" valori mai mari ca "<<a;
    cout << "\nProgram terminat" << endl;
    return 0;
}
