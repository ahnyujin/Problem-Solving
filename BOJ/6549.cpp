#include <stdio.h>
#include <stack>
#include <utility>
using namespace std;
int main(){
    while(1){
        stack<pair<int,int> > mystack;
        int n;
        long long int height[100050];
        long long int l[100050];
        long long int r[100050];
        scanf("%d",&n);
        if(n==0)break;
        for(int i=0;i<n;i++){
            scanf("%lld",&height[i]);
            while(!mystack.empty() && mystack.top().first > height[i]){
                r[mystack.top().second]=i;
                mystack.pop();
            }
            mystack.push(make_pair(height[i],i));
        }
        while(!mystack.empty()){
            r[mystack.top().second]=n;
            mystack.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!mystack.empty() && mystack.top().first > height[i]){
                l[mystack.top().second]=i;
                mystack.pop();
            }
            mystack.push(make_pair(height[i],i));
        }
        while(!mystack.empty()){
            l[mystack.top().second]=-1;
            mystack.pop();
        }

        long long int answer=0;
        for(int i=0;i<n;i++){
            if(answer<height[i]*(r[i]-l[i]-1)){
                answer=height[i]*(r[i]-l[i]-1);
            }
        }
        printf("%lld\n",answer);
    }
    return 0;
}