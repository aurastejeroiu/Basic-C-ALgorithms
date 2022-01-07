#include <iostream>
#include <iomanip>

using namespace std;
/// Sortare prin selectie, varianta simplificata
/// Abordare recursiva


void CitSecventa(int& Dim, long V[]){
   cout<<"da dim.:";
   cin >>Dim;
   for(int i=1;i<=Dim;i++){
     cout<<"V["<<i<<"]=";
     cin >>V[i];
   }
}

void Swap(long& a,long& b){
  long  X=a;
        a=b;
        b=X;
}

void SelectR(int Dim, long V[], int i, int j, int iMin){
   if(i<Dim)
      if(j<=Dim){
        if(V[j]<V[iMin]) iMin=j;
        SelectR(Dim,V,i,j+1,iMin);
      }
      else{
         Swap(V[i],V[iMin]);
         SelectR(Dim,V,i+1,i+2,i+1);
      }

}


void AfisSecv(int Dim, long V[]){
    cout<<"secventa sortata:";
    for(int i=1;i<=Dim;i++)
        cout<<setw(5)<<V[i];
}

int main()
{   int          Dim;
    long         V[1000];
    CitSecventa  (Dim, V);
    SelectR      (Dim,V,1,2,1);
    AfisSecv     (Dim,V);
    cout        << endl<<"Programul s-a terminat" << endl;
    return 0;
}

