#include <stdio.h>
#define B printf("\n");
#define D(a,x,b) for(a=x;a<b;a++){
#define E(x) q[18+((x/9)/3)+((x%9)/3)*3]
#define F(x) q[9+x%9]
#define G(x) )&(1<<x))>>x
#define H(x) |=1<<t[x];F(x)|=1<<t[x];E(x)|=1<<t[x];
int main(){
  int t[81],q[27],a[81],v[81],i,j,k,l=-1,m=0,n=0;
  D(i,0,81)scanf("%d",t+i);a[i]=0;v[i]=0;}
I:D(i,0,27)q[i]=0;}
  D(i,0,81)if(t[i]){q[i/9]H(i)}}
  if(n){n=0;goto K;}k=-1;m=0;
  D(i,0,81)if(!t[i]){m++;a[i]=0;
      D(j,1,10)a[i]+=((q[i/9]|F(i)|E(i)G(j);}
      if(a[i]==9)goto K;if(k==-1)k=i;if(a[i]>a[k])k=i;}}
  if(!m){for(i=0;i<81;printf("%d",t[i++]))if(!(i%9)&&i)B B return 0;}
J:D(i,1,10)if(!(((q[k/9]|F(k)|E(k)G(i))){
      t[k]=i;l++;v[l]=k;goto I;}}
K:k=v[l];if(a[k]==8){t[k]=0;l--;n++;goto I;}
  q[k/9]H(k)t[k]=0;a[k]++;goto J;}