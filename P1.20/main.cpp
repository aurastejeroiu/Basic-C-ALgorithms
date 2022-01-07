#include <iostream>

using namespace std;

int main()              //a/b si c/d sa aiba acelasi semn
{  long a,b,c,d;
   cout<<"numitorii sa fie pozitivi\n";
   cout<<"da a:";
   cin >>a;
   cout<<"da b:";
   cin >>b;
   cout<<"da c:";
   cin >>c;
   cout<<"da d:";
   cin >>d;
   if(a*d>b*c) cout<<a<<"/"<<b<<" > "<<c<<"/"<<d;
   else  if(a*d==b*c) cout<<a<<"/"<<b<<" = "<<c<<"/"<<d;
         else cout<<c<<"/"<<d<<" > "<<a<<"/"<<b;
   return 0;
}
