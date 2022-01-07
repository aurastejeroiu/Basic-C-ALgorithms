long Y(long a, long b){  //a,b>=1
  if(b>a)  return 0;
  if(b==1) return a;
  if(b<=a) return (a-b+1)*Y(a,b-1);
}