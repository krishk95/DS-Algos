#include<iostream>
#include<cstdlib>
#include<ctime>


using namespace std;

int partition(int arr[],int low,int high)
{
    int i = low-1;
    int j = high+1;
    int pivot = arr[low];
    while(true)
    {
        do{
            i++;
        }while(arr[i] < pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if( i >= j)
            return j;
        swap(arr[i],arr[j]);
    }


}

int partition_r(int arr[],int low,int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(arr[random],arr[high]);
    return partition(arr,low,high);
}

void execute_quick_sort(int arr[],int low,int high)
{
    if(low < high)
    {
        int random_number = partition_r(arr,low,high);
        execute_quick_sort(arr,low,random_number);
        execute_quick_sort(arr,random_number+1,high);
    }
}


void print_array(int arr[],int size)
{
    for(int i = 0;i<size;i++)
        cout << arr[i] << "\t";
}

int main()
{
    int array_size;
    cout << "Enter the size of array";
    cin >> array_size;
    int arr[array_size];
    cout << "\nEnter the array elements:\n";
    for(int i = 0 ; i <array_size ; i++)
    {
        cin >> arr[i];
    }
    execute_quick_sort(arr,0,array_size-1);
    print_array(arr,array_size);
    return 0;
}