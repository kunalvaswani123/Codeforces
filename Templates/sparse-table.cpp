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
ll arr[L];
ll table[L][20];
ll query(ll a, ll b)
{
	ll len = b - a + 1;
	vector <ll> v;
	ll c = 0;
	while (len > 0) {
		if (len % 2 == 1)
			v.pb(c);
		len /= 2;
		c++;
	}	
	reverse(all(v));
	ll ans = 1e18;
	ll prev = 0;
	for (ll i = 0; i < sz(v); i++) {
		ans = min(ans, table[a + prev][v[i]]);
		prev += (1 << v[i]);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n, q, a, b;
 	cin >> n;
 	for (ll i = 0; i < n; i++)
 		cin >> arr[i];
 	for (ll j = 0; (1 << j) <= n; j++) {
 		for (ll i = 0; i + (1 << j) - 1 < n; i++) {
 			if (j == 0)
 				table[i][j] = arr[i];
 			else
 				table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
 		}
 	}
 	cin >> q;
 	while (q--) {
 		cin >> a >> b;
 		cout << query(a, b) << endl;
 	}
	return 0;
}