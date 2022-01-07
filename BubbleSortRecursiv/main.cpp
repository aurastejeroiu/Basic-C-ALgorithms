#include <iostream>
#include <iomanip>
using namespace std;

void afisR(int n, int v[]){
   if(n>0)
      {afisR(n-1,v);
       cout<<setw(4)<<v[n];
      }
}

void citR(int n, int v[]){
   if(n>0)
     {citR(n-1,v);
      cout<<"v["<<n<<"]=";
      cin >> v[n];
     }
}
void Schimb(int &x, int &y)
{   int aux;
    aux=x;
    x=y;
    y=aux;
}

void BubleRec (int n,int x[], int i, int Ok){  ///apelul cu i=1, Ok=1
    if(i<n){
        if(x[i]>x[i+1]) {
            Schimb(x[i],x[i+1]);
            Ok=0;
        }
        BubleRec(n,x,i+1,Ok);
    }
    if(Ok==0) BubleRec(n,x,1,Ok=1);
}

int main()
{   int n;
    int v[10];
    cout<<"da nr de elemente"; cin>>n;
    citR(n,v);
    cout<<endl<<"afisare recursiva:\n";
    afisR(n,v);
    BubleRec(n,v,1,1);
    cout<<endl<<"afisare recursiva dupa sortare:\n";
    afisR(n,v);
    cout << "\nHello world!" << endl;
    return 0;
}




