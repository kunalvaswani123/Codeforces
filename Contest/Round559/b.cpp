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
const ll L = 3e5 + 5;
pll arr[L];
ll m[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	for(i=0;i<n;i++)
 	{
 		cin >> arr[i].fi;
 		arr[i].se = i;
 	}
 	sort(arr,arr+n);
 	ll ans = 1e18;
	ll l = 0, r = n-1;
	ll j;
	for(i=0;i<n;i++)
	{
		ll v = arr[i].se;
		if(l<v)
		{
			ll temp = arr[i].fi / abs(v - l);
			ans = min(ans,temp);
		}
		if(v<r)
		{
			ll temp = arr[i].fi / abs(r - v);
			ans = min(ans,temp);
		}
		m[arr[i].se] = 1;
		if(arr[i].se == l)
		{
			while(m[l] == 1)
				l++;
		}
		else if(arr[i].se == r)
		{
			while(m[r] == 1)
				r--;
		}
	}
	cout << ans << endl; 	
	return 0;
}