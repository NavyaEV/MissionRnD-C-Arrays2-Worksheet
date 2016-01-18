/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
void quicksort(int *,int ,int );
int findSingleOccurenceNumber(int *A, int len) {
	int i = 0;
	if (A == nullptr)
	{
		return -1;
	}
	quicksort(A, 0, len - 1);
	while (i<len)
	{
		if (A[i]!=A[i+2])
		{
			return A[i];
		}
		i = i + 3;
	}
}
void quicksort(int *a, int left, int right)
{
	int p, l, r, t;
	l = left;
	r = right;
	p = a[left];
	while (l<r)
	{
		while ((a[r] >= p) && (l<r))
			r--;
		if (l<r)
		{
			t = a[l];
			a[l] = a[r];
			a[r] = t;
			l++;
		}
		while ((a[l] <= p) && (l<r))
			l++;
		if (l<r)
		{
			t = a[l];
			a[l] = a[r];
			a[r] = t;
			r--;
		}

		if (left<r)
			quicksort(a, left, l);
		if (right>l)
			quicksort(a, l + 1, right);
	}
}
