#include <iostream>
#include <iomanip>

using namespace std;
/// Sortare prin selectie, varianta simplificata
/// Abordare recursiva


void CitSecventa(int& Dim, int V[]){
   cout<<"da dim.:";
   cin >>Dim;
   for(int i=1;i<=Dim;i++){
     cout<<"V["<<i<<"]=";
     cin >>V[i];
   }
}

void InsertR(int n, int X[],int i, int j, int Aux)
{ if(i<=n)
     if(j>0 && Aux<X[j])
         { X[j+1]=X[j];
           InsertR(n,X,i,j-1,Aux);
         }
        else
         { X[j+1]=Aux;
           InsertR(n,X,i+1,i,X[i+1]);
         }
}




void AfisSecv(int Dim, int V[]){
    cout<<"secventa sortata:";
    for(int i=1;i<=Dim;i++)
        cout<<setw(5)<<V[i];
}

int main()
{   int          Dim;
    int          V[1000];
    CitSecventa  (Dim, V);
    InsertR      (Dim,V,2,1,V[2]);
    AfisSecv     (Dim,V);
    cout        << endl<<"Programul s-a terminat" << endl;
    return 0;
}

