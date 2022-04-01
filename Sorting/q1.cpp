#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int sum1=0,sum2=0;
    int diff;
	int a[n];
	for(int i=0; i<n; i++)
	{
	  cin>>a[i];
    }
	sort(a,a+n);
	for(int i=0; i<n/2; i++)
	{
	 sum1+=a[i];
	}
	 for(int i=n/2; i<n; i++)
	 {
	   sum2+=a[i];
	 }
     diff=sum2-sum1;
     cout<<diff;

}


