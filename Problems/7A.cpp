#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
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
 	ll i,j;
 	ll count=0;
 	vector<string>s;
	string te;
 	for(i=0;i<8;i++)
 	{
 		cin>>te;
 		ll f=0;
 		for(j=0;j<8;j++)
 		{
 			if(te[j]=='W')
 				f=1;
 		}
 		if(f==0)
 			count++;
 		s.pb(te);
 	}   
 	if(count==8)
 		cout<<count<<endl;
 	else
 	{
 		ll count2=0;
 		for(i=0;i<8;i++)
 		{
			ll f=0;
 			for(j=0;j<8;j++)
 			{
 				if(s[j][i]=='W')
 					f=1;
 			}
			if(f==0)
				count2++;
 		}
 		cout<<count+count2<<endl;
 	}
	return 0;
}