#include <cstdio>
using namespace std;
int m, n, sum = 500, data[30][30], rec[30][30];
int xb[] = {0, 0, 1, -1}, yb[] = {1, -1, 0, 0};
struct w
{
	int x, y;
} way[500], py[500];
void copy(int a)
{
	for (int i = 1; i <= a; i++)
		py[i] = way[i];
}
void ss(int x, int y,int p)
{
	int tx, ty;
	for (int i = 0; i <= 3; i++)
	{
		tx = x + xb[i], ty = y + yb[i];
		if (tx >= 1 && tx <= m && ty >= 1 && ty <= n && (!data[tx][ty]) && (!rec[tx][ty]))
		{
			way[p].x = tx;
			way[p].y = ty;
			rec[tx][ty] = 1;
			if (tx == m && ty == n)
			{
				if (p < sum)
				{
					sum = p;
					copy(p);
				}
			}
			else if (p + m - tx + n - ty < sum)
				ss(tx, ty, p + 1);
			rec[tx][ty] = 0;
		}
	}
}
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &data[i][j]);
	way[1].x = way[1].y = 1;
	rec[1][1] = 1;
	ss(1, 1, 2);
	if (sum==500)
		printf("Noway!\n");
	else
	{
		printf("%d\n", sum);
		for (int i = 1; i <= sum; i++)
		printf("%d %d\n", py[i].x, py[i].y);
	}
	return 0;
}