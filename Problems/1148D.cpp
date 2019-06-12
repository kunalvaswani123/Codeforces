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
 	ll i,n;
 	cin >> n;   
 	set<pll,greater<pll> >mn;
 	set<pll>mx;
 	ll a,b;
 	for(i=1;i<=n;i++)
 	{
 		cin >> a >> b;
 		if(a < b)
 			mn.insert(mp(b,i));
 		else
 			mx.insert(mp(b,i));
 	}
 	if(sz(mn) > sz(mx))
 	{
	 	set<pll,greater<pll> > :: iterator it;
 		cout << sz(mn) << endl;
 		for(it=mn.begin();it!=mn.end();it++)
 			cout << (*it).se << ' ';
 		cout << endl;
 	}
 	else
 	{
	 	set<pll> :: iterator it;
 		cout << sz(mx) << endl;
 		for(it=mx.begin();it!=mx.end();it++)
 			cout << (*it).se << ' ';
 		cout << endl;	
 	}
	return 0;
}