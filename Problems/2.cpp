#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[10000];
ll count1[10000];
int main()
{
	ll i,j,n;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	for(i=1;i<=n;i++)
	{
		ll temp=i;
		while(1)
		{
			count1[temp]++;
			if(count1[temp]==2)
				break;
			temp=arr[temp];
		}
		cout<<temp<<' ';
		for(j=1;j<=n;j++)
			count1[j]=0;	
	}
	cout<<endl;
	return 0;
}