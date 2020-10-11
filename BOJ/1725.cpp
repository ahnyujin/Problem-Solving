#include <stdio.h>
#include <stack>
#include <utility>
using namespace std;
int main(){
    stack<pair<int,int> > mystack;
    int n;
    int height[100050];
    int l[100050];
    int r[100050];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&height[i]);
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

    int answer=0;
    for(int i=0;i<n;i++){
        if(answer<height[i]*(r[i]-l[i]-1)){
            answer=height[i]*(r[i]-l[i]-1);
        }
    }
    printf("%d",answer);
    return 0;
}