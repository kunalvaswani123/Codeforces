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
const ll L = 1e5 + 5;
const ll logn = 20;
ll parent[L];
ll dp[L][logn + 5];
vector <ll> ad[L];
ll vis[L];
ll depth[L];
void dfs(ll ind)
{
	vis[ind] = 1;
	for (ll v : ad[ind]) {
		if (!vis[v]) {
			depth[v] = depth[ind] + 1;
			dfs(v);		
		}
	}
}
ll lca(ll u, ll v)
{
	if (depth[u] < depth[v])
		swap(u, v);
	ll dist = depth[u] - depth[v];
	for (ll i = logn; i >= 0; i--) {
		ll temp = dist - (1 << i);
		if (temp >= 0) {
			dist -= (1 << i);
			u = dp[u][i];
		}
	}
	if (u == v)
		return u;
	for (ll i = logn; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) {
			u = dp[u][i];
			v = dp[v][i];
		} 
	}
	return parent[u];
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n;
 	cin >> n;
 	parent[0] = 0;
 	depth[0] = 0;
 	for (ll i = 1; i < n; i++) {
 		cin >> parent[i];
 		ad[i].pb(parent[i]);
 		ad[parent[i]].pb(i);
 	}
 	dfs(0);
 	for (ll i = 0; i < n; i++) {
 		for (ll j = 0; j <= logn; j++) {
 			dp[i][j] = 0;
 		}
 	}
 	for (ll i = 0; i < n; i++)
 		dp[i][0] = parent[i];
 	for (ll j = 1; j <= logn; j++) {
 		for (ll i = 0; i < n; i++) {
 			dp[i][j] = dp[dp[i][j - 1]][j - 1];
 		}
 	}
 	ll m, x;
 	cin >> m;
 	cin >> x;
 	ll ans = x;
 	for (ll i = 1; i < m; i++) {
 		cin >> x;
 		ans = lca(ans, x);
 	} 
 	cout << ans << endl;
 	return 0;
}