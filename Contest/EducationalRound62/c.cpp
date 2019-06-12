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
vector<pll>ad;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i, n, k;
 	cin >> n >> k;
 	ll t, b;
 	for(i=0;i<n;i++)
 	{
 		cin >> t >> b;
 		ad.pb(mp(b, t));
 	}
 	sort(ad.begin(), ad.end());
 	reverse(ad.begin(), ad.end());
 	multiset<ll>as;
 	ll sum = 0;
 	ll ans = -1;
 	for(i=0;i<n;i++)
 	{
 		if(as.size() == k)
 		{
 			ll val = *as.begin();
 			if(ad[i].se > val)
 			{
 				as.erase(as.begin());
 				as.insert(ad[i].se);
 				sum = sum - val + ad[i].se;
		 		ans = max(ans, ad[i].fi * sum);
 			}
 		}
 		else
 		{
	 		as.insert(ad[i].se);
 			sum += ad[i].se;		
	 		ans = max(ans, ad[i].fi * sum);
 		}
 	}
 	cout << ans << endl;
	return 0;
}