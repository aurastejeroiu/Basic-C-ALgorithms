#include <iostream>

using namespace std;

int EgaleCu(int n,int x[],int val) {
  int cnt=0;
  for(int i=1;i<=n;i++)
    if(val==x[i])
  cnt++;
  return cnt;
}

int MaxiI(int n,int x[],int poz)
{ int max=x[poz];
  for(int i=poz+1;i<=n;i++)
        if(x[i]>max) max=x[i];
  return max;
}

void crey(int n,int x[],int y[])
{ for(int i=1;i<=n;i++)
    if(i%2==0) y[i]=MaxiI(n,x,i);
    else       y[i]=EgaleCu(n,x,x[i]);
}

void afisy(int n,int y[])
{ for(int i=1;i<=n;i++)
    cout<<y[i]<<" ";
}

int main()
{ int x[100],n,y[100];
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>x[i];
  crey(n,x,y);
  afisy(n,y);
  return 0;
}
