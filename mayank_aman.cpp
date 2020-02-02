#include <bits/stdc++.h>
using namespace std;
int s[5000001];
bool prime[5000001];
int main()
{
    for (int i = 2; i < 5000001; i++)
    {
        if (prime[i] == 0)
        {
            s[i] = i;
            for (int j = 2 * i; j < 5000001; j += i)
            {
                prime[j] = 1;
                if (s[j] == 0)
                    s[j] = i;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> b >> a;
        c = a;
        d = b;
        int ans = 0;
        cout << s[a] << " " << s[b] << "\n";
        unordered_map<int, int> mp;
        int ans = 0;
        while (a > 1)
        {
            int y = s[a],z=s[a];
            while (y <= a)
            {
                ans += a / y;
                y *= z;
            }
            while (a % z == 0)
                a /= z;
        }

        cout << ans << "\n";
    }
}