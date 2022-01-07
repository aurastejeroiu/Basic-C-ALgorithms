#include <iostream>

using namespace std;

int main()
{   int m,n,d,c,i;
    cout<<"da numitorul:";
    cin >>m;
    cout<<"da numarul de zecimale:";
    cin >>n;
    d=1;
    i=1;
    cout<<"0.";
    while(i<=n)
    { c=d*10/m;
      cout<<c;
      d=d*10-c*m;
      i++;
    }
    cout <<endl<< "Program terminat" << endl;
    return 0;
}
