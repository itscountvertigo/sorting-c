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

int main(void) 
{
    int array[100000];
    randomize_array(array, sizeof array / sizeof *array, 1000);

    time_t start = time(NULL);
 
    bubble_sort(array, sizeof array / sizeof *array);

    time_t end = time(NULL);

    printf("Executed in %ld seconds\n", end - start);
    /*
    for (int i = 0; i < sizeof array / sizeof *array; i++) {
        printf("%u\n", array[i]);
    } 
    */

    return 0;
}
