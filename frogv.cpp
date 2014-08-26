#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n, p, k, prev = -1, x, y;
	int a[100010];
	int b[100010];
	vector<int> imp;
	vector<int>::iterator start, end;
	cin>>n>>k>>p;
	for(int i=0; i<n; i++)
	{
		scanf("%d", a+i);
		b[i] = a[i];
	}
	sort(b, b+n);
	for(int i=1; i<n; i++)
		if(b[i] - b[i-1] > k && prev!=b[i])
		{
			imp.push_back(b[i]);
			prev = b[i];
		}
	start = imp.begin();
	end = imp.end();
	while(p--)
	{
		scanf("%d%d", &x, &y);
		if(upper_bound(start, end, a[x-1]) == upper_bound(start, end, a[y-1]))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
