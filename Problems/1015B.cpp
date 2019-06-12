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
vector<ll>v;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,i,j,k;
 	string s,t;
 	cin>>n;
 	cin>>s>>t;
 	for(i=0;i<n;i++)
 	{
 		if(s[i]!=t[i])
 		{
 			for(j=i+1;j<n;j++)
 			{
 				if(s[j]==t[i])
 				{
 					for(k=j-1;k>=i;k--)
 					{
 						v.pb(k+1);
 						char temp=s[k];
 						s[k]=s[k+1];
 						s[k+1]=temp;
 					}
 					break;
 				}
 			}
 		}
 	}
 	for(i=0;i<n;i++)
 	{
 		if(s[i]!=t[i])
 		{
 			cout<<-1<<endl;
 			return 0;
 		}
 	}
 	cout<<v.size()<<endl;
 	for(i=0;i<v.size();i++)
 		cout<<v[i]<<' ';
 	cout<<endl;
	return 0;
}