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
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	vector< pair<int, int> > all(k);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	sortv(a);
	for(int i=0; i<k; i++)
	{
		scanf("%d%d", &all[i].f, &all[i].s);
		if(all[i].f > all[i].s)
			swap(all[i].f, all[i].s);
	}
	sortv(all);
	int count = 0;
	int end = -1;
	int j = 0;
	for(int i=0; i<k; i++)
	{
		if(all[i].f <= end)
			end = max(all[i].s, end);
		else
		{
			for(; j<n && a[j] <= end; j++)
				count++;
			end = all[i].s;
			for(; j<n && a[j]<all[i].f; j++);
		}
	}
	printf("%d\n", n-count);
	return 0;
}

