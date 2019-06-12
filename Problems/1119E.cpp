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
 	ll i,n,x,temp;
 	ll count = 0;
 	ll ans = 0;
 	cin >> n;
 	for(i=0;i<n;i++)
 	{
 		cin >> x;
 		if(count == 0 && x >= 3)
 		{
 			temp = x / 3;
 			ans += temp;
 			count += (x - temp * 3);
 		}
 		else if(count == 0 && x < 3)
 			count += x;
 		else
 		{
			temp = x / 2;
			if(temp >= count)
			{
				ans += count;
				x -= count * 2;
				temp = x / 3;
				ans += temp;
				count = x - temp * 3;
			}
			else
			{
				ans += temp;
				x -= temp * 2;
				count += (x - temp);
			}
 		}
 	}
 	cout << ans << endl;
	return 0;
}