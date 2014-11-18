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
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	int n, m;
	char a[550][550];
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
		scanf("%s", a[i]);
	int count1=0, count2=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			if((i+j)%2==0)
			{
				if(a[i][j] == '1')
					count1++;
				else
					count2++;
			}
			else
				if(a[i][j] == '1')
					count2++;
				else
					count1++;
		}
	printf("%d\n", min(count1, count2));
	return 0;
}

