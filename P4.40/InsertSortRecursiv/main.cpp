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

void InsertRec(int n,int i, int j,int x[], int aux){  ///apelul cu i=2, j=1, aux=x[2]
    if(i<=n)
       if(j>0 && aux < x[j]){
          x[j+1]=x[j];
          InsertRec(n,i,j-1,x,aux);
       }
       else {x[j+1]=aux;
             InsertRec(n,i+1,i,x,x[i+1]);
       }
}



int main()
{   int n;
    int v[100];
    cout<<"da nr de elemente"; cin>>n;
    citR(n,v);
    cout<<endl<<"afisare recursiva:\n";
    afisR(n,v);
    int i=2,j=1;
    InsertRec(n,i,j,v,v[2]);
    cout<<endl<<"afisare recursiva dupa sortare:\n";
    afisR(n,v);
    cout << "\nHello world!" << endl;
    return 0;
}




