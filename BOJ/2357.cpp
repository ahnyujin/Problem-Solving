#include <stdio.h>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

int table[100002];
pair<int, int> tree[400002];
pair<int, int> comp(pair<int, int> x, pair<int, int> y){
    return make_pair( max(x.first, y.first), min(x.second, y.second));
}
pair<int, int> init(int start, int end, int cur) {
    if(start==end) return tree[cur] = make_pair(table[start], table[start]);
    int mid = (start+end)/2;
    return tree[cur] = comp( init(start, mid, cur*2), init(mid+1, end, cur*2+1));
}
pair<int, int> find(int start, int end, int cur, int a, int b) {
    if(b < start || end < a) {
        return make_pair(-1, 1000000001);
    }
    if(a<=start && end <=b) {
        return tree[cur];
    }
    int mid = (start+end)/2;
    return comp(find(start,mid,cur*2,a,b), find(mid+1,end,cur*2+1, a,b));
}
int main() 
{
    int n,m;
    scanf("%d %d",&n, &m);
    for(int i=0;i<n;i++){
        scanf("%d",&table[i]);
    }
    memset(tree, 0, sizeof(tree));
    init(0, n-1, 1);
    for(int i=0;i<m;i++){
        // min, max
        int a,b;
        scanf("%d %d",&a,&b);
        pair<int, int> answer = find(0,n-1,1,a-1,b-1);
        printf("%d %d\n", answer.second, answer.first);
    }
}
