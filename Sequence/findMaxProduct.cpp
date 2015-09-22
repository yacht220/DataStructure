/*
 * Find maximum product among all N-1 sequence combinations and the target N-1 sequenc in a gvien N sequence WITHOUT applying division.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findMaxProduct(int array[], int size)
{
    int numOfNegative = 0;
    int numOfZero = 0;
    int minPositive;
    int maxNegative;
    int product = 1;
    bool duplicateHitFlag = false;
    bool firstHitPositiveFlag = true;
    bool firstHitNegativeFlag = true;
    int elemRemoved;

    printf("\n\nOriginal sequence is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");

    // Extract some info.
    for (int i = 0; i < size; i++)
    {
        if (0 <= array[i])
        {
            if (true == firstHitPositiveFlag)
            {
                minPositive = array[i];
                firstHitPositiveFlag = false;
            }

            if (minPositive > array[i])
            {
                minPositive = array[i];
            }

            if (0 == array[i])
            {
                numOfZero++;
            }
        }
        else
        {
            if (true == firstHitNegativeFlag)
            {
                maxNegative= array[i];
                firstHitNegativeFlag = false;
            }

            if (maxNegative < array[i])
            {
                maxNegative = array[i];
            }
            numOfNegative++;
        }
    }

    // At least there are 2 zeros.
    if (1 < numOfZero)
    {
        printf("At least 2 zeros.\n");
        product = 0;
    }
    // There is negative number.
    else if (0 < numOfNegative)
    {
        printf("There is negative number.\n");
        // Even number of negative number.
        if (0 == (numOfNegative % 2)) 
        {
            elemRemoved = minPositive;
        }
        // Odd number of negative number.
        else
        {
            elemRemoved = maxNegative;
        }
    }
    // There is NO negative number.
    else
    {
        printf("There is NO negative number.\n");
        elemRemoved = minPositive;
    }

    if (0 != product)
    {
        printf("The %d - 1 sequence of max product is: ", size);
        for (int i = 0; i < size; i++)
        {
            if (false == duplicateHitFlag) 
            {
                if (elemRemoved != array[i])
                {
                    product *= array[i];
                    printf("%d, ", array[i]);
                }
                else
                {
                    duplicateHitFlag = true;
                }
            }
            else
            {
                product *= array[i];
                printf("%d, ", array[i]);
            }
        }
    }

    printf("\nThe max product of %d - 1 sequence is %d.\n", size, product);
}

int main(int argc, char** argv)
{
    int array0[] = {11,2,3,4,5,6,7,8,9,10};
    int array1[] = {0,2,3,0,5,6,7,8,9,10};
    int array2[] = {11,2,3,0,5,6,7,8,9,10};
    int array3[] = {11,2,3,0,5,-6,7,8,9,10};
    int array4[] = {11,2,3,0,5,-6,7,-8,9,10};
    int array5[] = {11,2,3,-4,5,6,-7,8,9,10};
    int array6[] = {-11,2,3,-4,5,6,-7,8,9,10};

    findMaxProduct(array0, 10);
    findMaxProduct(array1, 10);
    findMaxProduct(array2, 10);
    findMaxProduct(array3, 10);
    findMaxProduct(array4, 10);
    findMaxProduct(array5, 10);
    findMaxProduct(array6, 10);

    return 1;
}
