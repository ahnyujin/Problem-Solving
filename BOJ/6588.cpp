#include <cstdio>
int T[1000050] = {0};
int main()
{
	T[1] = 1;
    for (int i=3;i<=1000000;i++){
        for(int j=2;i*j<=1000000;j++){
            T[i*j] = 1;//소수 x
        }
    }
	while (1)
	{
		int x;
		scanf("%d", &x);
		if (x == 0)break;

		int flag = 0;
		for (int i = 3; i < x; i+=2)
		{
			if (T[i] == 0 && T[x - i] == 0)
			{
				flag = 1;
				printf("%d = %d + %d\n", x, i, x - i);
				break;
			}
		}
		if (flag == 0)
		{
			printf("Goldbach's conjecture is wrong.\n");
		}
	}

	return 0;
} 