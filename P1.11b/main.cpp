#include <iostream>
#include <iomanip>
using namespace std;

//P1.11. Sa se determine toate numerele naturale de 3 cifre abc cu proprietatea
//       abc=a^3+b^3+c^3

int main()
{   for (long a=1;a<10;a++)
      for(long b=0;b<10;b++)
        for(long c=0;c<10;c++)
          if (a*a*a+b*b*b+c*c*c==100*a+10*b+c) cout<<a<<b<<c<<endl;
    cout << "Program terminat" << endl;
    return 0;
}
