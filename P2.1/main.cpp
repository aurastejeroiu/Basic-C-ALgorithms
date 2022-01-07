#include <iostream>
using namespace std;

void DivN(long n, long d){
  if(d*d>n) {cout<<"1,"<<n<<endl;
             }
  else
   {  if(n%d==0)
         if(n/d==d) {cout<<d<<",";           DivN(n,d+1);}
         else       {cout<<d<<","<<n/d<<","; DivN(n,++d);}
      else DivN(n,d+1);
   }
}

int main()
{   long n;
    cout<<"da n:";
    cin >>n;
    DivN(n,2);
    cout << "Program terminat" << endl;
    return 0;
}
