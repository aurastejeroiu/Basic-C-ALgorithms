#include <iostream>

using namespace std;
//P1.7 Fie n,k numere intregi si pozitive, n<>k. Sa se scrie un algoritm pentru calculul numarului de
//     combinari de n elemente luate cate k

//Dam in continuare 3 functii recursive derivate din formula n!/(k!(n-k)!)

long CNK1(long n, long k){
   if(n<k)          return 0;
   if(n==k || k==0) return 1;
   else             return CNK1(n-1,k-1)+CNK1(n-1,k);
}

long CNK2(long n, long k){
   if(n<k)          return 0;
   if(k==0)         return 1;
   else             return CNK2(n-1,k-1)*n/k;
}

long CNK3(long n, long k){
   if(n<k)          return 0;
   if(k==n)         return 1;
   else             return CNK3(n-1,k)*n/(n-k);
}


int main()
{   long n,k;
    cout<<"da n=";cin>>n;
    cout<<"da k=";cin>>k;
    cout<<CNK1(n,k)<<endl;
    cout<<CNK2(n,k)<<endl;
    cout<<CNK3(n,k)<<endl;
    cout << "Program terminat" << endl;
    return 0;
}
