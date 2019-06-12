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
char ans[5][105];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n;
 	cin>>n;
 	char c1='a',c2='b';
 	for(i=0;i<n-1;i+=2)
 	{
 		ans[0][i]=c1,ans[0][i+1]=c1;
 		ans[1][i]=c2,ans[1][i+1]=c2;
 		char temp=c1;
 		c1=c2;
 		c2=temp;
 	}
 	c1='d',c2='e';
 	ans[2][0]='c';
 	ans[3][0]='c';
 	for(i=1;i<n-1;i+=2)
 	{
 		ans[2][i]=c1,ans[2][i+1]=c1;
 		ans[3][i]=c2,ans[3][i+1]=c2;
 		char temp=c1;
 		c1=c2;
 		c2=temp;
 	}
 	if(n%2==0)
 	{
 		ans[2][n-1]='f';
 		ans[3][n-1]='f';
 	}
 	else
 	{
 		ans[0][n-1]='f';
 		ans[1][n-1]='f';
 	}
 	for(i=0;i<4;i++)
 	{
 		for(j=0;j<n;j++)
 			cout<<ans[i][j];
 		cout<<endl;
 	}
	return 0;
}