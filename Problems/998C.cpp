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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll i, n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	ll count = 0, f = 0;
	for(i=0;i<n;i++)
	{
		if(s[i] == '0' && f == 0)
			count++, f = 1;
		else if(s[i] == '1' && f == 1)
			f = 0;
	}
	ll ans = 1e18;
	if(count == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for(i=1;i<=count;i++)
		ans = min(ans, i * y + (count - i) * x);
	cout << ans << endl;
	return 0;
}