#include <iostream>
#include <iomanip>

using namespace std;


long MedRec (long n, long Max, long Min)            //elimina cifra maxima si cifra minima de pe fiecare pozitie
{ if(n==0) return 0;
  if((n%10 != Max) && (n%10 !=Min)) return MedRec(n/10,Max,Min)*10 + n%10;
  else                              return MedRec(n/10,Max,Min);
}

long CMax(long n,long Max)
{ if(n==0) return Max;
  if(n%10>Max)
     {  Max=n%10;
        return CMax(n/10,Max);
     }
  else  return CMax(n/10,Max);
}

int main()
{ long M=0;
  cout<<CMax(156242,M)<<endl;
  cout<<MedRec(123456,6,1);

  cout << "Hello world!" << endl;
  return 0;
}
