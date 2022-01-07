#include <iostream>

using namespace std;

int main()
{   int j,S,n;
    cout << "da n:";
    cin  >> n;

    for(int i=1;i*i<=n;i++)
    { S=i;
      j=i;
      while(S<n)
      { j++;
        S*=j;
      }
      if(S==n)
      {   cout<<n<<"=";
          for(int k=i;k<=j;k++)
            cout<<k<<"*";
          cout<<"\b "<<endl;
      }
    }


    return 0;
}
