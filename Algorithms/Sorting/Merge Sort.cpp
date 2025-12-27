#include<bits/stdc++.h>
using namespace std;
int arr[100005];
void Merge(int low, int mid, int high)
{
    int n1=mid-low+1;
    int n2=high-mid;

     /* create temp arrays */
    int left[n1],right[n2];

    /* Copy data to temp arrays left[] and right[] */
    for(int i=0; i<n1; i++){
        left[i]=arr[low+i];
    }
    for(int i=0; i<n2; i++){
        right[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=low;

    /* Merge the temp arrays back into arr[l..r]*/
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
            k++;
        }
        else{
            arr[k]=right[j];
            j++;
            k++;
        }
    }

    /* Copy the remaining elements of left[], if there are any */
    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of right[], if there are any */
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }

}
void MergeSort(int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;

        MergeSort(low,mid);
        MergeSort(mid+1,high);
        Merge(low,mid,high);
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

    MergeSort(0,Size-1);

    printf("\nSorted array using Merge Sort:\n");
    for(int i=0; i<Size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");

    return 0;
}
