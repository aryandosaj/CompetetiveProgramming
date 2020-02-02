#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
map<string, bool> mp;
map<string, int> kk;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    // cout<<((int)'a');
    string s;
    cin >> s;
    int l = s.length();
    string arr;
    cin >> arr;
    int k;
    cin >> k;

    // string s1 = s.substr(0,3);
    // cout<<s1;
    // return 0;
    string s1;
    string s2;
    
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        s1="";
        for (int j = i; j <= l; j++)
        {
            s2=s1;
            // string s1 = s.substr(i, j);
            s1+=s[j];
            // cout << s1 << " ";
            if (j == i)
            {
                kk[s1] = (1 - (arr[s1[0] - 97] - 48));
            }
            else
            {
                
                kk[s1] = kk[s2] + (1 - arr[s1[j - 1] - 97] + 48);
                // cout <<(1 - arr[s1[j - 1]-97]+48)<<"\n";
            }
                    cout<<s1<<" ";

            if (kk[s1] > k)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
            {
                break;
            }
            else
            {
                    // cout<<kk[s1]<<" ";

                if (mp[s1] == false)
                {
                    // cout<<s1<<" ";
                    count++;
                    mp[s1] = true;
                }
            }
        }
    }
    // cout<<kk["ab"]<<" ";
    cout << count;
}