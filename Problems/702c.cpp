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
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define ordered_set tree <ll, null_type,less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//K-th smallest
//cout << k << "kth smallest: " << *A.find_by_order(k - 1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
ll power(ll x, ll y, ll p)
{ 
    ll res = 1;  
    x = x % p;
    while (y > 0) { 
        if (y & 1) res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p;   
    } 
    return res; 
}
vector<ll>a;
vector<ll>b;
ll check(ll mid) {
	ll f = 0;
	ll prev = 0;
	ll end = -1e18;
	for (ll i = 0; i < sz(b); i++) {
		ll low = b[i] - mid;
		ll hi = b[i] + mid;
		ll ind1 = lower_bound(all(a), low) - a.begin();
		ll ind2 = upper_bound(all(a), hi) - a.begin();
		if (ind1 > prev)
			f = 1;
		prev = ind2;
		end = max(end, ind2);
		if (end >= sz(a))
			break;
	}
	return (f == 0 && end >= sz(a));
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,x;
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
    	cin >> x;
    	a.pb(x); 
    }
    for (ll i = 0; i < m; i++) {
    	cin >> x;
    	b.pb(x); 
    }
    sort(all(a));
    sort(all(b));
    ll l = 0;
    ll r = 2 * (1e9 + 1);
    ll ans = 1e18;
    while (l <= r) {
    	ll mid = l + (r - l) / 2;
    	if (check(mid)) {
    		ans = min(ans, mid);
    		r = mid - 1;
    	}
    	else
    		l = mid + 1;
    }
    cout << ans << endl;
	return 0;
}