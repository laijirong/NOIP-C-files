#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
int best,num[5001],data[5001],n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&data[i]);
    num[n]=1;
    for(int i=n-1;i>=1;i--)
    {
       int max=1;
       for(int j=i+1;j<=n;j++)
       {
           if(data[i]<=data[j]&&max<=num[j])
              max=num[j]+1;
            num[i]=max;
       }
    }
    for(int i=1;i<=n;i++)
        if(best<num[i])best=num[i];
    printf("%d\n",best);
    return 0;
}
