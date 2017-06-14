#include<iostream>
#include<vector>
#include<queue>

using namespace std;

long D[1000010];

int main()
{
 long f,s,g,u,d;
 scanf("%ld%ld%ld%ld%ld",&f,&s,&g,&u,&d);
 long up,down,x;

 queue<long> Q;
 Q.push(s);

 while(!Q.empty())
 {
  x = Q.front();
  Q.pop();
  up = x+u;
  down=x-d;

  if(up<=f && D[up]==0 && u)
  {
   Q.push(up);
   D[up] = D[x]+1;
  }
  if(down>=1 && D[down]==0 && d)
  {
   Q.push(down);
   D[down] = D[x]+1;
  }
  if(up==g || down==g)
   break;
 }

 if((D[g]==0) && (g!=s))
  printf("use the stairs");
 else
  printf("%ld",D[g]);

return 0;
}
