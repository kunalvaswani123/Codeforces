#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define american_pie 3.1415926535
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
const ll L = 1e5 + 5;
ll arr[2 * L];
ll c[200];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i, n, k;
    cin >> n >> k;
    for(i = 0; i < n; i++)
    {
    	cin >> arr[i], arr[i] %= k;
    	c[arr[i]]++;
    }
    ll ans = 0;
    for(i = 0; i < k; i++)
    {
    	if(i % k  == (k - i) % k)
    	{
    		ans += (c[i] / 2) * 2;
    		c[i] = 0;
    	}
    	else
    	{
    		ans += min(c[i], c[k - i]) * 2;
    		c[k - i] = 0;
    		c[i] = 0;
    	}
    }
    cout << ans << endl;
	return 0;
}