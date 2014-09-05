#include<bits/stdc++.h>

using namespace std;

int main()
{
// Uncomment to use TestCases
	int T, len, i;
	char s[100100];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		len = strlen(s);
		for(i=0; i<len/2; i++)
			if(s[i]!=s[len-1-i])
				break;
		if(i>=len/2)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}

