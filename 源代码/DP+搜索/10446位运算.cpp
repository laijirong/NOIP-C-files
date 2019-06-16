#include <cstdio>
using namespace std;
int e[] = {-1, 3, 9, 31, 99}, data[1010];
void out(int a)
{
	for (int i = 0; i <= a; i++)
		printf("%d ", data[i]);
	printf("\n");
	return;
}
int can(int a, int &b)
{
	int t;
	do
	{
		t = 1 << (a % 10);
		if ((b & t) == t)
			return 0;
		b = (b | t);
		a /= 10;
	} while (a);
	return 1;
}
void search(int a, int b)
{
	int tb = b;
	for (int i = e[a] + 1; i <= e[a + 1]; i++, tb = b)
		if (can(i * i, tb))
		{
			data[a] = i * i;
			if (a == 3)
				out(a);
			else
				search(a + 1, tb);
		}
}
int main()
{
	search(0, 0);
	return 0;
}