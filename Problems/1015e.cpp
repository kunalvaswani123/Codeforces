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
#define endl '\n'
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
const ll L = 1e3 + 5;
string arr[L];
ll lr[L][L];
ll rl[L][L];
ll tb[L][L];
ll bt[L][L];
ll ans[L][L];
ll ans2[L][L];
vector <pair<pll,ll>> stars;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n, m;
 	cin >> n >> m;
 	for (ll i = 0; i < n; i++)
 		cin >> arr[i];
 	for (ll i = 0; i < n; i++) {
 		ll c = 0;
 		for (ll j = 0; j < m; j++) {
 			if (arr[i][j] == '*')
 				lr[i][j] = ++c;
 			else
 				c = 0;
 		}
 	}
 	for (ll i = 0; i < n; i++) {
 		ll c = 0;
 		for (ll j = m - 1; j >= 0; j--) {
 			if (arr[i][j] == '*')
 				rl[i][j] = ++c;
 			else
 				c = 0;
 		}
 	}
 	for (ll j = 0; j < m; j++) {
 		ll c = 0;
 		for (ll i = 0; i < n; i++) {
 			if (arr[i][j] == '*')
 				tb[i][j] = ++c;
 			else
 				c = 0;
 		}
 	}
 	for (ll j = 0; j < m; j++) {
 		ll c = 0;
 		for (ll i = n - 1; i >= 0; i--) {
 			if (arr[i][j] == '*')
 				bt[i][j] = ++c;
 			else
 				c = 0;
 		}
 	}
 	for (ll i = 0; i < n; i++) {
 		for (ll j = 0; j < m; j++) {
 			if (i != 0 && j != 0 && i != n - 1 && j != m - 1 && arr[i][j] == '*') {
 				ll a1 = tb[i - 1][j];
 				ll a2 = bt[i + 1][j];
 				ll a3 = lr[i][j - 1];
 				ll a4 = rl[i][j + 1];
 				ll len = min(a1, a2);
 				len = min(len, a3);
 				len = min(len, a4);
 				if (len >= 1)
 					stars.pb({{i + 1,j + 1}, len});
 			}
 		}
 	}
 	for (ll i = 0; i < sz(stars); i++) {
 		ll x = stars[i].fi.fi;
 		ll y = stars[i].fi.se;
 		ll len = stars[i].se;
 		ans[x - 1][y - len - 1] = max(ans[x - 1][y - len - 1], 2 * len + 1);
 		ans2[x - len - 1][y - 1] = max(ans2[x - len - 1][y - 1], 2 * len + 1);
 	}
 	for (ll i = 0; i < n; i++) {
 		ll c = ans[i][0];
 		for (ll j = 1; j < m; j++) {
 			c--;
 			c = max(c, ans[i][j]);
 			ans[i][j] = c; 
 		}
 	}
 	for (ll j = 0; j < m; j++) {
 		ll c = ans2[0][j];
 		for (ll i = 1; i < n; i++) {
 			c--;
 			c = max(c, ans2[i][j]);
 			ans2[i][j] = c;
 		}
 	}
 	ll f = 0;
 	for (ll i = 0; i < n; i++) {
 		for (ll j = 0; j < m; j++) {
 			if (arr[i][j] == '*') {
 				if (ans[i][j] == 0 && ans2[i][j] == 0)
  					f = 1;
 			}
 		}
 	}
 	if (f == 1) {
 		cout << -1 << endl;
 		return 0;
 	}
 	cout << sz(stars) << endl;
 	for (ll i = 0; i < sz(stars); i++)
 		cout << stars[i].fi.fi << ' ' << stars[i].fi.se << ' ' << stars[i].se << endl;
 	return 0;
}