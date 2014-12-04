#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
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
	scanf("%d", &T);
	while(T--)
	{
		int n, k;
		SI(n); SI(k);
		char a[n];
		scanf("%s", a);
		int possible = 0;
		int cnt = 0;
		int mx;
		for(int i=0; i<n;)
		{
			mx = i;
			i++;
			cnt++;
			while(a[i] == a[i-1])
				i++;
			if(i-mx >= k)
			{
				possible = 1;
				cnt += ((i-mx)-1)/k;
			}
//			printf("%d %d\n", i, mx);
		}
		if(possible)
			printf("%d\n", cnt);
		else
			printf("-1\n");
	}
	return 0;
}

