#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
map<string, int> kk;
map<string, bool> visit;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    string s;
    string arr;
    cin >> s >> arr;
    int a[200];
    int k;
    cin >> k;
    int l = s.length();
    string s1, s2;
    int j = 0;
    for (char i = 'a'; i <= 'z'; i++, j++)
    {
        a[i] = 1 - arr[j] + 48;
    }
    ll count=0;
    for (int i = 0; i < l; i++)
    {
        s1 = "";
        for (int j = i; j < l; j++)
        {
            s2 = s1;
            if (j == i)
            {
                s1 = s[i];
                kk[s1] = a[s[i]];
            }
            else
            {
                s1 += s[j];
                kk[s1] = kk[s2] + a[s[j]];
                s2 = s1;
            }
            if (kk[s1] > k)
                break;
            else
            {
                if (visit[s1] == false)
                {
                    count++;
                    visit[s1] = true;
                    // cout<<s1<<"-";
                }
            }
        }
    }
    cout<<count;
}