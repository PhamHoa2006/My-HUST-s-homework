//C 
#include <stdio.h> 

long long main() 
{ 
    long long T;
    long long n,t;
    long long test = 0;
    long long arr[100000];
    scanf("%d",&T);
    for (long long j = 1; j <= T; j++){
        scanf("%d",&n);
        long long mangDanhDau[100005]={0};
        for (long long i = 0; i < n; i++) {
            scanf("%d",&arr[i]);
        }
        for (long long i = 0; i < n; i++) {
        
            if (arr[i]<1|| arr[i]>n){
                test = 0;
                break;
            }
            mangDanhDau[arr[i]]++;
            if (mangDanhDau[arr[i]] != 1) {
                test = 0;
                break;
            }
            else test = 1;
        }
    
        if (test == 0) prlong longf("0\n");
        if (test==1) prlong longf("1\n");
    }
    return 0;
}