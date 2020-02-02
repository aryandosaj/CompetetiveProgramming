#include <bits/stdc++.h>
using namespace std;
int mp1[20000000];
int level[20000000];
int main()
{
    int t;
    scanf("%d",&t);

    while (t--)
    {
        // map<int, int> mp1;
        
        queue<int> q;
        int n, a, b, i=1;
        scanf("%d%d%d",&n,&a,&b);
        for(int i = 0;i<=(n*a+n*b+1);i++)
        mp1[i]=0,level[i]=0;
        level[0] = 0;
        mp1[0] = 1;
        q.push(0);
        int g = __gcd(a,b);
        int a1 = a/g;
        int a2 = b/g;
        if((a1+a2)>n) {cout<<(((n+1)*(n+2))/2)<<"\n";continue;}
        while (!q.empty())
        {
            int j = q.front();
            q.pop();
            if (level[n*b+j] >= n)
                break;

            if (mp1[n*b+j + a] == 0)
            {
                q.push(j + a);
                mp1[n*b+j + a] = 1;
                i++;
                level[n*b+j + a] = level[n*b+j] + 1;
            }
            if (mp1[n*b+j - b] == 0)
            {
                q.push(j - b);
                i++;
                mp1[n*b+j - b] = 1;
                level[n*b+j - b] = level[n*b+j] + 1;
            }
        }
        printf("%d\n",i);
    }
}