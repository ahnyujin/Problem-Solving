#include<stdio.h>
long long table[1000050];
long long tree[4000050]={0};
int init(int start, int end, int node){
    if(start == end) return tree[node] = table[start];
    int mid = (start+end)/2;
    return tree[node] = init(start,mid, node*2) + init(mid+1,end,node*2+1);
}
int sum(int start, int end, int node, int left, int right){
    if(left>end || right < start) return 0;
    if(left<=start && end <=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}
void change(int start, int end, int node, int index, long long  dif) {
    if(index<start || index >end) return;
    tree[node]+=dif;
    if(start==end)return;
    int mid = (start+end)/2;
    change(start, mid, node*2, index, dif);
    change(mid+1, end, node*2+1, index, dif);
}
int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &table[i]);
    }
    init(0,n-1,1);
    for(int i=0;i<m+k;i++){
        long long a, b, c;
        scanf("%lld %lld %lld",&a,&b,&c);

        if(a==1){
            change(0, n-1, 1, b-1, c-table[b-1]);
        }
        else {
            printf("%lld\n", sum(0,n-1, 1, b-1, c-1));
        }
    }
}