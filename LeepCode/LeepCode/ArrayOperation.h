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

//前提A、B数组都已经排好序，并且A分配的内存足够存储两个数组
int* MergeSortedArray(int *A, int m, int *B, int n)
{
	int i = m + n - 1;
	int j = m - 1;
	int k = n - 1;
	while (i >= 0)
	{
		if (j >= 0 && k >= 0)
		{
			if (A[j] > B[k])
			{
				A[i] = A[j];
				j--;
			}
			else
			{
				A[i] = B[k];
				k--;
			}
		}
		else if (j >= 0)
		{
			A[i] = A[j];
			j--;
		}
		else if (k >= 0)
		{
			A[i] = B[k];
			k--;
		}
		i--;

	}
	return A;
}



void OsForeachArrayElement(string title, int* A, int length)
{
	cout << title;
	for (int i = 0; i < length; ++i)
	{
		cout << " " << A[i];
	}
	cout << endl;
}

void ArrayDemo()
{
	cout << "数组当中移除某个元素" << endl;
	int A[5] = { 3, 2, 2, 5, 6 };
	OsForeachArrayElement("Raw:", A, 5);
	int aLength = RemoveElementFromArray(A, 5, 2);
	OsForeachArrayElement("Result:", A, aLength);

	cout << "从排序数组当中移除重复的元素" << endl;
	int B[6] = { 1, 2, 2, 3, 3, 4, };
	OsForeachArrayElement("Raw:", B, 6);
	int bLength = RemoveDuplicatesElementFromSortedArray(B, 6);
	OsForeachArrayElement("Result:", B, bLength);

	cout << "从排序数组当中移除指定数量的相同元素" << endl;
	int C[9] = { 1, 2, 2, 2, 3, 3, 3, 4, 4 };
	OsForeachArrayElement("Raw:", C, 9);
	int cLength = RemoveNumberOfDuplicatesElementFromSortedArray(C, 9, 2);
	OsForeachArrayElement("Result:", C, cLength);


	cout << "加一" << endl;
	vector<int> numbers = { 1, 2, 3, 4, 9 };
	cout << "Raw Number: ";
	for (auto number : numbers)
	{
		cout << number;
	}
	cout << endl;
	vector<int> result = PlusOne(numbers);

	cout << "Now Number: ";
	for (auto number : result)
	{
		cout << number;
	}
	cout << endl;


	cout << "杨辉三角" << endl;
	vector<vector<int>> values = YangHuiSanJiao(6);
	for (size_t i = 0; i < values.size(); ++i)
	{

		for (size_t j = 0; j < values[i].size(); ++j)
		{
			cout << " " << values[i][j];
		}
		cout << endl;
	}

	cout << "索引方式的杨辉三角" << endl;
	vector<int> rowValues = BetterYangHuiSanJiao(5);
	for (size_t i = 0; i < rowValues.size(); ++i)
	{
		cout << " " << rowValues[i];
	}
	cout << endl;

	cout << "合并排好序的两个数组" << endl;
	int D[9] = { 1, 3, 6, 9 };
	int E[5] = { 3, 4, 6, 8, 9 };
	int *mergeResult = MergeSortedArray(D, 4, E, 5);
	OsForeachArrayElement("Result: ", mergeResult, 9);
}






