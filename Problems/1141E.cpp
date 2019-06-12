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
ll pref[2 * L];
ll check(ll H, ll n)
{	
	ll i;
	for(i=1;i<=n;i++)
	{
		if(H + pref[i] <= 0)
			return i;
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i;
	ll H, n;
 	cin >> H >> n;
 	for(i=1;i<=n;i++)
 		cin >> arr[i];
	pref[1] = arr[1];
	ll minp = pref[1];
	for(i=2;i<=n;i++)
	{
		pref[i] = arr[i] + pref[i-1];
		minp = min(pref[i], minp);	
	}
	ll c1 = check(H, n);
	if(c1 != -1)
	{
		cout << c1 << endl;
		return 0;
	}
	if(pref[n] >= 0)
	{
		cout << -1 << endl;
		return 0;
	}
	ll ans = 0;
	ll temp = (H + minp) / abs(pref[n]);
	ans += temp * n;
	H -= temp * abs(pref[n]);
	while(1)
	{
		if(check(H, n) != -1)
		{
			cout << ans + check(H, n) << endl;
			break;
		}
		else
		{
			H -= abs(pref[n]);
			ans += n;
		}
	}
	return 0;
}