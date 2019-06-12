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
 	ll i, n;
 	cin >> n;
 	string s;
 	cin >> s;
 	ll pans = 0;
 	ll ans = 1;
 	ll f, c = 1;
 	if(s[0] == '0')
 		f = 0;
 	else
 		f = 1;
 	s[n] = 1 - s[n-1];
 	ll f2 = 0;
 	for (i = 1; i < n + 1; i++)
 	{	
 		if (s[i] != s[i-1])
 		{
 			if (i != n)
	 			ans++;
 			if (c >= 3)
 				pans = max(pans, (ll)2);
 			else if (c == 2)
 			{
 				if (f2 == 1)
 					pans = max(pans, (ll)2);
 				else
 					pans = max(pans, (ll)1);
 				f2 = 1;
 			}
 			c = 1;
 		}	
 		else
 			c++;
 	}
 	cout << ans + pans << endl;
	return 0;
}