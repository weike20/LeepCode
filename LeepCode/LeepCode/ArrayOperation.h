#pragma once

#include <vector>
using namespace std;


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

vector<int> PlusOne(vector<int> A)
{
	vector<int> result(A.size(), 0);
	int one = 1;
	for (int i = A.size() - 1; i >= 0; --i)
	{
		int sum = (int)one + A[i];
		result[i] = sum % 10;
		one = sum / 10;
	}
	if (one > 0)
	{
		result.insert(result.begin(), 1);
	}
	return result;
}

vector<vector<int>> YangHuiSanJiao(int rowCount)
{
	vector<vector<int>> values;
	values.resize(rowCount);
	for (int i = 0; i < rowCount; ++i)
	{
		values[i].resize(i + 1);
		values[i][0] = 1;
		values[i][values[i].size() - 1] = 1;
		for (size_t j = 1; j < values[i].size() - 1; ++j)
		{
			values[i][j] = values[i - 1][j - 1] + values[i - 1][j];
		}
	}
	return values;
}

vector<int> BetterYangHuiSanJiao(int rowNumber)
{
	vector<int> values;
	values.resize(rowNumber + 1, 1);
	for (int i = 0; i < rowNumber+1; ++i)
	{
		for (int j = i - 1; j >= 1 ; --j)
		{
			values[j] = values[j] + values[j - 1];
		}
	}
	return values;
}






