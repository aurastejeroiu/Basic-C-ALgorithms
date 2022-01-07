#include <iostream>

using namespace std;

int cml (int n,int x[], int i) //returneaza j, cea mai lunga rampa locala (nu globala)
{  int j=i;
   while(j<n && x[j]<x[j+1])
        j++;
   return j;
}

void lungaRampa(int n, int x[],int &st, int&dr)
{     int i,j;
      i=1;
      while(i<n)
      {   while(i<n && x[i]>=x[i+1]) i++; //se sare peste numerele car nu formeaza rampa
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
    int n=10,x[]={0,5,7,2,4,6,11,4,13,15},st,dr;
    st=dr=0;
    lungaRampa(n-1,x,st,dr);
    if(dr-st>0)
        for(int i=st;i<=dr;i++)
            cout<<x[i]<<" ";
    else cout<<"nu exista secventa impare";



    return 0;
}
