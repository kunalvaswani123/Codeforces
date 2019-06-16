#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
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
const ll L = 2e5 + 5;
ll dp[L][12];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,n,k,a,b,j;
    cin >> n;
    for(i=1;i<=n;i++)
        for(k=0;k<=9;k++)
            dp[i][k] = -1;
    for(j=1;j<=n;j++)
    {
        multiset<ll,greater<ll> >s[4];
        multiset<ll,greater<ll> >::iterator it;
        cin >> k;
        for(i=0;i<k;i++)
        {
            cin >> a >> b;
            s[a].insert(b);
        }
        ll ans[5];
        ll m[5];
        ans[1] = 0, ans[2] = 0, ans[3] = 0;
        m[1] = 0, m[2] = 0, m[3] = 0;
        if(sz(s[3])!=0)
        {
            ll p = *s[3].begin();
            if(p >= ans[1])
                m[1] = p, ans[1] = p;
        }
        if(sz(s[2])!=0)
        {
            if(sz(s[1])!=0)
            {
                ll ch = *s[1].begin() + *s[2].begin();
                if(ch >= ans[2])
                    ans[2] = ch, m[2] = max(*s[2].begin(), *s[1].begin());
            }
            ll ch2 = *s[2].begin();
            if(ch2 >= ans[1])
                ans[1] = ch2, m[1] = *s[2].begin();
        }
        ll sum = 0;
        ll c = 0;
        for(it=s[1].begin();it!=s[1].end();it++)
        {
            sum += *it, c++;
            if(c == 1)
            {
                if(sum >= ans[1])
                    ans[1] = sum, m[1] = *s[1].begin();
            }
            else if(c == 2)
            {
                if(sum >= ans[2])
                    ans[2] = sum, m[2] = *s[1].begin();
            }
            else if(c == 3)
            {
                if(sum >= ans[3])
                    ans[3] = sum, m[3] = *s[1].begin();
            }
            else
                break;
        }
        if(j == 1)
        {
            dp[j][0] = 0;
            if(ans[1]!=0)
                dp[j][1] = ans[1];
            if(ans[2]!=0)
                dp[j][2] = ans[2];
            if(ans[3]!=0)
                dp[j][3] = ans[3];
        }
        else
        {
            for(i=0;i<10;i++)
            {
                if(dp[j-1][i] == -1)
                    continue;
                dp[j][i] = max(dp[j-1][i], dp[j][i]);
                if(i >= 7 && ans[3] != 0)
                {
                    ll temp = (i+3)%10;
                    dp[j][temp] = max(dp[j-1][i] + ans[3] + m[3], dp[j][temp]);  
                }
                if(i >= 8 && ans[2] != 0)
                {
                    ll temp = (i+2)%10;
                    dp[j][temp] = max(dp[j-1][i] + ans[2] + m[2], dp[j][temp]);  
                }
                if(i >= 9 && ans[1] != 0)
                {
                    ll temp = (i+1)%10;
                    dp[j][temp] = max(dp[j-1][i] + ans[1] + m[1], dp[j][temp]);  
                }
                for(ll k=1;k<=3;k++)
                {
                    ll temp = (i+k)%10;
                    if(ans[k] != 0)
                        dp[j][temp] = max(dp[j][temp], dp[j-1][i] + ans[k]); 
                }
            }
        }
    }
    a = 0;
    for(i=0;i<10;i++)
        a = max(a, dp[n][i]);
    cout << a << endl;
    return 0;
}