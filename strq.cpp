
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

LL a[1000100][4][4];
LL b[1000100][4];
char s[1000100];

int getInd(char c)
{
	if(c=='c')
		return 0;
	if(c=='h')
		return 1;
	if(c=='e')
		return 2;
	if(c=='f')
		return 3;

	return -1;
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
	scanf("%s", s);
	for(int i=0; i<16; i++)
			a[0][i>>2][i&3] = 0;
	for(int i=0; s[i]; i++)
	{
		for(int j=0; j<16; j++)
			a[i+1][j>>2][j&3] = a[i][j>>2][j&3];
		for(int j=0; j<4; j++)
			b[i+1][j] = b[i][j];
		
		int ind = getInd(s[i]);

		for(int j=0; j<4; j++)
			a[i+1][j][ind] += b[i+1][j];

		b[i+1][ind]++;
	}

/*
	for(int i=0; i<=tot; i++)
	{
		for(int j=0; j<16; j++)
			cout<<a[i][j>>2][j&3]<<" ";
		cout<<endl;
	}
	for(int i=0; i<=tot; i++)
	{
		for(int j=0; j<4; j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
*/
	int q;
	SI(q);
	
	while(q--)
	{
		LL ans = 0;
		char x, y;
		int l, r;
		scanf("%c%c%c%c%d%d", &x, &x, &y, &y, &l, &r);
		int ind1 = getInd(x);
		int ind2 = getInd(y);
		l--;
		ans = a[r][ind1][ind2] - a[l][ind1][ind2];
		ans -= (b[r][ind2]-b[l][ind2])*b[l][ind1];
		printf("%lld\n", ans);
	}


	return 0;
}
