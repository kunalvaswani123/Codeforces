#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define american_pie 3.1415926535
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define qq queue
#define pqq priority_queue
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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll q,n;
 	string s;
 	cin >> q;
 	while(q--)
 	{
 		cin >> n >> s;
 		if(n == 2)
 		{
 			ll a = s[0] - '0';
 			ll b = s[1] - '0';
 			if(b <= a)
 			{
 				cout << "NO" << endl;
 				continue;
 			}
 		}
 		cout << "YES" << endl;
 		cout << 2 << endl;
 		cout << s[0] << ' ' << &s[1] << endl;
 	}   
	return 0;
}