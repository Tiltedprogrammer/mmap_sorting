#include "merge_sort.h"
#include "comparator.h"
#include <stdlib.h>

void merge_sort(char**array, int n)
{
	if(n < 2)
	{
		return;
	}

	int pos = 0;
	int i = 0;
	char **arrayB = (char**)malloc(sizeof(char*) * n);
	if(!arrayB) exit(1);

	merge_sort_recurse(array, arrayB, n, &pos);

	if(pos == 1)
	{
		for(i = 0; i < n; i++)
		{
			array[i] = arrayB[i];
		}
	}
	free(arrayB);
}

void merge_sort_recurse(char **arrayA, char **arrayB, int n, int *pos)
{
    int i;
    //for (i =  0; i < n; i++)
      //  {
        //    printf("%s ", array[i]);
        //}
	//printf("\n");
	//pointer to rezult
	*pos = 0;
	if(n < 2)
	{
		return;
	}



	int mid = n / 2;
	// points to relut
	int pos0; 
	int pos1; 

	merge_sort_recurse(arrayA, arrayB, mid, &pos0);
	merge_sort_recurse(arrayA + mid, arrayB + mid, n - mid, &pos1);

	if(pos0 != pos1)
	{
		if(pos0 == 0)
		{
		    int i;
			for(i = mid; i < n; i++)
			{
				arrayA[i] = arrayB[i];
			}
		}
		else
		{   int i;
			for( i = mid; i < n; i++)
			{
				arrayB[i] = arrayA[i];
			}
		}
	}

	if(pos0 == 0)
	{
		merge(arrayA, mid, arrayA + mid, n - mid, arrayB);
		*pos = 1;
		for (i = 0; i < n; i++)
		    {
	//	        printf("%s ", arrayB[i]);
		    }
		//    printf("\n");
	}
	else
	{
		merge(arrayB, mid, arrayB + mid, n - mid, arrayA);
		*pos = 0;
		//for (i = 0; i < n; i++)
		  //  {
		     //   printf("%s ", array[i]);
		    //}
		    //printf("\n");

	}


}

void merge(char **L, int nL, char **R, int nR, char **array)
{
	int l = 0;
	int r = 0;
	int k = 0;

	while(l < nL && r < nR)
	{
		if(comparator(L[l], R[r]) == -1)
		{
			array[k++] = L[l++];
		}
		else
		{
			array[k++] = R[r++];
		}
	}

	while(l < nL)
	{
		array[k++] = L[l++];
	}
	while(r < nR)
	{
		array[k++] = R[r++];
	}
}
