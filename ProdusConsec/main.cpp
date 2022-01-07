#include <iostream>

using namespace std;

void g(int n){

  for(int i=1;i*i<=n;i++)
    { int S=i;
      int j=i+1;
      while(S<n)
      {
        S*=j;
        j++;
      }
      if(S==n)
      {   cout<<n<<'=';
          for(int k=i;k<j;k++)
            cout<<k<<"*";
          cout<<"\b ";
          cout<<endl;
      }
    }
}

int main()
{   int n;
    cout << "da n:";
    cin  >>n;
    g(n);
    cout<<"\nProgram terminat";
    return 0;
}
