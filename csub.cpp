#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int t, n;
	long long count;
	char ch;
	cin>>t;
	while(t--)
	{
		count = 0;
		scanf("%d", &n);
		getchar();
		for(int i=0; i<n; i++)
			if(getchar()=='1')
				count++;
		cout<<((count+1)*count)/2<<endl;
	}
	return 0;
}
