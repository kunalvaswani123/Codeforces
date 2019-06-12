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
ll arr1[L];
vector<ll>arr2;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,m,t1,t2,k,x;
 	cin >> n >> m >> t1 >> t2 >> k;
 	for(i=0;i<n;i++)
 		cin >> arr1[i];
 	for(i=0;i<m;i++)
 	{
 		cin >> x;
 		arr2.pb(x);
 	}
 	if(k >= n || k >= m)
 	{
 		cout << -1 << endl;
 		return 0;
 	}
 	ll ans = -1;
 	for(i=0;i<=k;i++)
 	{	
 		ll pos = arr1[i];
 		ll it = lower_bound(all(arr2), pos + t1) - arr2.begin();
 		ll val = k - i;
 		it += val;
 		if(it >= m)
 		{
			cout << -1 << endl;
			return 0; 			
 		}
 		ans = max(ans, arr2[it] + t2);
 	}
 	cout << ans << endl;
	return 0;
}