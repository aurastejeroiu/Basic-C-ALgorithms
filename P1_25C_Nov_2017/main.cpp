#include <iostream>

using namespace std;
struct Cuplu{
   int x;
   int y;
};
void CitireA(int &n, int A[]){
    n=0;
    int X;
    do{
      cout<<"mai da un numar:";
      cin >>X;
      if(X>0) A[++n]=X;
    }
    while(X!=0);
}
int Modul(int x){
    if(x<0) return -x;
    return x;
}
bool Prim(int n){
   if (n<2)   return false;
   if (n==2)  return true;
   if (n%2==0)return false;
   for(int d=3; d*d<=n; d+=2)
     if(n%d==0) return false;
   return true;
}

void Schimba(int &x, int &y){
   int aux=x;
         x=y;
         y=aux;
}

bool EsteInR(int x, int y, int k, Cuplu R[]){
   if(x>y) Schimba(x,y);
   for(int i=1;i<=k;i++)
     if(R[i].x==x and R[i].y==y) return true;   ///am gasit cuplul de twins
   return false;                                ///(x,y) nu e in R
}

void Adauga(int &k, Cuplu R[], int x, int y){
   if(x>y) Schimba(x,y);
   int i=k;
   while(i>0 and x<R[i].x){
       R[i+1].x=R[i].x;
       R[i+1].y=R[i].y;
       i--;
   }
   R[i+1].x=x;
   R[i+1].y=y;
   k++;
}

void CrereR(int n, int A[], int &k, Cuplu R[]){
   k=0;
   for(int i=1;i<n;i++)
      for(int j=i+1;j<=n;j++){
        if(Modul(A[i]-A[j])==2 and Prim(A[i]) and Prim(A[j]) )
            if(!EsteInR(A[i],A[j],k,R)) Adauga(k,R,A[i],A[j]); ///daca (A[i],A[j]) nu e in R se adauga in R
   }
}
void AfisR(int k, Cuplu R[]){
  if(k==0) cout<<" nu exista cupluri de gemene prime";
  else
    for(int i=1; i<=k; i++)
      cout<<"("<<R[i].x<<","<<R[i].y<<") ";
}

int main()
{   int n, A[100];          ///n lung lui A
    int k; Cuplu R[100];    ///k lung sirului de perechi
    CitireA(n,A);
    CrereR (n,A,k,R);
    AfisR  (k, R);
    cout << "\nProgram terminat" << endl;
    return 0;
}
