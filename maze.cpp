#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void markpath(string *arr, int n, int m, int k, int i, int j)
{
    if (cnt >= k)
        return;
    if (arr[i][j] == '#')
        return;
    if (arr[i][j] == 'D')
        return;
    cnt++;
    arr[i][j] = 'D';
    if (cnt < k && i < n - 1)
        markpath(arr, n, m, k, i + 1, j);
    if (cnt < k && j < m - 1)
        markpath(arr, n, m, k, i, j + 1);
    if (cnt < k && i > 0 )
        markpath(arr, n, m, k, i - 1, j);
    if (cnt < k && j > 0)
        markpath(arr, n, m, k, i, j - 1);
    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    string *arr = new string[n];
    int cd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.')
            {
                cd++;
            }
        }
    }
    //cout<<k<<" "<<cd<<"\n";
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.')
            {
                markpath(arr, n, m, cd - k, i, j);
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]=='.')
            {
                arr[i][j]='X';
            }
            if(arr[i][j]=='D')
            {
                arr[i][j]='.';
            }

            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}