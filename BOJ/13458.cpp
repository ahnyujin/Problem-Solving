#include <stdio.h>
int main()
{
    int n;
    int candidate[1000005];
    int b,c;
    long long int answer=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&candidate[i]);
    }
    scanf("%d %d",&b,&c);
    for(int i=0;i<n;i++){
        answer++;
        if(candidate[i]-b>0){
            answer+=(candidate[i]-b)/c;
            if((candidate[i]-b)%c>0) answer++;
        }
    }
    printf("%lld",answer);
    return 0;
}