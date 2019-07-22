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
const ll L = 1e3 + 5;
pll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,i,j;
 	cin >> n;
 	for(i=0;i<n;i++)
 		cin >> arr[i].fi >> arr[i].se;
 	set<pair<pll,ll> > as;
 	set<pair<pll,ll> > :: iterator it;
 	for(i=0;i<n;i++)
 	{
 		for(j=i+1;j<n;j++)
 		{
 			ll m2 = arr[j].se - arr[i].se;
 			ll m1 = arr[j].fi - arr[i].fi;
 			ll g = __gcd(m2,m1);
 			m2 /= g;
 			m1 /= g;
 			if (m2 < 0 || (m2 == 0 && m1 < 0))
			{
			    m2 = -m2;
			    m1 = -m1;
			}
 			ll c = m2 * arr[j].fi - m1 * arr[j].se;
 			as.insert(mp(mp(m2,m1),c));
 		}
 	}
 	ll ans = sz(as);
 	ans = ans * (ans - 1);
 	ans /= 2;
 	it = as.begin();
 	ll s1 = (*it).fi.fi;
 	ll s2 = (*it).fi.se;
 	ll c = 1;
 	it++;
 	as.insert(mp(mp(1e5,1e5),1e5));
 	for(;it!=as.end();it++)
 	{
 		pair<pll,ll> temp = *it;
 		if(temp.fi.fi == s1 && temp.fi.se == s2)
 			c++;
 		else
 		{
			ll t = c * (c - 1);
			t /= 2;
			ans -= t;
 			c = 1;
 		}
 		s1 = temp.fi.fi;
 		s2 = temp.fi.se;
 	}
 	cout << ans << endl;
	return 0;
}