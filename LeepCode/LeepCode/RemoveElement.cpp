
class ArrayOperation
{
public:

	int RemoveElementFromArray(int* A, int length, int element)
	{
		int i = 0;
		int j = 0;
		for (; i < length; ++i)
		{
			if (A[i] == element)
				continue;

			A[i] = A[j];
			j++;
		}
		return j;
	}
};




