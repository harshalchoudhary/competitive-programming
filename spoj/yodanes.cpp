/*was gettin WA on using cout instead of printf*/

#include<iostream>
#include<map>
using namespace std;

long long inversion_count = 0;

void merge(long arr[], long p, long q, long r)
{
 long n1 = q-p+1;
 long n2 = r-q;
 long L[n1];
 long R[n2];

 for(long i=0;i<n1;i++)
 {
  L[i]=arr[p+i];
 }
 L[n1]=99999999;

 for(long i=0;i<n2;i++)
 {
  R[i]=arr[q+1+i];
 }
 R[n2]=9999999;

 long i=0;
 long j=0;
 long k=p;

 while(k<=r)
 {
  if(L[i]<=R[j])
  {
   arr[k]=L[i];
   i++;
   k++;
  }
 else if(L[i]>R[j])
 {
  arr[k]=R[j];
  j++;
  k++;
  inversion_count+=n1-i;
 }
}
}

void merge_sort(long arr[], long p, long r)
{
 if(p<r)
 {
  long q = (p+r)/2;
  merge_sort(arr,p,q);
  merge_sort(arr,q+1,r);
  merge(arr,p,q,r);
 }
}


int main()
{
  //  freopen("input.txt","r",stdin);
 int t;
 long n,i;
 long arr[200002];
 scanf("%d",&t);
 char yoda[33333][22];
 string word;
 map<string,int> hash;
 while(t--)
 {
  hash.clear();
  cin>>n;
  for(int i=1;i<=n;i++)
   scanf("%s",yoda[i]);

  for(int i=1;i<=n;i++)
  {
   cin>>word;
   hash[word]=i;
  }

 // scanf("%ld",&n);
  for(i=0;i<n;i++)
   arr[i]=hash[yoda[i+1]];
  merge_sort(arr,0,n-1);
  printf("%lld\n",inversion_count);
  inversion_count=0;
 }
//getch();
return 0;
}
