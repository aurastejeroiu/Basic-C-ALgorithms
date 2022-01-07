#include <iostream>

using namespace std;

void CitireDate(int&n, int X[]){
   cout<<"cate elem:"; cin>>n;
   for(int i=1;i<=n;i++){
      cout<<"x["<<i<<"]=";
      cin >>X[i];
   }

}
void InsDes (int &m, int Y[], int aux){ ///inserare descrescator
   int i=m;
   while(i>0 && aux>Y[i]){
      Y[i+1]=Y[i];
      i--;
   }
   Y[i+1]=aux;
   m++;
}
void CreVF(int a, int VF[10]){
   while(a>0){
     VF[a%10]++;
     a/=10;
   }
}
int Distincte(int a,int VF[10]){
   int nou=0;
   int p=1;
   while(a>0){
      int c=a%10;
      if(VF[c]==1){
        nou=nou+c*p;
        p=p*10;
      }
      a=a/10;
   }
   return nou;
}

void CreY(int n, int X[], int Y[]){
  int m=0;                      ///m lungimea lui Y, initial  =0;
  for(int i=1;i<=n;i++) {
     int VF[10]={0};            /// vectorul de frecv initializat cu 0
     CreVF(X[i],VF);            ///crearea vectorului de frecventa pentru fiecare X[i]
     int aux=Distincte(X[i],VF); ///construire unui aux cu cifre distincte
     InsDes(m,Y,aux);            ///inserarea descrescatoare lui aux in Y
  }
}

void AfiSir(int n, int X[], char c[20]){
   cout<<endl<<c<<endl;
   for(int i=1;i<=n;i++)
        cout<<X[i]<<" ";
   cout<<endl;
}

int main()
{   int n, X[100], Y[100];
    CitireDate(n,X);
    CreY      (n, X, Y);
    AfiSir    (n,X,"sirul initial X:");
    AfiSir    (n,Y,"sirul Y:");
    cout <<   "\nProgram terminat" << endl;
    return 0;
}
