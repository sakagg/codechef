
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		string c[6];
		for(int i=0; i<6; i++)
			cin>>c[i];
		if(c[0]==c[2] || c[0]==c[3])
			if(c[0]==c[4] || c[0]==c[5])
			{
				printf("YES\n");
				continue;
			}
		if(c[1]==c[2] || c[1]==c[3])
			if(c[1]==c[4] || c[1]==c[5])
			{
				printf("YES\n");
				continue;
			}
		printf("NO\n");
	}
	return 0;
}
