#include <iostream>

using namespace std;

int Progresie (int X[], int n){
   int i=2;
   while(i<n && X[i]*2==X[i-1]+X[i+1]) i++;
   if(i==n) return 1;
   i=2;
   while(i<n && X[i]*X[i]==X[i-1]*X[i+1]) i++;
   if(i==n) return 2;
   return 3;
}


int main()
{ int x[]={0,1,2,3,4,5};
   int  n,cod;
   n    =5;
   cod Progresie(X,n);
   if(cod==1) cout<<"Prgresie arit.\n";
   else   if(cod==2) cout <<"Progresie geometrica\n";
          else       cout <<"n-am progresie";
   return 0;
}

