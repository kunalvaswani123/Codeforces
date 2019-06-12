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
ll a[L];
ll b[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	ll ch = 0;
 	deque<ll>d;
 	multiset<ll>as;
 	for(i=1;i<=n;i++)
 	{
	 	cin >> a[i];
 		as.insert(a[i]);
 	}
	for(i=1;i<=n;i++)
	{
		cin >> b[i];
		d.pb(b[i]);
	}
	ll f = 0;
	for(i=b[n]+1;i<=n;i++)
	{
		if(as.find(i)!=as.end())
		{
			d.pb(i);
			as.insert(d.front());
			d.pop_front();
		}
		else
		{
			f = 1;
			break;	
		}
	}
	ll f2 = 0;
	if(f == 0)
	{
		ll st = 1;
		while(sz(d)!=0)
		{
			if(d.front() == st)
				st++, d.pop_front();
			else
			{
				f2 = 1;
				break;
			}
		}
		if(f2 == 0)
		{
			cout << n - b[n] << endl;
			return 0;
 		}
	}
	ll mx = 0;
	for(i=1;i<=n;i++)
	{
		if(b[i] == 0)
			continue;
		if(i >= b[i])
		{
			ll t = i - b[i] + 1;
			if(t > mx)
				mx = t;
		}
	}
	cout << mx + n << endl;
	return 0;
}