#include<stdio.h>
int main()
{
	int Arr[100],X,i,j,temp;
	
	printf("Enter the Size of Array :\n");
	scanf("%d",&X);
	printf("Enter elements of Array :\n");
	for(i=0;i<X;i++)
	{
		scanf("%d",&Arr[i]);
	}
	for(i=0;i<X-1;i++)
	{
		for(j=0;j<X-1-i;j++)
		{
			if(Arr[j]>Arr[j+1])
			{
				temp=Arr[j];
				Arr[j]=Arr[j+1];
				Arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<X;i++)
	{
		printf("Index %d Element %d\n",i+1,Arr[i]);
	}
	return 0;
}
