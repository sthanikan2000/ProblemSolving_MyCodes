#include <iostream>
using namespace std;
  
// Merges two subarrays of array[].
// First subarray is arr[begin..mid].
// Second subarray is arr[mid+1..end].
// Function to print an array.
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout<<endl;
}
void merge(int array[], int const left, int const mid, int const right){
    int i=0;
    int arr1[mid-left+1];
    int arr2[right-mid];
    while (i<=(mid-left)){
        arr1[i]=array[left+i];
        i++;
    }
    int a=0;
    while(a<=(right-mid-1)){
        arr2[a]=array[mid+1+a];
        a++;
    }
    //printArray(arr1, mid+1);
    //printArray(arr2, right-mid);
    //cout<<"***";
    
    int j=0;
    int k=0;
    for(int l=left;l<=right;l++){
        if((j<=mid-left)and(k<=right-mid-1)){
            if (arr1[j]>arr2[k]){
                array[l]=arr2[k];
                k++;
            }
            else{
                array[l]=arr1[j];
                j++;
            }
        }
        else{
            if(j<=(mid-left)){
                array[l]=arr1[j];
                j++;
            }
            if(k<=(right-mid-1)){
                array[l]=arr2[k];
                k++;
            }
        }
    }
}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted.
void mergeSort(int array[], int const begin, int const end){
    if (begin<end){
       int mid=(begin+end)/2;
        mergeSort(array,begin,mid);
        //printArray(array,end+1);
        mergeSort(array,mid+1,end);
        //printArray(array,end+1);
        merge(array,begin,mid,end);
        //printArray(array,end+1);
    }

}
  

  
int main()
{
    int arr_size;
    cin >> arr_size;

    int arr[arr_size];

    for (int i=0; i<arr_size; i++) {
         cin >> arr[i];
    }
  
    //printArray(arr, arr_size);
  
    mergeSort(arr, 0, arr_size - 1);

    printArray(arr, arr_size);
    return 0;
}