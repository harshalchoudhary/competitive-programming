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
const unsigned INF = 1<<30;
//}Global Var Ends


int main ()
{
    int N,Q;
    GI(N); GI(Q);
    long long x[50010],y[50010];

    double totalArea=0,Area[50010];
    double ar = 0, var=0;

    scanf("%lld%lld",&x[0],&y[0]);
    scanf("%lld%lld",&x[1],&y[1]);
    ar=x[0]*y[1]-x[1]*y[0];

    for(int i=2;i<N;i++)
    {
      scanf("%lld%lld",&x[i],&y[i]);
      ar+=x[i-1]*y[i]-x[i]*y[i-1];
      var = ar + (x[i]*y[0]-x[0]*y[i]);
      var/=2;

      if(var<0)
       var *= -1;

      Area[i] = var;
    }
     totalArea=var;


    long long f1,f2;
    double arr=0,area;
    forn(i,Q)
    {
     scanf("%lld%lld",&f1, &f2);
     arr=(x[0]*y[f1]-x[f1]*y[0])+(x[f1]*y[f2]-x[f2]*y[f1])+(x[f2]*y[0]-x[0]*y[f2]);

    //  cout<<arr<<endl;
      if(arr<0)
       arr*=-1;
      arr/=2;

     //cout<<arr<<endl;

     area=arr+Area[min(f1,f2)]+totalArea-Area[max(f1,f2)];
     if(area<(totalArea-area))
      printf("%.1lf\n",area);
     else
      printf("%.1lf\n",totalArea-area);

    }

	return 0;
}
