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
const ll L=1e5+5;
ll arr[2*L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin>>n;
 	for(i=0;i<n;i++)
 		cin>>arr[i];
 	set<ll>ecount;
 	set<ll>ocount;
 	ll count=1;
 	if(arr[n-1]%2==0)
 		arr[n]=1;
 	else
 		arr[n]=0;
 	for(i=1;i<n;i++)
 	{
 		if(i!=1&&arr[i]==arr[i-1])
 		{
 			if(arr[i-2]%2==0&&arr[i]%2==0)
 			{
 				arr[i-2]=max(arr[i],arr[i-2]);
 				arr[i]=arr[i-2];
 				arr[i-1]=arr[i-2];
 			}
 			else if(arr[i-2]%2==1&&arr[i]%2==1)
 			{
 				arr[i-2]=max(arr[i],arr[i-2]);
 				arr[i]=arr[i-2];
 				arr[i-1]=arr[i-2];
 			}
 			else
 			{
 				if(arr[i-2]<arr[i])
 				{
	 				arr[i-2]=max(arr[i],arr[i-2])+1;
	 				arr[i]=arr[i-2];	
	 				arr[i-1]=arr[i-2];
 				}
 				else
 				{
 					arr[i-2]=max(arr[i],arr[i-2]);
	 				arr[i]=arr[i-2];	
	 				arr[i-1]=arr[i-2];	
 				}
 			}
 		}
 	}
 	// for(i=0;i<n;i++)
 	// 	cout<<arr[i]<<' ';
 	// cout<<endl;
 	for(i=1;i<n;i++)
 	{
 		if(arr[i-1]%2==0&&arr[i]%2==0)
 		{
 			count++;
 		}
 		else if(arr[i-1]%2==1&&arr[i]%2==1)
 		{
 			count++;
 		}
 		else
 		{
 			if(arr[i-1]%2==1)
 				ocount.insert(count);
 			else
 				ecount.insert(count);
 			count=1;
 		}
 	}
 	if(arr[i-1]%2==1)
		ocount.insert(count);
	else
		ecount.insert(count);
 	ll of=0;
 	ll ef=0;
 	set<ll>::iterator it;
 	for(it=ocount.begin();it!=ocount.end();it++)
 	{
 		
 		ll check=*it;
 		if(check%2==1)
 			of=1;	
 	}
 	for(it=ecount.begin();it!=ecount.end();it++)
 	{
 		ll check=*it;
 		if(check%2==1)
 			ef=1;
 	}
 	if(of==1&&ef==1)
 		cout<<"NO"<<endl;
 	else
 		cout<<"YES"<<endl;
	return 0;
}