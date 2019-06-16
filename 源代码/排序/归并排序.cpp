#include <cstdio>
using namespace std;
int n, x[100010];
void change(int &a, int &b)
{
    a ^= b ^= a ^= b;
}
void sort(int a, int b)
{
    if (a == b)
        return;
    int mid = x[(a + b) / 2];
    int i = a - 1, j = b + 1;
    while (1)
    {
        do
            i++;
        while (x[i] < mid);
        do
            j--;
        while (x[j] > mid);
        if (i >= j)
            break;
        change(x[i], x[j]);
    }
    sort(a, j);
    sort(j + 1, b);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]);
    sort(1, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    return 0;
}