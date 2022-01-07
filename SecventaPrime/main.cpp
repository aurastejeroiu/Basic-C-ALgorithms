#include <iostream>

using namespace std;

bool prim(int n)
{
    if(n<2)return false;
    if(n>2 && n%2==0) return false;

    for(int d=3;d*d<=n;d+=2)
    {
        if(n%d==0) return false;
    }

    return true;
}

int cml (int n,int x[], int i) //returneaza j
{  int j=i;
   while(j<=n && prim(x[j]))
     j++;
   return j-1;
}

void lungaImp(int n, int x[],int &st, int&dr)
{     int i,j;
      i=1;
      while(i<=n)
      {   while(i<=n && !prim(x[i])) i++; //se sare peste numerele pare
          j=cml(n,x,i);
          if (j-i>dr-st)
          {  st=i;
             dr=j;
          }
          i=j+1;
      }

}
int main()
{
    int n=10,x[]={0,1,5,7,2,4,11,4,13,15},st,dr;
    st=dr=0;
    lungaImp(n-1,x,st,dr);
    if(dr-st>0)
        for(int i=st;i<=dr;i++)
            cout<<x[i]<<" ";
    else cout<<"nu exista secventa impare";



    return 0;
}
