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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i, j, n, m;
 	string s, t;
 	cin >> n >> s >> m;
 	vector<ll> a[27];
 	ll te[27] = {0};
 	for (i = 0; i < n; i++) {
 		ll v = s[i] - 'a';
 		te[v]++;
 		for (j = 0; j < 26; j++) {
 			a[j].pb(te[j]);
 		}
 	}
 	while (m--) {
 		cin >> t;
 		for (i = 0; i < 26; i++) {
 			te[i] = 0;
 		}
 		for (i = 0; i < sz(t); i++) {
 			ll v = t[i] - 'a';
 			te[v]++;
 		}
 		ll ind = 0;
 		for (i = 0; i < 26; i++) {
 			ll f = lower_bound(all(a[i]), te[i]) - a[i].begin();
 			ind = max(ind, f);
 		}
 		cout << ind + 1 << endl;
 	}
	return 0;
}