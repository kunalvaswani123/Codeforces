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
const ll L = 3e5 + 5;
ll arr1[L];
ll arr2[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n, m;
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> arr1[i];
	cin >> m;
	for (ll i = 0; i < m; i++) cin >> arr2[i];
	ll st1 = 0;
	ll st2 = 0;
	ll ans = 0;
	ll a1 = arr1[0];
	ll a2 = arr2[0];
	while (st1 < n && st2 < m) {
		if (a1 == a2) {
			st1++, st2++;
			if (st1 < n && st2 < m) a1 = arr1[st1], a2 = arr2[st2];
			ans++;
		}
		else if (a1 < a2) {
			st1++;
			if (st1 < n) a1 += arr1[st1];
		}
		else if (a1 > a2) {
			st2++;
			if (st2 < m) a2 += arr2[st2];	
		}
	}
	if (st1 == n && st2 == m) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}