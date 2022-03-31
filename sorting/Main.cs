namespace SortingAlgorithms
{
    public class SortingAlgorithms
    {
        public const int LIST_LENGTH = 1000000;
        public const int MAX_RANDOM_VALUE = 1000000;

        public static async Task Main()
        {
            //float quickSortTime = TimedSort("quick", LIST_LENGTH, MAX_RANDOM_VALUE);
            //Console.WriteLine($"Sorted list in {quickSortTime} ms using Quicksort");

            //float insertionSortTime = TimedSort("insertion", LIST_LENGTH, MAX_RANDOM_VALUE);
            //Console.WriteLine($"Sorted list in {insertionSortTime} ms using Insertion Sort");

            //float bubbleSortTime = TimedSort("bubble", LIST_LENGTH, MAX_RANDOM_VALUE);
            //Console.WriteLine($"Sorted list in {bubbleSortTime} ms using Bubble Sort");

            using StreamWriter file = new("output.txt", append: true);

            for (int i = 0; i < 10000000; i += 1000)
            {
                float time = TimedSort("quick", i, 1000000);

                await file.WriteLineAsync($"{i} {time}");
                Console.WriteLine($"{i} {time}");
            }
        }

        // Sorting Algorithms
        public static void BubbleSort(int[] inputArray)
        {
            for (int i = 0; i < inputArray.Length - 1; i++)
            {
                bool swapOccurred = false;
                for (int j = 0; j < inputArray.Length - i - 1; j++)
                {
                    if (inputArray[j] > inputArray[j + 1])
                    {
                        Swap(inputArray, j, j + 1);
                        swapOccurred = true;
                    }
                }
                if (swapOccurred == false)
                {
                    return;
                }
            }
        }

        public static void InsertionSort(int[] inputArray)
        {
            int i = 1;
            while (i < inputArray.Length)
            {
                int j = i - 1;
                while (j >= 0 && inputArray[j] > inputArray[j+1])
                {
                    Swap(inputArray, j, j + 1);
                    j--;
                }

                i++;
            }
            return;
        }

        public static void QuickSort(int[] inputArray, int start, int end)
        {
            if (end - start <= 1)
            {
                return;
            }

            int pivotIndex = start;

            for (int i = start + 1; i < end; i++)
            {
                if (inputArray[i] < inputArray[pivotIndex])
                {
                    Swap(inputArray, pivotIndex, pivotIndex + 1);

                    if (pivotIndex + 1 != i) {
                        Swap(inputArray, pivotIndex, i);
                    }

                    pivotIndex += 1;
                }
            }

            QuickSort(inputArray, start, pivotIndex);
            QuickSort(inputArray, pivotIndex + 1, end);
        }

        public static void SelectionSort(int[] inputArray)
        {
            for (int i = 0; i < inputArray.Length; i++)
            {
                int smallestValueIndex = i;
                for (int j = i; j < inputArray.Length; j++)
                {
                    if (inputArray[j] < inputArray[smallestValueIndex])
                    {
                        smallestValueIndex = j;
                    }
                }
                Swap(inputArray, i, smallestValueIndex);
            }
        }
        
        // Functions to make running easier
        public static float TimedSort(string algorithm, int listLength, int maxRandomValue)
        {
            var timer = new System.Diagnostics.Stopwatch();
            int[] unsortedArray = randomizeArray(listLength, maxRandomValue);

            timer.Start();

            if (algorithm == "quick")
            {
                QuickSort(unsortedArray, 0, listLength);
            }
            else if (algorithm == "bubble")
            {
                BubbleSort(unsortedArray);
            }
            else if (algorithm == "insertion")
            {
                InsertionSort(unsortedArray);
            }
            else if (algorithm == "selection")
            {
                SelectionSort(unsortedArray);
            }

            timer.Stop();

            //printArray(unsortedArray);

            return timer.ElapsedMilliseconds;
        }

        public static int[] randomizeArray(int listLength, int maxRandomValue)
        {
            Random random = new Random();
            int[] randomArray = new int[listLength];

            for (int i = 0; i < listLength; i++)
            {
                int randomValue = random.Next(0, maxRandomValue);
                randomArray[i] = randomValue;
            }

            return randomArray;
        }

        public static void printArray(int[] inputArray)
        {
            for (int i = 0; i < inputArray.Length; i++)
            {
                Console.WriteLine(inputArray[i]);
            }
        }

        // Functions to make sorting easier
        public static void Swap(int[] inputArray, int firstIndex, int secondIndex)
        {
            int temp = inputArray[firstIndex];

            inputArray[firstIndex] = inputArray[secondIndex];
            inputArray[secondIndex] = temp;
        }
    }
}