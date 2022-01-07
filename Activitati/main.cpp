#include <iostream>
#include <fstream>
#include <values.h>
#define nn 100
#define MAXINT 9999

using namespace std;

/* Se dau n activitati prin intervale de timp: (s1,f1)...(sn,fn)
   O submultime maximala de activitati care nu se intersecteaza
*/

int S[nn+1], F[nn+1], n;
int A[nn+1];

bool Inter2(int a, int b, int c, int d){
   int Max=a>c?a:c;
   int Min=b<d?b:d;
   if(Max>=Min) return true;
   return false;
}

bool InterK(int &k, int A[], int a, int b){

   for(int j=1;j<=k;j++)
     if (!Inter2(S[A[j]],F[A[j]],a,b)) return false;
   return true;
}
void Adauga(int &k, int A[], int i){
  A[++k]=i;
}
void Inter(int I0,int &k, int A[])
{ k=0;
  A[++k]=I0;
  for(int i=1;i<=n;i++){
     if (i!=I0 && InterK(k,A,S[i],F[i]))
         Adauga(k,A,i);
  }

}


void citestematrice(void)
{ cout<<"da numarul de intervale:";
  cin >>n;
  ifstream fin("Cupluri.txt");
  for(int i=1;i<=n;i++){
       fin>>S[i];
       fin>>F[i];
  }
}

void afiseaza(int k,int A[])
{  for(int i=1;i<=k;i++)
     cout<<A[i]<<" ";
}

int main(void)
{ int vdlm, I0;
  citestematrice();
  int k;
  cout<<"da varful de inceput:";
  cin >>I0;
  Inter(I0,k,A);
  afiseaza (k,A);
  return 0;
}
