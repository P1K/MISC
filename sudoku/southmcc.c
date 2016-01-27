#define E(x) q[18+(x/27)+((x%9)/3)*3]
#define H(x) q[x/9]|=1<<t[x];q[9+x%9]|=1<<t[x];E(x)|=1<<t[x]
main(){
  int t[81],q[27],a[81],v[81],i,j,k,l,m,n;
  for(i=0;i<81;scanf("%d",t+i++));
A:for(i=0;i<27;q[i++]=0);for(i=0;i<81;i++){if(t[i])H(i);}if(n)
  {n=0;goto C;}k=-1;m=0;for(i=0;i<81;i++){if(!t[i]){m++;a[i]=0;
  for(j=1;j<10;j++){a[i]+=((q[i/9]|q[9+i%9]|E(i))&(1<<j))>>j;}
  if(a[i]>8)goto C;if(k==-1)k=i;if(a[i]>a[k])k=i;}}if(!m){for
  (i=0;i<81;printf("%d%s",t[i],++i%9?"":"\n"));return 0;}
B:for(i=1;i<10;i++)if(!(((q[k/9]|q[9+k%9]|E(k))&(1<<i))>>i))
  {t[k]=i;v[l++]=k;goto A;}
C:k=v[l];if(a[k]==8){t[k]=0;l--;n++;goto A;}H(k);t[k]=0;a[k]++;
  goto B;}
