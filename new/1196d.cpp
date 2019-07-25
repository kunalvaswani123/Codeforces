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
ll v(char a)
{
	if (a == 'R')
		return 0;
	else if(a == 'G')
		return 1;
	return 2;
}
const ll L = 2e5 + 5;
ll a[L];
ll arr[4][L];
ll pref[4][L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll q, n, k;
 	cin >> q;
 	while (q--) {
 		cin >> n >> k;
 		char temp;
 		for (ll i = 1; i <= n; i++)
 			cin >> temp, a[i] = v(temp);
 		for (ll i = 0; i < 3; i++) {
 			ll t = i;
 			for (ll j = 1; j <= n; j++) {
 				arr[i][j] = t;
 				t++;
 				t %= 3;
 			}
 		}
 		for (ll i = 0; i < 3; i++) {
 			for (ll j = 1; j <= n; j++) {
 				if (arr[i][j] != a[j])
 					pref[i][j] = 1 + pref[i][j - 1];
 				else
 					pref[i][j] = pref[i][j - 1];
 			}
 		} 
 		ll ans = 1e18;
 		for (ll j = k; j <= n; j++) {
 			for (ll i = 0; i < 3; i++) {
 				ans = min(ans, pref[i][j] - pref[i][j - k]);
 			}
 		}
 		cout << ans << endl;
 	}    
	return 0;
}