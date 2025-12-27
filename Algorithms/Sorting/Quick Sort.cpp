#include<bits/stdc++.h>
using namespace std;
int arr[101];
int Partition(int low, int high)
{
    int pivot=arr[high];
    int k=low;

    for(int i=low; i<high; i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[k],arr[i]);
            k++;
        }
    }
    swap(arr[k],arr[high]);
    return k;   // position of the pivot
}
void QuickSort(int low, int high)
{
    if(low<high)
    {
        int pivPos = Partition(low,high);
        QuickSort(low,pivPos-1);
        QuickSort(pivPos+1,high);
    }
}
int main()
{
    int Size;
    printf("Enter the size of array: ");
    scanf("%d",&Size);

    printf("\nEnter all the elements of the array:\n");
    for(int i=0; i<Size; i++)
    {
        scanf("%d",&arr[i]);
    }

    QuickSort(0,Size-1);

    printf("\nSorted array using Quick Sort:\n");
    for(int i=0; i<Size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");

    return 0;
}
