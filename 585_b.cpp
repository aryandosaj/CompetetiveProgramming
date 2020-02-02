#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pint pair<int, int>
#define pb push_back
#define F first
#define S second
#define I insert
#define vint vector<int>
int power(int a, int b, int mod)
{
    int c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int n, k;
char s[3][105];
int dp[3][105];
int flag = 0;
void dfs(int ui, int uj)
{
    if (uj >= n - 1)
    {
        flag = 1;
        
        return;
    }
    if(dp[ui][uj]!=-1)
    {
        flag=dp[ui][uj];
        return;
    }
    for (int i = -1; i < 2; i++)
    {
        if ((ui + i < 0) || (ui + i > 2))
            continue;
        else
        {
            if (s[ui][uj + 1] == '.')
                if ((s[ui + i][uj + 3] == '.')&&(s[ui + i][uj + 1] == '.')&&(s[ui + i][uj + 2] == '.'))
                    {
                        if(flag==0)
                        dfs(ui + i, uj + 3);
                        dp[ui+i][uj+3]=flag;
                    }
        }
    }
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 105; j++)
            {
                dp[i][j]=-1;
            }
            
        }
        
        scanf("%d%d", &n ,&k);

        for (int i = 0; i < 3; i++)
        {
            scanf("%s",s[i]);
            s[i][n]='.';
            s[i][n+1]='.';
            s[i][n+2]='.';
        }
        int pos;
        for (int i = 0; i < 3; i++)
        {
            if (s[i][0] == 's')
            {
                pos = i;
            }
        }

        dfs(pos, 0);
        if (flag == 1)
            printf( "YES\n");
        else
            printf("NO\n");
        flag = 0;
    }
}