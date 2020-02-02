#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, m;
    cin >> n >> m;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((arr[i][j] == '*'))
            {
                continue;
            }
            else
            {

                ll c = 0;
                for (ll k = -1; k < 2; k++)
                {
                    // cout<<"k="<<k;
                    for (ll l = -1; l < 2; l++)
                    {
                        if (i == 0)
                        {
                            if (k == -1)
                                continue;
                        }
                        if (j == 0)
                        {
                            if (l == -1)
                                continue;
                        }

                        if (j == m - 1)
                        {
                            if (l == 1)
                                continue;
                        }
                        if (i == n - 1)
                        {
                            if (k == 1)
                                continue;
                        }
                        // cout << l << " " << k << "\n";

                        if ((l == 0) && (k == 0))
                            continue;
                        else
                        {
                            // cout << arr[i + k][j + l];
                            if (arr[i + k][j + l] == '*')
                                c++;
                        }
                    }
                }
                if (arr[i][j] == '.')
                {
                    if (c != 0)
                    {
                        cout << "NO";
                        return 0;
                    }
                    continue;
                }
                if (arr[i][j] != (c + 48))
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES";
}