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

void Bule(int Dim, long V[]){
   int i,Ok;
   do {
       Ok=0;
       for(i=1;i<Dim;i++)
         if(V[i]>V[i+1]){
                      Swap(V[i],V[i+1]);
                      Ok=1;
         }
   }
   while(Ok==1);
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
    Bule         (Dim,V);
    AfisSecv     (Dim,V);
    cout        << endl<<"Programul s-a terminat" << endl;
    return 0;
}

