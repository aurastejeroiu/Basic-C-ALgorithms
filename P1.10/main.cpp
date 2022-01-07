#include <iostream>

using namespace std;

//P1.10. Fie n,k din N, n>=k. Sa se scrie un algoritm pentru calculul sumaei
//       S=Aranj(n,k)+Combi(n,k) +Perm(n);

//Idee: se vor face subprograme pentru aranjamente, combinari si permutari

long CNK(long n, long k){           //combinari de n luate cate k
   if(n<k)          return 0;
   if(k==0||k==n)   return 1;
   else             return CNK(n-1,k)*n/(n-k);
}

long ANK(long n, long k){
   if(n<k)          return 0;
   if(k==1)         return n;
   else             return (n-k+1)*ANK(n,k-1);
}

long P(long n){
   if(n==0 || n==1) return 1;
   else             return n*P(n-1);
}


int main()
{   long n,k, S;
    cout<<"da n=";cin>>n;
    cout<<"da k=";cin>>k;
    cout<<ANK(n,k)<<endl;
    cout<<CNK(n,k)<<endl;
    ///cout<<P(n)<<endl;
    cout<<ANK(n,n)<<endl;
    S=ANK(n,k)+CNK(n,k)+P(n);
    cout <<S<<endl;
    cout << "Program terminat" << endl;
    return 0;
}
