#include <stdio.h>
int num[100010], save[100010];
int main()
{
	int k = 0;
	while (scanf("%d", &num[k]) != EOF)
	{
		++k;
	}
	int res = 0, r = 1, summax = 0, sum = 0;
	int j = res;
	if (k == 1)
	{
		printf("%d", num[0]);
		return 0;
	}
	while (r < k)
	{
		for (int i = res; i < r; i++)
		{
			if (num[r] == num[i])
			{
				if (i == r - 1)
				{
					res = i + 1;
					r = res + 1;
				}
				else
				{
					r++;
					res = i + 1;
				}
				continue;
			}
		}
		for (int j = res; j <= r; j++)
		{
			sum += num[j];
			if (sum > summax)
			{
				summax = sum;
			}
		}
		r++;
		sum = 0;
	}
	printf("%d", summax);
	return 0;
}
