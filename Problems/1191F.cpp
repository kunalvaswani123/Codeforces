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
 	ll n, x, y;
 	cin >> n;
 	map <ll,vector<ll>> ym;
 	map <ll,ll> xm;
 	ordered_set xs;
 	set <ll> ys;
 	while (n--) {
 		cin >> x >> y;
		ym[y].pb(x);
		ys.insert(y);
		xm[x]++;
		xs.insert(x);
 	}   
 	ll ans = 0;
 	for (auto it : ys) {
 		ll cury = it;
 		sort(all(ym[cury]));
 		ans += ((sz(xs) + 1) * sz(xs)) / 2;
 		ll prev = 0;
 		for (ll i = 0; i < sz(ym[cury]); i++) {
 			ll curx = ym[cury][i];
 			ll temp = xs.order_of_key(curx);
 			ll les = temp - prev;
 			ans -= ((les + 1) * les) / 2;
 			prev = temp + 1;
 		}
 		ll les = sz(xs) - prev;
		ans -= ((les + 1) * les) / 2;
 		for (ll i = 0; i < sz(ym[cury]); i++) {
 			ll curx = ym[cury][i];
 			xm[curx]--;
 			if (xm[curx] == 0)
 				xs.erase(xs.find(curx));
 		}
 	}
 	cout << ans << endl;
	return 0;
}