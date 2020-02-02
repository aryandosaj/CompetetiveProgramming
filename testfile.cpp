#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY        100

int array[MAXARRAY];
int indexArray[MAXARRAY];
int outputArray[MAXARRAY];

int indexCompare(const void *i1, const void *i2);

int main(void)
{
    int i, n;

    scanf("%d",&n);
    if (n >= MAXARRAY)
        exit(1);
    for(i=0;i<n;i++) {
        scanf("%d",&array[i]);
        indexArray[i]=i;
    }
    qsort(indexArray, n, sizeof(array[0]), indexCompare);
    for (i=0;i<n;i++)
        outputArray[indexArray[i]] = i;
    for(i=0;i<n;i++)
        printf("%d ", outputArray[i]);
    printf("\n");
    return 0;
}

int indexCompare(const void *i1, const void *i2)
{
    int index1 = *(int *) i1;
    int index2 = *(int *) i2;

    if (array[index1] < array[index2])
        return -1;
    if (array[index1] > array[index2])
        return 1;
    return 0;
}