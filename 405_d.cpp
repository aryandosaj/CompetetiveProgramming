#include <bits/stdc++.h>
using namespace std;
int mp[1000001];
int main()
{
    int n, s = 1000000;
    scanf("%d", &n);
    int x=0;
    for(int i = 0; i < 1000001; i++)
    {
        mp[i]=0;
    }
    int a;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        mp[a] = 1;
        if(mp[s+1-a])x++;
    }
    printf("%d\n", n);
    for(int i = 1; i < s+1; i++)
    {
        if(mp[i]&&!mp[s+1-i])
        {
            printf("%d ", s-i+1);
        }
        else if(x&&!mp[i]&&!mp[s+1-i])
        {
            printf("%d ", i);
            printf("%d ",s+1-i);
            x--;
        }
    }
    
    
    
}