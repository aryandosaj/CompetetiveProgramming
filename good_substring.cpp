#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
struct trie
{
    map<char, trie> children;
    bool end_of_word;
    ll k;
};
trie abc[200];
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    //code start here
    string s;
    cin >> s;
    ll l = s.length();
    ll a[200];
    string arr;
    cin >> arr;
    ll k;
    cin >> k;
    int jj = 0;
    for (char i = 'a'; i <= 'z'; i++, jj++)
    {
        a[i] = 1 - arr[jj] + 48;
    }
    ll count = 0;
    for (ll i = 0; i < l; i++)
    {
        ll j = i;
        ll kk = 0;
        trie temp;
        temp = abc[s[i]];
        while (j < l)
        {
            kk += a[s[j]];
            temp.k = kk;
            if (temp.end_of_word == false)
            {
                temp.end_of_word = true;
                if (kk <= k)
                {
                    count++;
                cout<<s.substr(i,j)<<"\n";
                }
            }
            if (kk > k)
                break;
            if (j < l - 1)
                temp = temp.children[s[j + 1]];
            j++;
        }
        
    }
    cout << count;
}