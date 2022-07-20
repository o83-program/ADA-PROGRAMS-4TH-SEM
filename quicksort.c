#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[1000000];

void swap(int arr[], int index1,int index2){
  int temp= arr[index1];
  arr[index1] = arr[index2];
  arr[index2]=temp;
}

int partition(int arr[] ,int start , int end){
    int pivot = arr[end];
    int boundary = start-1;
    int i;
    for( i=start ; i<=end;i++){

        if(arr[i] <= pivot){
            boundary++;
            swap(arr,i,boundary);
        }

    }
    return boundary;

}

void quicksort(int arr[] , int start , int end){
 int i,j;
for( i=0;i<800;i++)
{
    for(j=0;j<400;j++)
    {

    }
}
    if(start>=end)
        return;

    int boundary = partition(arr, start , end);
    quicksort(arr ,start ,boundary-1);
    quicksort(arr ,boundary+1,end);

}


void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    time_t start, end;
    int n;
    srand(time(0));
    printf("Enter the no of elements \n");
    scanf("%d", &n);
	int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = rand();
    }

    start = time(NULL);
    quicksort(arr,0,n-1);
    end = time(NULL);

    printf("The array is sorted\n");
    // printf("The sorted array is: \n");
    // printArray(arr, n);

    printf("The time taken is %.10f\n", difftime(end, start) / CLOCKS_PER_SEC);
    return 0;
}
