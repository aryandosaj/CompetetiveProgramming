#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ALPHABET_SIZE = 2;
ll arr[100005];
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    ll c;
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;
    pNode->c = 0;

    for (ll i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (ll i = 0; i < key.length(); i++)
    {
        ll index = key[i] - '0';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    (pCrawl->c)++;
    pCrawl->isEndOfWord = true;
}

string search(struct TrieNode *root, string key)
{
    string ans = "";
    struct TrieNode *pCrawl = root;
    for (ll i = 0; i < key.length(); i++)
    {
        ll index = key[i] - '0';
        if (!pCrawl->children[index])
        {
            ans.push_back('1' - index);
            pCrawl = pCrawl->children[1-index];
        }
        else
        {
            ans.push_back(key[i]);
            pCrawl = pCrawl->children[index];
        }
    }
    return ans;
}
string getstring(ll n)
{
    string s;
    for (ll i = 0; i < 60; i++)
    {
        if (n > 0)
            s .push_back ('0' + n % 2),
                n /= 2;
        else
            s += '0';
    }
    reverse(s.begin(), s.end());
    return s;
}
ll getnum(string s)
{
    ll num = 0;
    reverse(s.begin(), s.end());
    for (ll i = 0; i < s.size(); i++)
    {
        num += (s[i] - '0') * (pow(2,i));
    }
    return num;
}
string convert(string s)
{
    string s1 ;
    for (ll i = 0; i < s.length(); i++)
        if (s[i] == '1')
            s1.push_back('0');
        else
            s1.push_back('1');
    return s1;
}
ll pre[100005];
ll suf[100005];
string pre1[100005];
string suf1[100005];
int main()
{
    struct TrieNode *root = getNode();
    ll n;
    cin >> n;
    ll ans = 0;

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = arr[i] ^ pre[i - 1];
        ans = max(ans,pre[i]);
        pre1[i] = getstring(pre[i]);
    }

    for (ll i = n; i > 0; i--)
    {
        suf[i] = suf[i + 1] ^ arr[i];
        ans = max(ans,suf[i]);

        suf1[i] = getstring(suf[i]);
        // insert(root, suf1[i]);
    }
    for (ll i = n; i > 0; i--)
    {
        if(i!=n)
        ans = max(ans,pre[i]^getnum(search(root,convert(pre1[i]))));
        insert(root,suf1[i]);
    }
    cout << ans;
}
