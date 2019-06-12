#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pival 3.1415926535
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
 	ll i,n;
 	cin >> n;
 	while(n--)
 	{
 		string s;
 		cin >> s;
 		sort(s.begin(),s.end());
 		ll f = 0;
 		for(i=1;i<s.size();i++)
 		{
 			ll x = s[i] - s[i - 1];
 			if(x != 1)
 				f = 1;
 		}
 		if(f == 0)
 			cout << "Yes" << endl;
 		else
 			cout << "No" << endl;
 	}   
	return 0;
}