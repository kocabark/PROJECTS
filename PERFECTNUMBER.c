#include <stdio.h>
#include <math.h>
#define ll long long


int PerfectPower(long long unsigned n){
    unsigned int max = sqrt(n);
    if( n == 1 ) {
        return true;
    }
    unsigned p, pp;


    for (unsigned int x=2; x<=max; x++)
    {
        p = n;
        while(true){
            pp = p;
            p = p/x;
            if (p == 1 && pp == p * x) {
                return true;
            }
            if (pp != p * x) {
                break;
            }
        }
    }
    return false;
}


int main (void){
    int ret = 0;
    unsigned ll int sum = 0;
    ll int i = 0, j = 0;
    printf("Intervals:\n");
    while(!feof(stdin)){
        sum = 0;
        ret = scanf("%lld %lld", &i, &j);
    if( ret != 2 || i > j || i < 1 || j < 1){
       if (!feof(stdin) || ret > 0){
        printf("Invalid input.\n");
       }
        return 0;
    }


    for(ll int num = i;num <= j; num++){
            if (!(PerfectPower(num))){
                sum = sum + 1;
            }

    }
    printf("[%lld;%lld] -> %llu\n", i, j, sum);
    }
    return 0;
}
