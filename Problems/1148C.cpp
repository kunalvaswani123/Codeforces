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
ll arr[L];
ll pos[L];
int main()	
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	for(i=1;i<=n;i++)
 	{
 		cin >> arr[i];
 		pos[arr[i]] = i;
 	}
 	vector<pll>v;
 	for(i=1;i<=n/2;i++)
 	{
 		ll t = pos[i];
 		if(pos[i] == i)
 			continue;
 		if(abs(i-t) >= n/2)
 		{
 			v.pb(mp(i,t));
 			swap(arr[i],arr[t]);
 			pos[arr[i]] = i;
 			pos[arr[t]] = t;
 			continue;
 		}
 		if(pos[i] <= n/2)
 		{
 			v.pb(mp(t,n));
 			v.pb(mp(n,i));
			swap(arr[t],arr[n]);
			swap(arr[n],arr[i]);
			pos[arr[t]] = t;
			pos[arr[i]] = i;
			pos[arr[n]] = n;	
 		}
 		else
 		{
 			v.pb(mp(t,1));
 			v.pb(mp(1,n));
 			v.pb(mp(n,i));
 			v.pb(mp(t,1));
 			swap(arr[t],arr[1]);
 			swap(arr[1],arr[n]);
 			swap(arr[n],arr[i]);
 			swap(arr[t],arr[1]);
 			pos[arr[t]] = t;
 			pos[arr[1]] = 1;
 			pos[arr[n]] = n;
 		}
 	}
 	for(i=n/2+1;i<=n;i++)
 	{
 		if(pos[i] == i)
 			continue;
 		ll t = pos[i];
 		v.pb(mp(t,1));
 		v.pb(mp(1,i));
 		v.pb(mp(1,t));
 		swap(arr[i],arr[t]);
 		pos[arr[i]] = i;
 		pos[arr[t]] = t;
 	}
 	cout << sz(v) << endl;
 	for(i=0;i<sz(v);i++)
 		cout << v[i].fi << ' ' << v[i].se << endl;
	return 0;
}