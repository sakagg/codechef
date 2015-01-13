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

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

int main()
{
	int T;
	char a[1100];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", a);
		int cnt[26] = {0};
		for(int i=0; a[i]; i++)
			cnt[a[i]-'a']++;
		int i;
		for(i=0; i<26; i++)
			if(cnt[i]!=i+1 && cnt[i]!=0)
				break;
		if(i==26)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

