#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//K-th smallest
//cout << k << "kth smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
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
pll el2(deque<ll>d)
{
	deque<ll>temp = d;
	ll fir = temp.front();
	temp.pop_front();
	ll sec = temp.front();
	return pll {fir,sec};
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,q,x;
 	cin >> n >> q;
 	deque<ll>d;
 	ll mx = -1;
 	for(i=0;i<n;i++)
 	{
 		cin >> x;
 		mx = max(mx,x);
 		d.pb(x);
 	}
 	map<ll,pll>m;
 	ll c = 1;
 	while(d.front()!=mx)
 	{
 		ll fir = d.front();
 		d.pop_front();
 		ll sec = d.front();
 		d.pop_front();
 		m[c] = {fir,sec};
 		d.push_front(max(fir,sec));
 		d.push_back(min(fir,sec));
 		c++;
 	}
 	ll nu;
 	d.pop_front();
 	vector<ll>res;
 	while(!d.empty())
 		res.pb(d.front()), d.pop_front();
 	// cout << c << endl;
 	// for(i=0;i<sz(res);i++)
 	// 	cout << res[i] << ' ';
 	// cout << endl; 
 	while(q--)
 	{
 		cin >> nu;
 		if(nu < c)
 			cout << m[nu].fi << ' ' << m[nu].se << endl;
 		else
 		{
 			ll ind = nu - c;
 			ind = ind % (n - 1);
 			cout << mx << ' ' << res[ind] << endl;
 		}
 	}
	return 0;
}