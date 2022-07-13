#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int a[20][20],reach[20],n;
void dfs(int v){
int i;
reach[v]=1;
for(i=1;i<=n;i++)
if(a[v][i]&&!reach[i]){
printf("\tn%d-->%d",v,i);
dfs(i);
}
}

int main(){
clock_t s,e;
int i,j,count=0;
printf("enter the no of vertices;\n");
scanf("%d",&n);
printf("enter the adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
s=clock();
dfs(1);
Sleep(400);
e=clock();
for(i=1;i<=n;i++)
if(reach[i])
count++;
if(count==n)
printf("\n graph connected");
else
printf("\n graph is disconnected");
printf("\nthe time taken for sorting the elements where n:%d is %f",n,((double)(e-s))/CLK_TCK);
return(0);
}
