#include <iostream>

using namespace std;

int main()
{  long a,b,c,d;
   cout<<"da a:";
   cin >>a;
   cout<<"da b:";
   cin >>b;
   cout<<"da c:";
   cin >>c;
   cout<<"da d:";
   cin >>d;
   if(a*d>b*c) cout<<a<<"/"<<b<<" > "<<c<<"/"<<d;
   else        cout<<c<<"/"<<d<<" > "<<a<<"/"<<b;
   return 0;
}
