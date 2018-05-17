#include<iostream>
using namespace std;

void heapify_array(int arr[], int size,int initial_index);
void print_array(int arr[],int size);


void heapify_array(int user_array[],int array_size,int initial_largest_index)
{
    int largest_element_index = initial_largest_index;
    int left_child_index = 2*initial_largest_index + 1;
    int right_child_index = 2*initial_largest_index + 2;
    if( left_child_index < array_size && user_array[left_child_index] > user_array[largest_element_index])
        largest_element_index = left_child_index;
    if( right_child_index < array_size && user_array[right_child_index] > user_array[largest_element_index])
        largest_element_index = right_child_index;
    if(initial_largest_index != largest_element_index)
    {
        swap(user_array[initial_largest_index],user_array[largest_element_index]);
        heapify_array(user_array,array_size,largest_element_index);
    }
}

void print_array(int user_array[] , int array_size)
{
    for(int index = 0 ; index<array_size ; index++)
        cout << user_array[index] << "\t";
}
int main()
{
    int array_size;
    cout << "Enter the size of array";
    cin >> array_size;
    cout << "Enter the array elements";
    int user_array[array_size];
    for(int index = 0; index < array_size ; index++){
        cin >> user_array[index];
    }
    for(int heap_index = (array_size)/2 -1; heap_index >= 0 ; heap_index -- ){
        heapify_array(user_array,array_size,heap_index);
    }
    for(int array_index = array_size - 1 ; array_index >= 0 ; array_index--){
        swap(user_array[array_index],user_array[0]);
        

        for(int heap_index = (array_index)/2 -1; heap_index >= 0 ; heap_index -- ){
            heapify_array(user_array,array_index,heap_index);
        }
    }
    print_array(user_array,array_size);
    return 0;

}