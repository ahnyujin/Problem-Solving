#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int T;
    int n,m;
    vector<int> A;
    vector<int> B;
    scanf("%d",&T);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(i==0) A.push_back(x);
        else{
            A.push_back(x+A.back());
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            A.push_back(A[j]-A[i]);
        }
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        if(i==0) B.push_back(x);
        else{
            B.push_back(x+B.back());
        }
    }
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            B.push_back(B[j]-B[i]);
        }
    }
    sort(A.begin(),A.end());
    long long int answer=0;
    for(int i=0;i<B.size();i++){
        auto x = lower_bound(A.begin(),A.end(),T-B[i]);
        auto y = upper_bound(A.begin(),A.end(),T-B[i]);
        answer += y-x;
    }
    printf("%lld",answer);
    return 0;
}