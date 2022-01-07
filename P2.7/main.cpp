#include <iostream>

using namespace std;

int main()
{int x[]={5,4,6,3,45,54,43};
 int Im=1,IM=1;

 for(int i=1;i<7;i++)
    { if(x[i]<x[Im]) Im=i;
      if(x[i]>x[IM]) IM=i;
    }
 cout << "componenta de val minima se afla pe poz:" <<Im<<endl;
 cout << "componenta de val maxima se afla pe poz:" <<IM<<endl;
 return 0;
}
