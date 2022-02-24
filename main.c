#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *input_array, int idx_1, int idx_2) 
{
    int temp = input_array[idx_1];

    input_array[idx_1] = input_array[idx_2];
    input_array[idx_2] = temp;
}

void randomize_array(int *input_array, size_t size, int max_value) 
{
    for (int i = 0; i < size; i++)
    {
        // Generates random value between 1 and max_value, with (rand() % (max - min + 1)) + 1
        input_array[i] = (rand() % max_value) + 1;
    }
}

void bubble_sort(int *input_array, size_t size) 
{
    for (int i = 0; i < size; i++) 
    {
        int swap_occurred = 0;
        
        for (int j = 0; j < size - i - 1; j++)   
        {
            if (input_array[j] > input_array[j + 1]) 
            {
                swap(input_array, j, j + 1);
                swap_occurred = 1;
            }
        }
        
        if (swap_occurred == 0) { return; } 
    }
}

void insertion_sort(int *input_array, size_t size)
{
    int i = 1;
    while (i < size)
    {
        int j = i - 1;
        while (j >= 0 && input_array[j] > input_array[j + 1])
        {
            swap(input_array, j, j + 1);
            j--;
        }
        
        i++;
    }
    return;
}

void quick_sort(int *input_array, int idx_start, int idx_end)
{
    if (idx_end - idx_start <= 1) { return; }

    int pivot_idx = idx_start;
    
    for (int i = idx_start + 1; i < idx_end; i++) 
    {
        if (input_array[i] < input_array[pivot_idx])
        {
            swap(input_array, pivot_idx, pivot_idx + 1);

            if (pivot_idx + 1 != i)
            {
                swap(input_array, pivot_idx, i);
            }

            pivot_idx++; 
        }
    }

    quick_sort(input_array, idx_start, pivot_idx);
    quick_sort(input_array, pivot_idx + 1, idx_end);
}

void timed_sort(char *sorting_mode, int num_of_values, int max_value, int print_array)
{
    int array[num_of_values];
    randomize_array(array, num_of_values, max_value); 

    time_t start = time(NULL); // record time before sorting

    if (sorting_mode == "bubble")
    {
        bubble_sort(array, num_of_values);
    }
    else if (sorting_mode == "insertion")
    {
        insertion_sort(array, num_of_values);
    }
    else if (sorting_mode == "quick")
    {
        quick_sort(array, 0, num_of_values);
    } 

    time_t end = time(NULL); // record time again

    if (print_array == 1)
    {
        for (int i = 0; i < num_of_values; i++)
        {
            printf("%ld\n", array[i]);
        }
    }

    printf("Executed in %ld using %s sort\n", end - start, sorting_mode); 
}

int main(void) 
{
    //timed_sort("bubble",    100000, 10000, 0);
    //timed_sort("insertion", 100000, 10000, 0);
    timed_sort("quick",       900000, 10000, 0);
 
    return 0;
}
