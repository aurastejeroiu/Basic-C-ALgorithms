#include <iostream>

using namespace std;

int DistZero(long n, int X[]){   /// X este vect. de frecv. al cifrelor
  int i;
  while(n){
    X[n%10]++;
    n/=10;
  }
  if(X[0]>0) return 0;
  for(i=1; i<=9;i++)
    if(X[i]>1) return 0;
  return 1;
}

int Deosebit(long n){
   int X[10]={0};
   if (DistZero(n,X))
      {for(int i=1;i<=9;i++)        ///se verifica si divizibilitatea
        {if(X[i]>0)
           if(n%i!=0) return 0;
        }
       return 1;
      }
   else return 0;
}
int main()
{   for(long i=12;i<=9876543;i++)
       if(Deosebit(i)) cout<<i<<" ";
    cout << "\nHello world!" << endl;
    return 0;
}
