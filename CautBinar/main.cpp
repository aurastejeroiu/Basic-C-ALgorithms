#include <iostream>

using namespace std;

int CautBinRec(int Ls, int Ld, int x[], int val){
  int m;
  m=(Ls+Ld)/2;
  if(val==x[m]) return m;
  if(Ls<=Ld)
    if(val<x[m]) return CautBinRec(Ls,m-1,x,val);
    else         return CautBinRec(m+1,Ld,x,val);
  return -1;
}
int CautBinar(int n, int x[], int val)
{ int ls,ld,m;
  ls=1;
  ld=n;
  m=(ls+ld)/2;
   while (ls<=ld && val!=x[m])
    {if(val<x[m]) ld=m-1;
     else         ls=m+1;
     m=(ls+ld)/2;
    }

  if(ls>ld) return -1;
  else      return m;
}

int main()
{ int x[]={0,750,678,565,45,33,2};
  int n=6,poz;
  int a=750;
  poz=CautBinar(n,x,a);
  if(poz>0) cout<<"val. cautata este pe poz:"<<poz;
  else      cout<<"val. cautata nu este in sir";
  cout<<endl;

  poz=CautBinRec(1,n,x,a);
  if(poz>0) cout<<"val. cautata este pe poz:"<<poz;
  else      cout<<"val. cautata nu este in sir";
  cout<<endl;
  cout <<endl << "Hello world!" << endl;
  return 0;
}
