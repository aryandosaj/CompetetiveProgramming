#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ALPHABET_SIZE = 2;
ll arr[100005];
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    ll c;
    ll e, o;
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

void insert(struct TrieNode *root, string key, ll ind)
{
    struct TrieNode *pCrawl = root;

    for (ll i = 0; i < key.length(); i++)
    {

        ll index = key[i] - '0';
        // cout<<index<<"\n";
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    (pCrawl->c)++;
    if (ind & 1)
        (pCrawl->o)++;
    else
        (pCrawl->e)++;
    pCrawl->isEndOfWord = true;
}

ll search(struct TrieNode *root, string key, ll ind)
{

    struct TrieNode *pCrawl = root;
    for (ll i = 0; i < key.length(); i++)
    {
        ll index = key[i];
        if (!pCrawl->children[index])
        {
            return 0;
        }
        else
        {
            pCrawl = pCrawl->children[index];
            if (i == key.length() - 1)
            {
                if (ind & 1)
                    return pCrawl->o;
                else
                    return pCrawl->e;
            }
        }
    }
}
string getstring(ll n)
{
    string s;
    for (ll i = 0; i < 60; i++)
    {
        if (n > 0)
            s.push_back('0' + n % 2),
                n /= 2;
        else
            s += '0';
    }
    reverse(s.begin(), s.end());
    return s;
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
        ans = max(ans, pre[i]);
        pre1[i] = getstring(pre[i]);
    }

    for (ll i = n; i > 0; i--)
    {
        cout<<pre[n-i+1]<<" ";
    }
    // cout<<"here";
    for (ll i = n; i > 0; i--)
    {
        if (i != n)
            ans += search(root, pre1[i],i&1);
        // cout<<"here";

        insert(root, pre1[i], i & 1);
    }
    cout << ans;
}
