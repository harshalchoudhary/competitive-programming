#include<iostream>

using namespace std;

int yeynum[510][510];
int bloggium[510][510];
int dp[510][510];

//bool Dir[510][510];
//1 UP bloggium; 0 DOWN

int compute(int r, int c)
{
 if(r<=0 || c<=0)
  return 0;
 if(dp[r][c]!=-1)
  return dp[r][c];
 //Dir[r][c] = true;
 int bloggium_sum = 0;
 for(int i=1;i<=r;i++)
  bloggium_sum+=bloggium[i][c];

 int yeynum_sum = 0;
 for(int j=1;j<=c;j++)
  yeynum_sum+=yeynum[r][j];

 return dp[r][c]=max(bloggium_sum+compute(r,c-1),yeynum_sum+compute(r-1,c));
}

int main()
{
 int n,m;
 scanf("%d%d",&n,&m);

 while(n && m)
 {
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++)
  {
   for(int j=1;j<=m;j++)
   {
    scanf("%d",&yeynum[i][j]);
   }
  }
  for(int i=1;i<=n;i++)
  {
   for(int j=1;j<=m;j++)
   {
    scanf("%d",&bloggium[i][j]);
   }
  }
  printf("%d\n",compute(n,m));
scanf("%d%d",&n,&m);
}
}
