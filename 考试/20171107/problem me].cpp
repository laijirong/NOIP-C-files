#include <cstdio>
#include <algorithm>
using namespace std;
int t, k, n, m, f[2020][2020], c[2020][2020];
int main()
{
    scanf("%d%d", &t, &k);
    for (int i = 1; i <= 2000; i++)
        f[i][0] = f[i][i] = 1;
    for (int i = 1; i <= 2000; i++)
        for (int j = 1; j < i; j++)
            f[i][j] = (f[i - 1][j] % k + f[i - 1][j - 1] % k) % k;
    for (int i = 1; i <= 2000; i++)
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = c[i][j - 1];
            if (!f[i][j])
                c[i][j]++;
        }
    for (int i = 1; i <= t; i++)
    {
        scanf("%d%d", &n, &m);
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            int j = min(i, m);
            ans += c[i][j];
        }
        printf("%d\n", ans);
    }
    return 0;
}