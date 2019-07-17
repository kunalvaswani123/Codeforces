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
const ll L = 30;
ll dp[L][3][20];
ll rec(ll n, ll f, ll m, string k1)
{
	if (n == 20) {
		ll p = 0;
		if (m <= 3)
			p = 1;
		return p;
	}
	if (dp[n][f][m] != -1)
		return dp[n][f][m];
	ll l = 9;
	if (f)
		l = k1[n] - '0';
	ll ans = 0;
	for (ll i = 0; i <= l; i++)	{
		ll nf;
		if(i < k1[n] - '0')
			nf = 0;
		else
			nf = f;
		ll send = 0;
		if (i != 0) send++;
		ans += rec(n + 1, nf, send + m, k1);
	}
	return dp[n][f][m] = ans;
}
string to_s(ll a)
{
	string temp = "";
	while (a > 0) {
		temp += ((a % 10) + '0');
		a /= 10;
	}
	for (ll i = sz(temp); i < 20; i++)
		temp += '0';
	reverse(all(temp));
	return temp;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll t;
 	cin >> t;
 	while (t--) {
 		ll l, r;
 		cin >> l >> r;
 		string a1 = to_s(l - 1);
 		string a2 = to_s(r);
 		ll ans1, ans2;
	 	for (ll i = 0; i < 20; i++)
	 		for (ll j = 0; j < 2; j++)
	 			for (ll k = 0; k < 20; k++)
	 				dp[i][j][k] = -1;
 		ans1 = rec(0, 1, 0, a1);
 		for (ll i = 0; i < 20; i++)
	 		for (ll j = 0; j < 2; j++)
	 			for (ll k = 0; k < 20; k++)
	 				dp[i][j][k] = -1;
 		ans2 = rec(0, 1, 0, a2);
 		cout << ans2 - ans1 << endl;
 	}	   
	return 0;
}