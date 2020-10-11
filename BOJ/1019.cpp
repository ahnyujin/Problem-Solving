
#include <stdio.h>
int count[10];

void add_digit(int n, int digit)
{
	while (n > 0) {
		count[n%10]+=digit;
		n/=10;
	}
}
void count_number_of_page(int x, int y, int digit) {
    //x끝자리가 0이 될때까지 직접 세어주기
	while(x%10!=0 && x<=y)
	{
		add_digit(x, digit);
		x++;
	}
	if(x>y) return;

    //y끝자리가 9가 될때까지 직접 세어주기
	while(y%10!=9)
	{
		add_digit(y, digit);
		y--;
	}

	int cnt=y/10-x/10+1;

	for (int i=0; i<10; i++){
		count[i]+=(cnt*digit);
    }

	count_number_of_page(x/10, y/10, digit*10);
}
int main()
{
	int n;
    scanf("%d",&n);
    //0~9 패턴의 규칙성으로 재귀적으로 해결하자.
	count_number_of_page(1,n,1);

    for(int i=0;i<10;i++){
        printf("%d ",count[i]);
    }
	return 0;
}