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
    cout << fixed << setprecision(5);
 	ll hh, mm;
 	cin >> hh >> mm;
 	ll h, d, c, n;
 	cin >> h >> d >> c >> n;
 	ll mins = 60 - mm;
	if (mins == 60)
		mins = 0;
	ll hours = 0; 	   
	ll f = 0;
	if (hh < 20) {
		hours = 20 - hh;
		if (mins != 0)
			hours--;
	}
	else f = 1;
	ll extime = hours * 60 + mins;
	ld ans1 = 1e18, ans2 = 1e18;
	ll req = h / n;
	if (h % n != 0)
		req++;
	if (f == 1) {
		ans1 = req * 0.8 * c;
		cout << ans1 << endl;
		return 0;
	}
	ans1 = req * c;
	h += extime * d;
	req = h / n;
	if (h % n != 0)
		req++;
	ans2 = req * 0.8 * c;
	cout << min(ans1, ans2) << endl; 
	return 0;
}