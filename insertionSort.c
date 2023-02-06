#include<stdio.h>
int main()
{
	int Ar[100],i,j,temp,n;
	
	printf("Enter the size of Array :\n");
	scanf("%d",&n);
	printf("Enter elements of Array :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&Ar[i]);
	}
	printf("----------- Insertion Sort -------------\n");
	
	for(i=1;i<n;i++)
	{
		temp=Ar[i];
		j=i-1;
		while(j>=0 && Ar[j]>temp)
		{
			Ar[j+1]=Ar[j];
			j--;
		}
		Ar[j+1]=temp;
	}
	printf("Sorted Elements are :\n");
	for(i=0;i<n;i++)
	{
		printf("Index %d Element %d\n",i+1,Ar[i]);
	}
	
	return 0;
}
