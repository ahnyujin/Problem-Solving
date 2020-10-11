#include <cstdio>
int main(){
    int n,k;
    int T[1050]={0};
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        for(int j=x;j<=k;j++){
            if(j==x){
                T[j]=1;
            }
            else if(T[j-x]!=0 && (T[j]==0 || T[j]>T[j-x]+1)){
                T[j]=T[j-x]+1;
            }
        }
    }
    if(T[k]==0) printf("-1");
    else printf("%d",T[k]);
}