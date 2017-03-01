#pragma once

#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
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

vector<int> TwoSum(vector<int> &numbers, int targetNumber)
{
	vector<int> result;
	if (numbers.size() <= 1)
		return result;

	hash_map<int,int> myMap;
	for (size_t i = 0; i < numbers.size(); ++i)
		myMap[numbers[i]] = i;
	for (size_t i = 0; i < numbers.size(); ++i)
	{
		int value = targetNumber - numbers[i];
		if (myMap.find(value) != myMap.end())
		{
			size_t index = myMap[value];
			if (index == i)
				continue;
			if (index < i)
			{
				result.push_back(index + 1);
				result.push_back(i + 1);
				
			}
			else
			{
				result.push_back(i + 1);
				result.push_back(index + 1);
			}
			break;
		}
	}
	return result;
}

vector<vector<int>> ThreeSum(vector<int> &numbers)
{
	vector<vector<int>> result;
	if (numbers.size() <= 2)
		return result;

	sort(numbers.begin(), numbers.end());

	for (size_t i = 0; i < numbers.size()-2; ++i)
	{
		size_t j = i + 1;
		size_t k = numbers.size() - 1;
		while (j < k)
		{
			vector<int> current;
			if (numbers[i] + numbers[j] + numbers[k] == 0)
			{
				current.push_back(numbers[i]);
				current.push_back(numbers[j]);
				current.push_back(numbers[k]);
				result.push_back(current);
				j++;
				k--;
				while (j<k &&numbers[j-1]==numbers[j])
					j++;
				while (j<k&&numbers[k] == numbers[k+1])
					k--;
			}
			else if (numbers[i] + numbers[j] + numbers[k] < 0)
			{
				j++;
			}
			else
			{
				k--;
			}
		}
		while (i < numbers.size()-1 && numbers[i] == numbers[i+1])
			i++;
	}
	return result;
}

int ThreeSumClosest(vector<int> &number, int target)
{
	if (number.size() <= 2)
		return -1;

	int result = 0;

	sort(number.begin(), number.end());
	int distance = INT_MAX;

	for (size_t i = 0; i < number.size()-2; ++i)
	{
		size_t j = i + 1;
		size_t k = number.size() - 1;

		while (j < k)
		{
			int tempValue = number[i] + number[j] + number[k];
			int tempDistance = 0;
			if (tempValue < target)
			{
				int tempDistance = target - tempValue;
				if (tempDistance < distance)
				{
					distance = tempDistance;
					result = number[i] + number[j] + number[k];
				}
				j++;
			}
			else if (tempValue > target)
			{
				int tempDistance = tempValue - target;
				if (tempDistance < distance)
				{
					distance = tempDistance;
					result = number[i] + number[j] + number[k];
				}
				k--;
			}
			else
			{
				result = number[i] + number[j] + number[k];
				return result;
			}
		}

	}
	return result;
}

vector<vector<int>> FourSum(vector<int> &num, int target)
{
	vector<vector<int>> result;
	if (num.size() <= 3)
		return result;
	sort(num.begin(), num.end());

	for (size_t i = 0; i < num.size() - 3; ++i)
	{
		if (i>0 && num[i] == num[i-1])
			continue;
		for (size_t j = i+1; j < num.size() - 2;++j)
		{
			if (j > i+1 && num[j] ==num[j-1])
				continue;
			size_t k = j + 1;
			size_t l = num.size() - 1;
			while (k<l)
			{
				int sum = num[i] + num[j] + num[k] + num[l];
				if (sum == target)
				{
					vector<int> current;
					current.push_back(num[i]);
					current.push_back(num[j]);
					current.push_back(num[k]);
					current.push_back(num[l]);
					result.push_back(current);

					do
					{
						++k;
					} while (k < l && num[k] == num[k - 1]);

					do
					{
						++l;
					} while (k < l && num[l] == num[l + 1]);

				}
				else if (sum < target)
					++k;
				else
					--l;
			}
		}
	}
	return result;
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
	cout << endl;

	cout << "2 求和" << endl;
	vector<int> F = { 1, 3, 5, 7, 9 };
	vector<int> twoSum = TwoSum(F, 10);
	cout << "result";
	for (vector<int>::iterator itr = twoSum.begin(); itr != twoSum.end(); ++itr)
	{
		cout << " " << *itr;
	}
	cout << endl;

	cout << "3 求和" << endl;
	vector<int> G = { -5, -3, -1, 7, 8, 9 };
	vector<vector<int>> threeSum = ThreeSum(G);
	for (auto itr = threeSum.begin(); itr!=threeSum.end(); ++itr)
	{
		for (auto item:(*itr))
		{
			cout << " " << item;
		}
		cout << endl;
	}
	cout << endl;

	cout << "3 求和：离目标最近的三个数求和 " << endl;
	vector<int> H = { 1, 2, 3, 5, 8, 9 };
	int threeSumClosest =  ThreeSumClosest(H, 23);
	cout << "three sum closest is : " << threeSumClosest << endl;

	cout << endl;
	cout << "4 求和" << endl;
	vector<int> J = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	vector<vector<int>>  fourSum = FourSum(J, 10);
	for (auto itr = fourSum.begin(); itr != fourSum.end(); ++itr)
	{
		for (auto item : (*itr))
		{
			cout << " " << item;
		}
		cout << endl;
	}

}






