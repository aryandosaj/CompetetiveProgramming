#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int arr[2000][2000];
int sum[2000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    int n, m;
    cin >> n >> m;
    string s;
    // cin>>s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j] - 48;
        }

        for (int j = 0; j < m; j++)
        {
            if (i != 0)
                sum[j] = sum[j] + arr[i][j];
            else
            {
                sum[j] = arr[i][j];
            }
        }
    }
    ll flag;
    for(int i = 0; i < n; i++)
    {
        flag=0;
        for(int j = 0; j < m; j++)
        {
            if((sum[j]-arr[i][j])==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"YES";
            return 0;
        }
        
    }
    cout<<"NO";
    
}