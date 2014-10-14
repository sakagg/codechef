#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int T;
	int n, m;
	LL mx, sum, num;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		scanf("%lld", &num);
		mx = sum = num;
		for(int i=1; i<n; i++)
		{
			scanf("%lld", &num);
			mx = max(mx, num);
			sum += num;
		}
		num = m+sum-n*mx;
		if(num>=0 && num%n==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

