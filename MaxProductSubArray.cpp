#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int currmax=a[0];
	int currmin=a[0];
	int ans=INT_MIN;
	int prevmax=a[0];
	int prevmin=a[0];
	for(int i=1;i<n;i++)
	{
	    currmax=std::max({prevmax*a[i],prevmin*a[i],a[i]});
	    currmin=std::min({prevmax*a[i],prevmin*a[i],a[i]});
	    ans=max(ans,currmax);
	    prevmax=currmax;
	    prevmin=currmin;
	}
	cout<<ans;
	return 0;
}