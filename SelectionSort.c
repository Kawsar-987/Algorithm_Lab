#include<stdio.h>
int main()
{
	int array[100],i,j,n,min,temp;
	printf("Enter the Size of your Array :\n");
	scanf("%d",&n);
	printf("Enter Elements : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("_____\\\_____ Selection Sort _____///_____\n");
	for(i=0;i<(n-1);i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(array[min]>array[j])
			min=j;
		}
		if(min!=i)
		{
			temp=array[i];
			array[i]=array[min];
			array[min]=temp;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("Index %d Element %d\n",i+1,array[i]);
	}
}

/*#include <stdio.h>
int main() {
   int arr[10]={6,12,0,18,11,99,55,45,34,2};
   int n=10;
   int i, j, position, swap;
   for (i = 0; i < (n - 1); i++) {
      position = i;
      for (j = i + 1; j < n; j++) {
         if (arr[position] > arr[j])
            position = j;
      }
      if (position != i) {
         swap = arr[i];
         arr[i] = arr[position];
         arr[position] = swap;
      }
   }
   for (i = 0; i < n; i++)
      printf("%d\t", arr[i]);
   return 0;
}*/
