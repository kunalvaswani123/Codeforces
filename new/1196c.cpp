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
#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll q, n, x, y, f1, f2, f3, f4;
 	cin >> q;
 	while (q--) {
 		cin >> n;
 		ll l = -1e5, r = 1e5, t = 1e5, b = -1e5;
 		for (ll i = 0; i < n; i++) {
 			cin >> x >> y >> f1 >> f2 >> f3 >> f4;
 			if (f1 == 0)
 				l = max(l, x);
 			if (f3 == 0)
 				r = min(r, x);
 			if (f2 == 0)
 				t = min(t, y);
 			if (f4 == 0)
 				b = max(b, y);
 		}
		if (b > t || l > r) 
			cout << 0 << endl;
		else
			cout << 1 << ' ' << l << ' ' << b << endl;
 	}   
	return 0;
}