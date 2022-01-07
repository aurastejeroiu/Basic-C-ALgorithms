#include <iostream>
using namespace std;
///1.1. Fie i,j,k numere naturale. Sa se determine restul impartirii
///     numarului (i^j) la k; deci (i^j)mod k.
///     Idee:
///          - se calculeaza la fiecare pas de inmultire restul produsului;
///          - practic se inmultesc resturile modulo k.
///          - recursiv

long long RestRec(long long i, long long j, long long k){///long long e facilitate a Code::Blocks
    if(j==0)  return 1;
              return (RestRec(i,j-1,k)*(i%k))%k;      ///atat lui i cat si produsului i se aplica %
    }

void CitireDate(long long &i, long long &j, long long &k){
    cout    <<"da i:"; cin >>i;
    cout    <<"da j:"; cin >>j;
    cout    <<"da k:"; cin >>k;
}
void AfisRest ( long long i, long long j, long long k, long long R){
 cout<<"restul lui "<<i<<"^"<<j<< " impartit la "<<k<< "="<<R<<endl;
}
int main()
{   long long    i,j,k,R;
    CitireDate  (i,j,k);
    R           =RestRec(i,j,k);
    AfisRest    (i,j,k,R);
    return 0;
}
