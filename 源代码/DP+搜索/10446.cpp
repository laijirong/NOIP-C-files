#include <cstdio>
using namespace std;
int used[10], e[] = {-1, 3, 9, 31, 99}, data[5];
void out(int a)
{
	for (int i = 0; i <= a; i++)
		printf("%d ", data[i]);
	printf("\n");
}
int can(int a)
{
	if (a==0) used[a]++;
	int t = a;
	while (t)
	{
		used[t % 10]++;
		t /= 10;
	}
	int flag = 1;
	for (int i = 0; i <= 9; i++)
		if (used[i] > 1)
			flag = 0;
	if (flag == 0)
	{
		if (a==0) used[a]--;
		while (a)
		{
			used[a % 10]--;
			a /= 10;
		}
	}
	return flag;
}
void search(int a)
{
	for (int i = e[a] + 1; i <= e[a + 1]; i++)
		if (can(i * i))
		{
			data[a] = i * i;
			if (a == 3)
				out(a);
			else
				search(a + 1);
			int tt = data[a];
			if (tt == 0)
				used[tt]--;
			while (tt != 0)
			{
				used[tt % 10]--;
				tt /= 10;
			}
		}
}
int main()
{
	search(0);
	return 0;
}
