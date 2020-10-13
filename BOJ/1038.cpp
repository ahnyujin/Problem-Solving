#include <cstdio>
#include <algorithm>
using namespace std;
long long int T[1050];
int cnt=0;
void desc(long long int cur){
    T[cnt++]=cur;
    if(cur%10==0) return;
    for(int i=cur%10-1;i>=0;i--){
        desc(cur*10+i);
    }
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<10;i++){
        desc(i);
    }
    sort(T,T+cnt);
    if(cnt<=N) printf("-1");
    else printf("%lld",T[N]);
    return 0;
}