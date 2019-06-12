#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
ll power(ll x,ll y,ll p) 
{ 
    ll res=1;  
    x=x%p;
    while (y > 0) 
    { 
        if(y&1) 
            res=(res*x)%p; 
        y=y>>1;
        x=(x*x)%p;   
    } 
    return res; 
}
map<ll,ll>m;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i;
 	m[33554431] = 1082401;
	m[16777215] = 5592405;
	m[8388607] = 178481;
	m[4194303] = 1398101;
	m[2097151] = 299593;
	m[1048575] = 349525;
	m[524287] = 1;
	m[262143] = 87381;
	m[131071] = 1;
	m[65535] = 21845;
	m[32767] = 4681;
	m[16383] = 5461;
	m[8191] = 1;
	m[4095] = 1365;
	m[2047] = 89;
	m[1023] = 341;
	m[511] = 73;
	m[255] = 85;
	m[127] = 1;
	m[63] = 21;
	m[31] = 1;
	m[15] = 5;
	m[7] = 1;
	m[3] = 1;
 	ll q,x;
 	cin >> q;
 	while(q--)
 	{
 		cin >> x;
 		if(m[x] != 0)
 		{
 			cout << m[x] << endl;
 			continue; 
 		}
 		ll val = 0;
 		ll temp = x;
 		while(temp > 0)
 		{
 			temp /= 2;
 			val++;
 		}
 		ll ans = 1 << val;
 		ans--;
 		cout << ans << endl;
 	}
	return 0;
}