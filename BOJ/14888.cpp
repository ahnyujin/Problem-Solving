#include <stdio.h>
int n;
int A[15];
int max=-100000001;
int min=100000001;
void put_operator(int index,int sum,int a,int s,int m,int d) {
    if(index == n-1) {
        if(sum > max) max=sum;
        if(sum < min) min=sum;
    }
    else {
        if(a!=0) put_operator(index+1,sum+A[index+1],a-1,s,m,d);
        if(s!=0) put_operator(index+1,sum-A[index+1],a,s-1,m,d);
        if(m!=0) put_operator(index+1,sum*A[index+1],a,s,m-1,d);
        if(d!=0) put_operator(index+1,sum/A[index+1],a,s,m,d-1);
    }
}
int main() {
    int a; //add
    int s; //subtract
    int m; //multiply
    int d; //division
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&A[i]);
    }
    scanf("%d %d %d %d",&a,&s,&m,&d);
    put_operator(0,A[0],a,s,m,d);
    printf("%d\n%d",max,min);
    return 0;
}