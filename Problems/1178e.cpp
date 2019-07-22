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
    string s;
    cin >> s;
    ll n = sz(s);
    ll st = 0, en = n - 1;
    string t = "";
    ll cur = 0;
    ll req = n / 2; 
    char ex = 'z';
    while (1) {
    	if (cur == req)
    		break;
    	else if (cur + 1 == req) {
    		ex = s[st];
    		break;
    	}
    	else {
    		if (s[st] == s[en]) t += s[st], st++, en--;
    		else if(s[st + 1] == s[en]) t += s[en], st += 2, en--;
    		else if(s[st + 1] == s[en - 1]) t += s[st + 1], st += 2, en -= 2;
    		else t += s[st], st += 1, en -= 2;
    		cur += 2;
    	}
    }
    string ans = t;
    reverse(all(t));
    if (ex != 'z')
    	ans += ex;
    ans += t;
    cout << ans << endl;
	return 0;
}