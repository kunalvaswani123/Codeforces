#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pival 3.1415926535
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define qq queue
#define pqq priority_queue
ll power(ll x,ll y,ll p) 
{ 
    ll res=1;  
    x=x%p;
    while (y > 0) 
    { 
        if(y&1) 
            res=(res*x)%p; 
        y=y>>1;
        x=(x*x)%p;   
    } 
    return res; 
}
char arr[2001][2001];
ll dp[2001][2001];
ll n,k;
vector<pll>ad[2001][2001];
ll vis[2001][2001];
vector<char>ans;
void solve()
{
    ll st,i,j;
    ans[0] = arr[0][0];
    vis[0][0] = 0;
    for(st=1;st<2*n-1;st++)
    {
        i = 0;
        j = st;
        if(st >= n)
        {
            i = st-n+1;
            j = n-1;
        }
        while(i < n && j >= 0)
        {
            if(i == 0)
            {
                if(arr[i][j-1] == ans[st-1] && vis[i][j-1] == st-1)
                    ans[st] = min(ans[st],arr[i][j]), vis[i][j] = st;
            }
            else if(j == 0)
            {
                if(arr[i-1][j] == ans[st-1] && vis[i-1][j] == st-1)
                    ans[st] = min(ans[st],arr[i][j]), vis[i][j] = st;
            }
            else
            {
                if(arr[i][j-1] == ans[st-1] && vis[i][j-1] == st-1)
                    ans[st] = min(ans[st],arr[i][j]), vis[i][j] = st;   
                else if(arr[i-1][j] == ans[st-1] && vis[i-1][j] == st-1)
                    ans[st] = min(ans[st],arr[i][j]), vis[i][j] = st;
            }
            i++,j--;
        }
    }
    for(i=0;i<2*n-1;i++)
        cout << ans[i];
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,j;
    string s;
    cin >> n >> k;
    for(i=0;i<n;i++)
    {
        cin >> s;
        for(j=0;j<n;j++)
            arr[i][j] = s[j];
    }
    for(i=0;i<4*n;i++)
        ans.pb('z');
    if(arr[0][0]!='a' && k>0)
        arr[0][0] = 'a',k--;
    dp[0][0] = k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i == 0 && j == 0)
                continue;
            if(i == 0)
            {
                if(dp[i][j-1] > 0)
                {
                    if(arr[i][j] == 'a')
                        dp[i][j] = dp[i][j-1];
                    else
                        arr[i][j] = 'a', dp[i][j] = dp[i][j-1] - 1;
                }
            }
            else if(j == 0)
            {
                if(dp[i-1][j] > 0)
                {
                    if(arr[i][j] == 'a')
                        dp[i][j] = dp[i-1][j];
                    else
                        arr[i][j] = 'a', dp[i][j] = dp[i-1][j] - 1;
                }
            }
            else
            {
                if(dp[i][j-1] == 0 && dp[i-1][j] == 0)
                    continue;
                if(arr[i][j] == 'a')
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                else if(dp[i][j-1] > dp[i-1][j])
                    arr[i][j] = 'a', dp[i][j] = dp[i][j-1] - 1;
                else
                    arr[i][j] = 'a', dp[i][j] = dp[i-1][j] - 1;
            }
        }
    }
    solve();
    return 0;
}