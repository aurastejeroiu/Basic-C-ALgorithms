#include <iostream>

using namespace std;

int CautBinar(int n, int x[], int val)
{ int ls,ld,m;
  ls=1;
  ld=n;
  m=(ls+ld)/2;
   while (ls<ld && val!=x[m])
    {if(val<x[m]) ld=m-1;
     else         ls=m+1;
     m=(ls+ld)/2;
    }

  if(ls>ld) return 0;
  else      return m;
}

int main()
{ int x[]={-100,2,33,45,565,678,75};
  int n=6,poz;
  poz=CautBinar(n,x,2);
  if(poz) cout<<"val. cautata este pe poz:"<<poz;
  else    cout<<"val. cautata nu este in sir";
  cout <<endl << "Hello world!" << endl;
  return 0;
}
