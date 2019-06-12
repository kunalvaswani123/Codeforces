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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n,q;
	cin >> q;
	while(q--)
	{
		cin >> n;
		ll ans = 0;
		while(n != 1)
		{
			if(n % 2 == 0)
				n /= 2;
			else if(n % 3 == 0)
				n /= 3, ans++;
			else if(n % 5 == 0)
				n /= 5, ans += 2;
			else 
				break;
			ans++;
		}
		if(n == 1)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}    
	return 0;
}