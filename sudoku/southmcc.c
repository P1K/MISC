#include <stdio.h>
#define E(x) q[18+(x/27)+((x%9)/3)*3]
#define H(x) q[x/9]|=1<<t[x];q[9+x%9]|=1<<t[x];E(x)|=1<<t[x]
int main(){
  int t[81],q[27],a[81],v[81],i,j,k,l=-1,m=0,n=0;
  for(i=0;i<81;i++){scanf("%d",t+i);a[i]=0;v[i]=0;}
I:for(i=0;i<27;i++)q[i]=0;for(i=0;i<81;i++){if(t[i])H(i);}
  if(n){n=0;goto K;}k=-1;m=0;for(i=0;i<81;i++){if(!t[i]){m++;a[i]=0;
  for(j=1;j<10;j++){a[i]+=((q[i/9]|q[9+i%9]|E(i))&(1<<j))>>j;}
  if(a[i]==9)goto K;if(k==-1)k=i;if(a[i]>a[k])k=i;}}
  if(!m){for(i=0;i<81;printf("%d",t[i++]))
  if(!(i%9)&&i)printf("\n");printf("\n");return 0;}
J:for(i=1;i<10;i++)if(!(((q[k/9]|q[9+k%9]|E(k))&(1<<i))>>i)){
  t[k]=i;l++;v[l]=k;goto I;}
K:k=v[l];if(a[k]==8){t[k]=0;l--;n++;goto I;}
  H(k);t[k]=0;a[k]++;goto J;}
