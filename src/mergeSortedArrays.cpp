/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
void finddate1(char *, int *);
int getvalue1(char *, int, int);
int check1(int *, int *);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i=0, j=0, k=-1, key,d1[3],d2[3];
	struct transaction merge[10];
	if ((A==nullptr)||(B==nullptr))
		return NULL;
	while ((i<ALen)&&(j<BLen))
	{
		finddate1(A[i].date, d1);
		finddate1(B[j].date, d2);
		key = check1(d1, d2);
		if (key==-1)
		{
			merge[++k] = A[i];
			i++;
		}
		else if (key==0)
		{
			merge[++k] = A[i];
			merge[++k] = B[j];
			i++;
			j++;
		}
		else
		{
			merge[++k] = B[j];
			j++;
		}
	}
	if (i == ALen)
	{
		while (j < BLen)
		{
			merge[++k] = B[j];
			j++;
		}
	}
	else
	{
		while (i < ALen)
		{
			merge[++k] = A[i];
			i++;
		}
	}
	return merge;
}
int check1(int d1[], int d2[])
{
	if (d1[2] < d2[2])
		return -1;
	else if (d1[2] > d2[2])
		return 1;
	if (d1[1] < d2[1])
		return -1;
	else if (d1[1] > d2[1])
		return 1;
	if (d1[0] < d2[0])
		return -1;
	else if (d1[0] > d2[0])
		return 1;
	return 0;
}
void finddate1(char *date, int d[])
{
	d[0] = getvalue1(date, 0, 1);
	d[1] = getvalue1(date, 3, 4);
	d[2] = getvalue1(date, 6, 9);
}
int getvalue1(char *date, int x, int y)
{
	int i, num = 0;
	for (i = x; i <= y; i++)
	{
		num = (num * 10) + (date[i] - 48);
	}
	return num;
}