#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t, n, ind;
	cin>>t;
	int a[100100], b[100100];
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; i++)
			scanf("%d", a+i);
//		sort(a, a+n);
		ind = 0;
		for(int i=1; i<n; i++)
			if((i&1) && a[i-1] > a[i])
				swap(a[i-1], a[i]);
			else if((!(i&1)) && a[i-1] < a[i])
				swap(a[i-1], a[i]);
		for(int i=0; i<n; i++)
			printf("%d ", a[i]);
		cout<<endl;
	}
	return 0;
}
