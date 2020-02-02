#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, l, x, y;
    cin >> n >> l >> x >> y;
    ll arr[n];
    map<ll, ll> abc;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        abc[arr[i]] = 1;
    }
    ll xx = 0, yy = 0;
    for (int i = 0; i < n; i++)
    {
        if (xx == 0)
            if ((abc[arr[i] + x] == 1))
            {
                xx = 1;
            }
        if (yy == 0)
            if (abc[arr[i] + y] == 1)
            {
                yy = 1;
            }
        if ((xx == 1) && (yy == 1))
            break;
    }
    if ((xx == 1) && (yy == 1))
    {
        cout << "0";
        return 0;
    }
    if ((xx + yy) == 1)
    {
        cout << (2 - xx - yy) << "\n";
        if (xx == 0)
            cout << x << " ";
        if (yy == 0)
            cout << y;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if ((abc[arr[i] + x + y] == 1))
            {
                cout << "1\n";
                cout << (arr[i] + x);
                return 0;
            }
            if ((abc[arr[i] + y - x] == 1))
            {
                if ((arr[i] + y) < l)
                {
                    cout << "1\n";
                    cout << (arr[i] + y);
                    return 0;
                }
                else if ((arr[i] - x) > 0)
                {
                    cout << "1\n";
                    cout << (arr[i] - x);
                    return 0;
                }
                
            }
        }
        cout << "2\n";
        cout << x << " " << y;
    }
}