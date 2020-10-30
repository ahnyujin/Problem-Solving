#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int h,w;
    scanf("%d %d",&h,&w);
    int world[550];
	int answer=0;
	for(int i=0;i<w;i++){
        scanf("%d",&world[i]);
	}
	int maxx=0;
	int l_max[550];
	for(int j=0;j<w;j++){
		l_max[j]=maxx;
		if(maxx<world[j]){
			maxx=world[j];
		}
	}
	maxx=0;
	for(int j=w-1;j>=0;j--){
		int depth=min(maxx,l_max[j]);
		if(depth>world[j]){
			answer+=(depth-world[j]);
			world[j]=depth;
		}
		if(maxx<world[j]){
			maxx=world[j];
		}
	}
    printf("%d",answer);
}