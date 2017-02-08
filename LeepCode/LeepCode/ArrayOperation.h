#pragma once


int RemoveElementFromArray(int* A, int length, int element)
{
	int i = 0;
	int j = 0;
	for (int i=0; i < length; ++i)
	{
		if (A[i] == element)
			continue;

		A[j] = A[i];
		j++;
	}
	return j;
}

//前提条件是数组已经排好序
int RemoveDuplicatesElementFromSortedArray(int* A, int length)
{
	if (length == 0)
		return 0;

	int j = 0;
	for (int i = 1; i < length; ++i)
	{
		if (A[j] != A[i])
		{
			A[++j] = A[i];
		}
	}
	return j+1;
}
//前提条件是数组已经排好序
int RemoveNumberOfDuplicatesElementFromSortedArray(int *A, int length, int repeatCount)
{
	if (length == 0)
		return 0;

	int j = 0;
	int num = 0;
	for (int i = 1; i < length; ++i)
	{
		if (A[j] == A[i])
		{
			if (++num < repeatCount)
			{
				A[++j] = A[i];
			}
		}
		else
		{
			A[++j] = A[i];
			num = 0;
		}
	}
	return j + 1;	
}




