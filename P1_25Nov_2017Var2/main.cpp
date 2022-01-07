#include <iostream>

using namespace std;

struct Pereche
{  long p1,p2;
};

void CitireA(int &n, long A[]);
void CreareR(int n, long A[], int &k, Pereche R[]);
void AfisR  (int k, Pereche R[]);

int main()
{  long A[1000];
   int n,k;
   Pereche R[1000];
   CitireA (n,A);
   CreareR (n,A,k,R);
   AfisR   (k,R);
   cout<<"Program terminat";
   return 0;
}

void CitireA (int &n,long A[])
{   long x;
    n=0;
    do
    { cout<<"mai da un numar:";
      cin>>x;
      if (x>0) A[++n]=x;
    }while (x!=0);
}

int Modul (long x)
{ if(x<0) return -x;
          return x;
}

bool Prim (long n)
{  if (n<2)    return false;
   if (n==2)   return true;
   if (n%2==0) return false;
   for (long d=3;d*d<=n;d+=2)
        if (n%d==0) return false;
   return true;
}

void Schimb (long &p1,long &p2)
{ long aux=p1;
        p1=p2;
        p2=aux;
}

bool Exista (long p1,long p2,int k,Pereche R[])
{   if (p1<p2) Schimb(p1,p2);
    int i=1;
    while (i<=k && R[i].p1!=p1)
        i++;
    if (i>k)    return false;
                return true;
}

void Adauga (int &k,Pereche R[],long p1,long p2)
{   k++;
    R[k].p1=p1;
    R[k].p2=p2;
}

void CreareR (int n,long A[],int &k,Pereche R[])
{   k=0;
    for (int i=1;i<n;i++)
      for (int j=i+1;j<=n;j++)
        {   if (Modul(A[i]-A[j])==2 && Prim(A[i]) && Prim(A[j]))
                if (!Exista(A[i],A[j],k,R))  Adauga(k,R,A[i],A[j]);
        }
}

void AfisR (int k,Pereche R[])
{ if (k==0) cout<<"nu exista perechi gemene prime";
  else
     for (int i=1;i<=k;i++)
            cout<<"("<<R[i].p1<<","<<R[i].p2<<")";
}
