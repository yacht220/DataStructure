/*
 * Shell sort.
 * Let increment = size / 2 at beginning, then increment /= 2 until increment equals to 1. 
 * Per increment there are "increment" data sets. 
 * In each of data sets, do bubble sort or insertion sort. 
 */

#include <stdlib.h>
#include <stdio.h>

void shellSort(int array[], int size)
{
    for (int increment = size / 2; increment >= 1; increment /= 2)
    {
        /* per increment */
        for (int startIndexOfEachDataSet = 0; 
                startIndexOfEachDataSet < increment; 
                startIndexOfEachDataSet++)
        {
            /*  
             * do bubblesort in each of data sets per increment,
             * which has "increment" span between adjacent data. 
             */
            int lastUnsortedIndexPerDataSet = startIndexOfEachDataSet;
            while (lastUnsortedIndexPerDataSet < size)
            {
                lastUnsortedIndexPerDataSet += increment;
            }
            lastUnsortedIndexPerDataSet -= increment;

            while (lastUnsortedIndexPerDataSet > startIndexOfEachDataSet)
            {
                bool isSortedInUnsortedSubArray = true;
                for (int curIndexPerDataSet = startIndexOfEachDataSet; 
                        curIndexPerDataSet + increment <= lastUnsortedIndexPerDataSet; 
                        curIndexPerDataSet += increment)
                {
                    if (array[curIndexPerDataSet] > array[curIndexPerDataSet + increment])
                    {
                        int tmp = array[curIndexPerDataSet];
                        array[curIndexPerDataSet] = array[curIndexPerDataSet + increment];
                        array[curIndexPerDataSet + increment] = tmp;
                        isSortedInUnsortedSubArray = false;
                    }
                }
                lastUnsortedIndexPerDataSet -= increment;

                if (true == isSortedInUnsortedSubArray)
                {
                    printf("NO need to loop.\n");
                    break;
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    int array[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};
    int size = sizeof(array) / sizeof(array[0]);
    shellSort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
    return 1;
}
