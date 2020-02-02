#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, k, a, b, x, y, ans;
    cin >> n >> k >> a >> b;
    if (a > b)
    {
        x = a / k;
        y = a / b;
        if(a%k==0)
        x--;
        if (x > b)
        {
            cout << "NO";
            return 0;
        }
        else
        {
            if (b - x > k)
            {

                for (ll i = y; i <= k; i++)
                {
                    if ((a - b * i) <= k)
                    {
                        ans = i;
                        break;
                    }
                }
            }
            else
            {
                ans = k;
            }
        }
        for (int i = 1; i <= n; i++)
        {

            if ((i % (ans + 1)) == 0)
            {
                cout << "B";
                b--;
                continue;
            }
            cout << "G";
            a--;
            if (a <= 0)
                break;
        }
        while (b > 0)
        {
            cout << "B";
            b--;
        }
    }
    else
    {
        x = b / k;
        y = b / a;
        if(b%k==0)
        x--;
        if (x > a)
        {
            cout << "NO";
            return 0;
        }
        else
        {
            if (a - x > k)
            {

                for (ll i = y; i <= k; i++)
                {
                    if ((b - a * i) <= k)
                    {
                        ans = i;
                        break;
                    }
                }
            }
            else
            {
                ans = k;
                
            }
            // cout<<ans;
            //     return 0;
        }
        for (int i = 1; i <= n; i++)
        {

            if ((i % (ans + 1)) == 0)
            {
                cout << "G";
                a--;
                continue;
            }
            cout << "B";
            b--;
            if (b <= 0)
                break;
        }
        while (a > 0)
        {
            cout << "G";
            a--;
        }
    }
}