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
 	ll i,n;
 	string s;
 	ll z=0,o=0,t=0;
 	cin>>n>>s;
 	for(i=0;i<n;i++)
 	{
 		if(s[i]=='0')
 			z++;
 		else if(s[i]=='1')
 			o++;
 		else
 			t++;
 	}
 	ll ch=n/3;
 	ll zc=1,oc=1,tc=1;
 	for(i=0;i<n;i++)
 	{
 		if(s[i]=='0')
 		{
 			if(z>ch)
 			{
 				if(zc<=ch)
 					zc++;
 				else if(o<ch)
 				{
 					z--,o++;
 					s[i]='1';
 				}
 				else
 				{
 					z--,t++;
 					s[i]='2';
 				}
 			}
 		}
 		else if(s[i]=='1')
 		{
 			if(o>ch)
 			{
 				if(z<ch)
 				{
 					o--,z++;
 					s[i]='0';
 				}
 				else if(oc<=ch)
 					oc++;
 				else
 				{
 					o--,t++;
 					s[i]='2';
 				}
 			}
 		}
 		else
 		{
 			if(t>ch)
 			{
 				if(z<ch)
 				{
 					t--,z++;
 					s[i]='0';
 				}
 				else
 				{
 					t--,o++;
 					s[i]='1';
 				}
 			}
 		}
 	}
 	cout<<s<<endl;
	return 0;
}