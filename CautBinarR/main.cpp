#include <iostream>

using namespace std;

int CB(int n, int x[], int val)
{ int ls,ld,m;	//n lungimea lui x
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
{   int V[]={0,2,4,5,7,8,10,13,15,16};
    cout<<CB(9,V,9);
    cout <<endl<<"Program terminat" << endl;
    return 0;
}
