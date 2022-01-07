#include <iostream>

using namespace std;

bool Prim(long n){
  if(n==2)   return true;
  if(n%2==0) return false;
  for(long d=3; d*d<=n; d+=2)
    if(n%d==0) return false;
  return true;
}

long OrdinalK(long k){
   long N,cnt,K;
   if(k==1 || k==2 || k==3) return k;   ///primii 3 termeni coincid cu sirul numerelor naturale
   cnt=N=3;
   while(cnt<k){
     N++;
     if(Prim(N)) {cnt++; K=N;}
     else{
         long d=2;
         while(cnt<k && d<=N/2){
            if(N%d==0 && Prim(d)) {
                cnt+=d;
                K=d;
            }
            d++;
         }
     }
   }
   return K;
}



int main()
{   long k;
    cout<<"da pozitia:";
    cin >>k;
    cout<<"val elem. de pe pozitia:"<<k<<" este:"<<OrdinalK(k);
    cout << "\nProgram terminat" << endl;
    return 0;
}
