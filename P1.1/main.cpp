#include <iostream>

using namespace std;

///1.1. Fie i,j,k numere naturale. Sa se determine restul impartirii
///     numarului (i^j) la k; deci (i^j)mod k.
///     Idee:
///          - se calculeaza la fiecare pas de inmultire restul produsului;
///          - practic se inmultesc resturile modulo k.

void AfisRest(long long i, long long j, long long k){   ///long long e facilitate a Code::Blocks
    long long Rest=i%k;
    for(long long l=2; l<=j; l++)
        Rest=(Rest*(i%k))%k;                            ///atat lui i cat si produsului i se aplica %
    cout<<Rest;
}

void CitireDate(long long &i, long long &j, long long &k){
    cout    <<"da i:"; cin >>i;
    cout    <<"da j:"; cin >>j;
    cout    <<"da k:"; cin >>k;
}

int main()
{   long long    i,j,k;
    CitireDate  (i,j,k);
    AfisRest    (i,j,k);
    return 0;
}
