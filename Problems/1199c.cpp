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
ll power(ll x, ll y)
{ 
    ll res = 1;  
    x = x;
    while (y > 0) { 
        if (y & 1) res = (res * x); 
        y = y >> 1;
        x = (x * x);   
    } 
    return res; 
}
const ll L = 4e5 + 5;
ll table[L][25];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n, i;
 	cin >> n >> i;
 	ll original_n = n;
	vector <ll> rs;
 	ll a = i * 8;
 	a /= n;
 	if (a >= 19) {
 		cout << 0 << endl;
 		return 0;
 	}   
 	ll p = power(2, a);
 	map <ll,ll> el;
 	ll x;
 	for (ll i = 0; i < n; i++) {
 		cin >> x;
 		if(el[x] == 0)
 			rs.pb(x);
 		el[x]++;
 	}
 	sort(all(rs));
 	vector <ll> ne;
 	for (ll i = 0; i < sz(rs); i++) {
 		ne.pb(el[rs[i]]);
 	}
 	if (p >= sz(ne)) {
 		cout << 0 << endl;
 		return 0;
 	}
 	n = sz(ne);
 	for (ll j = 0; (1 << j) <= n; j++) {
 		for (ll i = 0; i + (1 << j) - 1 < n; i++) {
 			if (j == 0)
 				table[i][j] = ne[i];
 			else
 				table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
 		}
 	}
 	ll ans = -1;
 	for (ll i = 0; i < n; i++) {
 		for (ll j = 0; j <= a; j++)
	 		ans = max(ans, table[i][j]);
 	}
 	cout << original_n - ans << endl;
	return 0;
}