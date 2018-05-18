#include<iostream>
using namespace std;


void merge(int arr[],int low,int high,int mid)
{
    int i,j,k;
    int array1_size = mid - low +1;
    int array2_size = high - mid;
    int array1[array1_size];
    int array2[array2_size];

    for(int i =0;i<array1_size;i++)
        array1[i] = arr[i+low];
    for(int j = 0 ; j<array2_size;j++)
        array2[j] = arr[mid+j+1];

    i = 0 ;
    j = 0;
    k = low;
    while ( i < array1_size && j < array2_size)
    {
        if(array1[i] <= array2[j])
        {
            arr[k] = array1[i];
            i++;
        }
        else 
        {
            arr[k] = array2[j];
            j++;
        }
        k++;
    }
    while(i < array1_size){
        arr[k] = array1[i];
        i++;
        k++;
    }
    while(j < array2_size){
        arr[k] = array2[j];
        j++;
        k++;
    }
}

void print_array(int arr[],int size)
{
    for(int i = 0; i<size;i++)
    {
        cout << arr[i] << "\t";
    }
}
void merge_sort(int arr[],int low,int high)
{
   if(low < high){
        int mid = low + (high-low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);

        merge(arr,low,high,mid);
   }
}


int main()
{
    int array_size;
    cout << "Enter the size of array";
    cin >> array_size;
    int arr[array_size];
    cout << "Enter the array elements";
    for(int i = 0;i<array_size;i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr,0,array_size-1);
    print_array(arr,array_size);
}