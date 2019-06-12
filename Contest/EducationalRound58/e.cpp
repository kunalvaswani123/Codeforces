#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
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
	ll n;
	cin>>n;
	set<pll>as1;
	set<pll>as2;
	while(n--)
	{
		char c;
		cin>>c;
		ll a,b;
		if(c=='+')
		{
			cin>>a>>b;
			as1.insert(mp(min(a,b),max(a,b)));
			as2.insert(mp(max(a,b),min(a,b)));
		}
		if(c=='?')
		{
			cin>>a>>b;
			ll f1=0,f2=0;
			if(as1.upper_bound(mp(min(a,b),max(a,b)))!=as1.end())
				f1=1;
			if(as2.upper_bound(mp(max(a,b),min(a,b)))!=as2.end())
				f2=1;
			if(f1==1||f2==1)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
	}
	return 0;
}