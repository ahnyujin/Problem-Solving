#include <stdio.h>
#include <vector>
#include <cmath> //c에서는 math.h c++에서는 cmath!
using namespace std;
int main(){
    long long int x,y;

    scanf("%lld %lld",&x,&y);
    // 각 x,y는 1조 이하로 매우 큰 숫자이지만
    // y<=x+1000000 이라는 조건으로 x와 y사이가 좁혀져 에라토스테네스의 체 로 문제를 해결할 수 있다.
    vector<long long int> vt(y-x+1,0);
    long long int end=sqrt(y);
    
    for(long long int i = 2 ;i<=end;i++){
        long long cur = i*i;
        long long index= x/cur;
        if(x%cur!=0) index++;
        for(long long int j=index;(j*cur)<=y;j++){
            vt[j*cur-x]=1;
        }
    }
    int answer=0;
    for(int i=0;i<y-x+1;i++){
        if(vt[i]==0) answer++;
    }
    printf("%d",answer);
    return 0;
}