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
#define endl '\n'
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
ll b, w;
map <pll,ll> m;
vector <pll> temp;
void dfs(ll x, ll y, ll in)
{
	if (m[{x, y}] == 1)
		return;
	m[{x, y}] = 1;
	temp.pb({x, y});
	if (in == 0)
		b--;
	else
		w--;
	if (in == 0 && w == 0)
		return;
	if (in == 1 && b == 0)
		return;
	dfs(x + 1, y, 1 - in);
	if (in == 0 && w == 0)
		return;
	if (in == 1 && b == 0)
		return;
	dfs(x - 1, y, 1 - in);
	if (in == 0 && w == 0)
		return;
	if (in == 1 && b == 0)
		return;
	dfs(x, y + 1, 1 - in);
	if (in == 0 && w == 0)
		return;
	if (in == 1 && b == 0)
		return;
	dfs(x, y - 1, 1 - in);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll q;
	cin >> q;
	while (q--) {
		cin >> b >> w;
		ll sx = 1e6, sy = 1e6;
		m.clear();
		temp.clear();
		ll tb = b;
		ll tw = w;
		dfs(sx + 1, sy, 0);
		if (b == 0 && w == 0) {
			cout << "YES" << endl;
			for (ll i = 0; i < sz(temp); i++)
				cout << temp[i].fi << ' ' << temp[i].se << endl;
			continue;
		}
		m.clear();
		temp.clear();
		b = tb;
		w = tw;
		dfs(sx, sy, 1);
		if (b == 0 && w == 0) {
			cout << "YES" << endl;
			for (ll i = 0; i < sz(temp); i++)
				cout << temp[i].fi << ' ' << temp[i].se << endl;
			continue;	
		}
		cout << "NO" << endl;
	}	
	return 0;
}