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
const ll L = 100;
string arr[L];
ll vis[L][L];
ll r1, c1, r2, c2, n;
vector <pll> v1;
vector <pll> v2;
ll f = 0;
void dfs(ll x, ll y, ll in)
{
	if (x < 0 || y < 0 || x >= n || y >= n || vis[x][y] == 1 || arr[x][y] == '1')
		return;
	vis[x][y] = 1;
	if (in == 0) {
		if (x == r2 && y == c2)
			f = 1;
		v1.pb({x,y});
	}
	else
		v2.pb({x,y});
	dfs(x + 1, y, in);
	dfs(x - 1, y, in);
	dfs(x, y + 1, in);
	dfs(x, y - 1, in);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	cin >> n;
 	cin >> r1 >> c1 >> r2 >> c2;
 	for (ll i = 0; i < n; i++) {
 		cin >> arr[i];
 	}
 	r1--;
 	r2--;
 	c1--;
 	c2--;
 	dfs(r1, c1, 0);
 	dfs(r2, c2, 1);
	ll ans = 1e18;
	if (f == 1) {
		cout << 0 << endl;
		return 0;
	}
 	for (ll i = 0; i < sz(v1); i++) {
 		for (ll j = 0; j < sz(v2); j++) {
 			ll temp = (v1[i].fi - v2[j].fi) * (v1[i].fi - v2[j].fi);
 			ll temp2 = (v1[i].se - v2[j].se) * (v1[i].se - v2[j].se);
 			ans = min(temp + temp2, ans);
 		}
 	}
 	cout << ans << endl;
	return 0;
}