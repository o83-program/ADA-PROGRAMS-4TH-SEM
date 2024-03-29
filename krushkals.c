#include<stdio.h>
#include<conio.h>
void kruskals();
int c[10][10];
int n;                                    // No of edges

int main()
{
 int i,j;
 printf("\nEnter the no. of vertices: ");
 scanf("%d",&n);
 printf("\nEnter the cost matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&c[i][j]);
  }
 }
 kruskals();
}

void kruskals()
{
 int i,j,u,v,a,b,min;
 int ne=0,mincost=0;
 int parent[10];

 for(i=1;i<=n;i++)
 {
  parent[i]=0;
 }
 while(ne!=n-1)
 {
  min=9999;
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
     if(c[i][j]<min)
     {
      min=c[i][j];
      u=a=i;
      v=b=j;
     }
   }
  }
  while(parent[u]!=0)
  {
   u=parent[u];
  }
  while(parent[v]!=0)
  {
   v=parent[v];
  }
  if(u!=v)
  {
   printf("\n\t%C <---> %C = %d\n",a+65,b+65,min);
   parent[v]=u;
   ne=ne+1;
   mincost=mincost+min;
  }
  c[a][b]=c[b][a]=9999;
 }
 printf("\n Minimum cost is =%d",mincost);
}
