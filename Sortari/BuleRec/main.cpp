#include <iostream>
#include <iomanip>

using namespace std;
/// Sortare prin selectie, varianta simplificata
/// Abordare recursiva


void CitSecventa(int& Lung, long V[]){
   cout<<"da Lung.:";
   cin >>Lung;
   for(int i=1;i<=Lung;i++){
     cout<<"V["<<i<<"]=";
     cin >>V[i];
   }
}

void Swap(long& a,long& b){
  long  X=a;
        a=b;
        b=X;
}

void Bule(int Lung, long V[]){
   int i,Ok;
   do {Ok=0;
       for(i=1;i<Lung;i++)
         if(V[i]>V[i+1]){
                      Swap(V[i],V[i+1]);
                      Ok=1;
         }
   }
   while(Ok==1);
}

void BuleRec(int Lung, long V[],int i,int Ok){
   if(i<Lung)
   { if(V[i]>V[i+1])
       {  swap(V[i],V[i+1]);
          Ok=1;
       }
       BuleRec(Lung,V,i+1,ok);
   }
   else
    if(Ok==1) BuleRec(Lung,V,1,0);

}


void AfisSecv(int Lung, long V[]){
    cout<<"secventa sortata:";
    for(int i=1;i<=Lung;i++)
        cout<<setw(5)<<V[i];
}

int main()
{   int          Lung;
    long         V[1000];
    CitSecventa  (Lung, V);
    BuleRec      (Lung,V,1,0);
    AfisSecv     (Lung,V);
    cout        << endl<<"Programul s-a terminat" << endl;
    return 0;
}

