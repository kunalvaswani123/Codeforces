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
 	ll f,r,c;
 	cin >> f >> r >> c;
 	ll ans = 0;
 	ans = min(f/3,r/2);
 	ans = min(ans,c/2);
 	f -= ans*3;
 	r -= ans*2;
 	c -= ans*2;
 	ans *= 7;
 	ll i,j,tf,tr,tc;
 	ll finalans = -1;
	for(i=0;i<7;i++)
	{
		tf = f;
		tr = r;
		tc = c;
		ll count = 0;
		ll j = i;
		ll tempans = ans;
		while(count < 7)
		{
			if(j == 0)
			{
				if(tf > 0)
					tf--,tempans++;
				else
					break;
			}
			if(j == 1)
			{
				if(tr > 0)
					tr--,tempans++;
				else
					break;
			}
			if(j == 2)
			{
				if(tc > 0)
					tc--,tempans++;
				else
					break;
			}
			if(j == 3)
			{
				if(tf > 0)
					tf--,tempans++;
				else
					break;
			}
			if(j == 4)
			{
				if(tc > 0)
					tc--,tempans++;
				else
					break;
			}
			if(j == 5)
			{
				if(tr > 0)
					tr--,tempans++;
				else
					break;
			}
			if(j == 6)
			{
				if(tf > 0)
					tf--,tempans++;
				else
					break;
			}
			count++;
			j++;
			if(j == 7)
				j = 0;
		}
		finalans = max(finalans,tempans);
	}
	cout << finalans << endl;
	return 0;
}