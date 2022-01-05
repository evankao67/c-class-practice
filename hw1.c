#include<stdio.h>
int num[25],i=0,min[25];
int main(){
while(scanf("%d",&num[i])!=EOF){
i++;
}
  int check0=num[0],check1=num[0];
  num[i]=num[i-1];
  for(int j=1;j<=i;++j){
 if(num[j]-check1==1){
         check1=num[j];
 }
 else{
         if(check0==check1){
                 printf("%d\n",check1);
         }
         else{
                 printf("%d->%d\n",check0,check1);
         }
         check0=num[j];
         check1=num[j];
 }
  }
}