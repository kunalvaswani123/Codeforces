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
const ll L=1e5+5; 
ll arr[L];
set<ll>::iterator p;
vector<ll>diff;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,q,x;
 	cin >> n;
 	for(i=0;i<n;i++)
 		cin >> arr[i];
 	sort(arr,arr+n);
 	for(i=1;i<n;i++)
 	{
 		if(arr[i]!=arr[i-1])
	 		diff.pb(arr[i]-arr[i-1]);
 	}
 	n=diff.size()+1;
 	vector<ll>newdiff;
 	if(diff.size() != 0)
 	{
	 	sort(diff.begin(),diff.end());
	 	newdiff.pb(diff[0]);
	 	for(i=1;i<diff.size();i++)
	 		newdiff.pb(diff[i]+newdiff[i-1]);
 	}
 	cin >> q;
 	ll l,r;
 	while(q--)
 	{
 		cin >> l >> r;
 		ll ans = n * (r - l + 1);
 		if(n == 1)
 		{
 			cout << ans << ' ';
 			continue;
 		}
 		ll val = upper_bound(diff.begin(),diff.end(),r-l)-diff.begin();
 		if(val == 0)
 		{
 			cout << ans << ' ';
 			continue;
 		}
 		val--;
 		ans -= (val + 1) * (r - l + 1);
 		ans += newdiff[val];
 		cout << ans << ' ';
 	}
 	cout << endl;
	return 0;
}