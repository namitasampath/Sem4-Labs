/*
1). Write a program to construct a heap for a given list of keys using bottom-up heap
construction algorithm.
*/

#include<stdio.h>
#include<conio.h>
void heapify(int h[],int n)
{
int i,k,v,heapify,j;
for(i=(n/2);i>=1;i--)
{
k=i;v=h[k];heapify=0;
while(heapify==0&&2*k<=n)
{
j=2*k;
if(j<n)
if(h[j]<h[j+1])
j=j+1;
if(v>=h[j])
heapify=1;
else
  {
h[k]=h[j];
k=j;
}
}
h[k]=v;
}
return;
}
void main()
{
int h[20],i,n;
clrscr();
printf("\nEnter the number of Elements:");
scanf("%d",&n);
printf("\nEnter the Elements:");
for(i=1;i<=n;i++)
scanf("%d",&h[i]);
printf("\ndisplay the array:");
for(i=1;i<=n;i++)
{
printf("%d\t",h[i]);
}
heapify(h,n);
printf("\nThe heap created:");
for(i=1;i<=n;i++)
{
printf("%d\t",h[i]);
}
getch();
}
