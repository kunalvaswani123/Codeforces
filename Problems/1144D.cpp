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
const ll L = 1e5 + 5;
ll arr[2 * L];
ll cc[2 * L];
vector<pair<ll,pll> >ans;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	for(i=0;i<n;i++)
 		cin >> arr[i];
 	ll sta = 0;
 	ll maxv = 0;
 	for(i=0;i<n;i++)
 	{
 		cc[arr[i]]++;
		if(cc[arr[i]] > maxv)
		{
			sta = i;
			maxv = cc[arr[i]];
		}
 	}
 	ll checkval = arr[sta];
 	for(i=sta-1;i>=0;i--)
 	{
 		if(arr[i] > checkval)
	 		ans.pb(mp(2,mp(i+1,i+2)));
	 	else if(arr[i] < checkval)
	 		ans.pb(mp(1,mp(i+1,i+2)));
 	}
 	for(i=sta+1;i<n;i++)
 	{
 		if(arr[i] > checkval)
	 		ans.pb(mp(2,mp(i+1,i)));
	 	else if(arr[i] < checkval)
	 		ans.pb(mp(1,mp(i+1,i)));
 	}
 	cout << ans.size() << endl;
 	for(i=0;i<ans.size();i++)
 		cout << ans[i].fi << ' ' << ans[i].se.fi << ' ' << ans[i].se.se << endl;
	return 0;
}