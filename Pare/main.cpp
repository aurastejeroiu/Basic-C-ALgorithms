#include <iostream>

using namespace std;

long Pare(long x)
{ if(x==0) return 0;
  else if(x%2==0) return Pare(x/10)*10+x%10;
       else       return Pare(x/10);
}

int main()
{
    cout << Pare(1284638)<< endl;
    return 0;
}
