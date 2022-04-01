#include<bits/stdc++.h>

using namespace std;

void mergesort(int ar1[],int ar2[],int n1,int n2){
	int gap=ceil((float)((n1+n2)/2));
	while(gap>0)
	{
		int i=0;
		int j=gap;

		while(j<(n+m))
		{
			if(j<n && ar1[i]>ar1[j])
			 swap(ar1[i],ar1[j]);
            else if(j>=n && i<n && ar1[i]>ar2[j-n])
              swap(ar1[i],ar2[j-n]);
            else if(j>=n && i>=n && ar1[i-n]>ar2[j-n])
              swap(ar1[i-n],ar2[j-n]);
             i++;
             j++;

		} 
		if(gap==1)
			gap=0;
		else
			gap=ceil((float)gap/2);
	}

}

int main()
{
	int n1,n2;
	cin>>n1;
	int ar1[n1];
	int ar2[n2];
	for(int i=0;i<n1;i++)
	{
		cin>>ar1[i];
	}
	cin>>n2;
	for(int i=0;i<n2;i++)
	{
		cin>>ar2[i];
	}

	mergesort(ar1,ar2,n1,n2);

	for(int i=0;i<n1;i++)
	{
		cout<<ar1[i];
	}
	cout<<endl;
    for(int i=0;i<n2;i++)
	{
		cout<<ar2[i];
	}
	return 0;
}