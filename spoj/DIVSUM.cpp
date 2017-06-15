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
const unsigned INF = 1<<30;
const int MAX_INPUT = 500000;
vector<bool> Table((500000>>1)+100);
int Prime[(500000>>1)];
//}Global Var Ends


void sieve()
{
// int sqr = sqrt(MAX_INPUT);
 for(int i=3;i<=707;i+=2)
 {
  if(!Table[(i-1)>>1])
   for(int j=i*i;j<=MAX_INPUT;j+=i)
   {
    if(j&1) Table[(j-1)>>1]=true;
   }
 }
 Prime[0]=2;
 int cnt=1;
 for(int i=1;2*i<=MAX_INPUT;i++)
 {
  if(!Table[i])
   Prime[cnt++]=(i<<1)+1;
 }
// forn(i,100)
//  cout<<Prime[i]<<" ";
}

int power(int b, int p)
{
 int temp=1;
 while(p)
 {
  if(p&1)
   temp=temp*b;
  b=b*b;
  p>>=1;
 }
return temp;
}

int main ()
{
    sieve();
    int testCase,Q;
    scanf ("%d", &testCase);
    while ( testCase-- ) {
        GI(Q);
        int save = Q;
        int result = 1;
        int exponent = 0;
    for(int i=0;Prime[i]<=Q;i++)
    {
      if(Q%Prime[i]==0)
      {
       while(Q%Prime[i]==0)
       {
        Q/=Prime[i];
        exponent++;
       }
       int tmp = power(Prime[i],exponent+1)-1;
       tmp /= (Prime[i]-1);
       result *= tmp;
       exponent=0;
      }
    }
    cout<<result-save<<endl;
    }
return 0;
}
