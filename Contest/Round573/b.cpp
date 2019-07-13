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
 	string s1,s2,s3;
 	cin >> s1 >> s2 >> s3;
 	ll a1[4];
 	ll a[4];
 	a[0] = s1[0] - '0';
 	a[1] = s2[0] - '0';
 	a[2] = s3[0] - '0';
 	a1[0] = a[0];
 	a1[1] = a[1];
 	a1[2] = a[2];
 	char b[4];
 	b[0] = s1[1];
 	b[1] = s2[1];
 	b[2] = s3[1];
 	sort(a,a+3);
 	if (b[0] == b[1] && b[1] == b[2]) {
 		if (a[0] == a[1] && a[1] == a[2])
 			cout << 0 << endl;
 		else if (a[1] - a[0] == 1 && a[2] - a[1] == 1)
 			cout << 0 << endl;
 		else if (a[1] - a[0] == 1 || a[2] - a[1] == 1 || a[2] - a[0] == 1)
 			cout << 1 << endl;
 		else if (a[2] - a[0] == 2 || a[1] - a[0] == 2 || a[2] - a[1] == 2)
 			cout << 1 << endl;
 		else if (a[0] == a[1] || a[1] == a[2])
 			cout << 1 << endl;
 		else
 			cout << 2 << endl; 
 	}
 	else if (b[0] == b[1] || b[1] == b[2] || b[2] == b[0]) {
 		if (b[0] == b[1]) {
 			if (abs(a1[1] - a1[0]) == 1 || abs(a1[1] - a1[0]) == 2 || a1[1] == a1[0])
 				cout << 1 << endl;
 			else
 				cout << 2 << endl;
 		}
 		else if (b[1] == b[2]) {
 			if (abs(a1[2] - a1[1]) == 1 || abs(a1[2] - a1[1]) == 2 || a1[1] == a1[2])
 				cout << 1 << endl;
 			else
 				cout << 2 << endl;	
 		}
 		else {
 			if (abs(a1[2] - a1[0]) == 1 || abs(a1[2] - a1[0]) == 2 || a1[0] == a1[2])
 				cout << 1 << endl;
 			else
 				cout << 2 << endl;	
 		}
 	}
 	else
 		cout << 2 << endl;
	return 0;
}