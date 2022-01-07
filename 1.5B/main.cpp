#include <iostream>

using namespace std;

long SumDiv(long n)
{ long S=n+1;
  for(long d=2; d*d<=n; d++)		//O(rad(n))
    if( n%d==0)   			        //S+=i+n/i;
        if(d==n/d) S+=d;
        else       S+=d+n/d;
  return S;
}
int main()
{ long a,b,i,S;
  cout<<"da a:";
  cin >>a;
  cout<<"da b:";
  cin >>b;
  for(i=a;i<=b-1;i++){
    S=SumDiv(i);
    cout<<i<<" ";
    for(long j=i+1;j<=b;j++)
        if(S==SumDiv(j)) cout<<j<<" ";
    cout<<endl;
  }

    cout << "Hello world!" << endl;
    return 0;
}
