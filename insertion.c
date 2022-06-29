#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
int insertion_sort(int a[],int n){
int i,j,item;
for(i=0;i<n;i++){
    item=a[i];
    j=i-1;
    while(j>=0 && a[j]>item){
        a[j+1]=a[i];
        j=j-1;
    }
    a[j+1]=item;
}
}
void main(){
int a[20000],i,j,n,num,u=0,l=400,result  ;
clock_t s,e;
printf("Insertion sort\n");
n=1000;
while(n<=10000){
for(i=0;i<n;i++){
    a[i]=n-i;
}
s=clock();
result= insertion_sort(a,n);
Sleep(150);
e=clock();
printf("\nTime taken for Insertion_sort where n : %d is: %f\n",n,((double)(e-s))/CLK_TCK);
n=n+1000;
}
}
