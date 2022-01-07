#include <iostream>
using namespace std;
struct Dublet{
  int val;
  int fr;
};
void CitireX(int& n, int x[])
{ cout<<"da dim sirului:";
  cin >>n;
  for(int i=1; i<=n;i++)
  {  cout<<"x["<<i<<"]=";
     cin >>x[i];
  }
}
int ExistaInY(int k, Dublet y[100], int v)
{   int i=1;
    while(i<=k && v!=y[i].val) i++;
    if(i>k) return 0;
    else    return i;
}
void AdaugInY(int& k, Dublet y[100], int v)
{ k++;
  y[k].val=v;
  y[k].fr =1;
}
void CreY(int n, int x[], int& k, Dublet y[100])
{for(int i=1;i<=n;i++)
      { int poz=ExistaInY(k,y,x[i]);            ///retur 0 sau pozitia
        if(poz==0) AdaugInY(k,y,x[i]);          ///frecventa se pune pe 1
        else       y[poz].fr++;                 ///Y[poz].frecv++; mareste frecventa
      }
}
void AfisY (int k, Dublet y[100])
{  for(int i=1;i<=k;i++)
        cout<<"("<<y[i].val<<","<<y[i].fr<<") ";
}
int main()
{ int n,k=0;                //m e lungimea lui y, initial m=0
  int x[100];
  Dublet   y[100];
  CitireX(n,x);
  CreY   (n,x,k,y);
  AfisY  (k,y);
  cout << "Program terminat" << endl;
  return 0;
}
