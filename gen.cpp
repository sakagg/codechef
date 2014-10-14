#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int T = 10;
	cout<<T<<endl;
	srand(time(NULL));
	while(T--)
	{
		int n = rand()%10000 + 10;
		cout<<n<<endl;
		for(int i=0; i<n; i++)
			cout<<1+rand()%100<<" ";
		cout<<endl;
	}
	return 0;
}

