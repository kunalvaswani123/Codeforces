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
	if(a.fi == b.fi)
	    return a.se > b.se;
	else
		return a.fi < b.fi; 
} 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pll>v;
    ll n,x,y,i;
    cin >> n;
    for(i=0;i<n;i++)
    {
    	cin >> x >> y;
    	v.pb(mp(x,y));
    }
    cout << "-------" << endl;
    sort(v.begin(),v.end(),cmp);
	for(i=0;i<n;i++)
    	cout << v[i].fi << ' ' << v[i].se << endl;
	return 0;
}