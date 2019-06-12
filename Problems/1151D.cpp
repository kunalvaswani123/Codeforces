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
bool cmp(const pll &a,const pll &b) 
{ 
	return a.fi - a.se > b.fi - b.se; 
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	ll a,b;
 	vector<pll>as;
 	for(i=0;i<n;i++)
 	{
 		cin >> a >> b;
 		as.pb(mp(a,b));
 	}
 	sort(as.begin(),as.end(),cmp);
 	ll ans = 0;
 	for(i=1;i<=n;i++)
 		ans += as[i-1].fi*(i-1)+as[i-1].se*(n-i); 
 	cout << ans << endl;
	return 0;
}