#include <cstdio>
#include <algorithm>
using namespace std;
int t, k, n, m, f[2005][2005], c[2005][2005];
int main()
{
    scanf("%d%d", &t, &k);
    for (int i = 0; i <= 2000; i++)
        f[i][0] = f[i][i] = 1;
    for (int i = 1; i <= 2000; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = ((f[i - 1][j - 1] % k) + (f[i - 1][j] % k)) % k;
    for (int i = 1; i <= 2000; i++)
        for (int j = 1; j <= 2000; j++)
        {
            c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
            if (!f[i][j] && i >= j)
                c[i][j]++;
        }
    for (int i = 1; i <= t; i++)
    {
        scanf("%d%d", &n, &m);
        printf("%d\n", c[n][m]);
    }
    return 0;
}