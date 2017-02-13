#include <iostream>
#include <string>
#include <vector>

#include "ArrayOperation.h"

using namespace std;
void OsForeachArrayElement(string title,int* A,int length)
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
	cout << "remove a element from array !" << endl;
	int A[5] = {3,2,2,5,6};
	OsForeachArrayElement("Raw:", A, 5);
	int aLength = RemoveElementFromArray(A, 5, 2);
	OsForeachArrayElement("Result:", A, aLength);

	cout << "remove duplicates from sorted array !" << endl;
	int B[6] = { 1, 2, 2, 3, 3, 4, };
	OsForeachArrayElement("Raw:", B, 6);
	int bLength = RemoveDuplicatesElementFromSortedArray(B, 6);
	OsForeachArrayElement("Result:", B, bLength);

	cout << "remove a number of duplicates from sorted array !" << endl;
	int C[9] = { 1, 2, 2, 2, 3, 3, 3, 4, 4 };
	OsForeachArrayElement("Raw:", C, 9);
	int cLength = RemoveNumberOfDuplicatesElementFromSortedArray(C, 9, 2);
	OsForeachArrayElement("Result:", C, cLength);


	cout << "Plus One !" << endl;
	vector<int> numbers = { 1, 2, 3, 4, 9 };
	cout << "Raw Number: ";
	for (auto number: numbers)
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


	cout << "yang hui san jiao !" << endl;
	vector<vector<int>> values = YangHuiSanJiao(6);
	for (size_t i = 0; i < values.size(); ++i)
	{
		
		for (size_t j = 0; j < values[i].size(); ++j)
		{
			cout << " " << values[i][j];
		}
		cout << endl;
	}

	cout << "better yang hui san jiao !" << endl;
	vector<int> rowValues = BetterYangHuiSanJiao(5);
	for (size_t i = 0; i<rowValues.size(); ++i)
	{
		cout <<" "<< rowValues[i];
	}

}

void main()
{
	ArrayDemo();
}

