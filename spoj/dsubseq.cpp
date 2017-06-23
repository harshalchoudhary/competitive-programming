/*
Difficulty:
Type:
Logic:
Links:
*/

//{
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define vi vector<int>
#define vs vector<string>
#define ll long long
#define ull unsigned long long
#define GI(t) scanf("%d",&(t))
#define init(a,v) memset(a,v,sizeof(a))
#define forn(i,n) for(int i=0;i<(n);i++)
#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
//}

using namespace std;

//{Global Var Starts
const unsigned MOD = 1000000007;
const int N = 111111;
int dp[N];
char s[N];
//}Global Var Ends


int main ()
{
    int testCase;
    scanf ("%d", &testCase);
    int prev[256];

    while ( testCase-- ) {
    scanf("%s",s+1);
    for(int i=1;s[i];i++)
     prev[s[i]]=0;

     dp[0]=1;
     int i;
    for(i=1;s[i];i++)
    {
     dp[i] = (dp[i-1] << 1);
     if(prev[s[i]])
      dp[i] -= dp[prev[s[i]]-1];
     if(dp[i]<0) dp[i]+=MOD;
     else if(dp[i]>=MOD) dp[i]-=MOD;
     prev[s[i]]=i;
    }

    cout<<dp[--i]<<endl;
	}

	return 0;
}
