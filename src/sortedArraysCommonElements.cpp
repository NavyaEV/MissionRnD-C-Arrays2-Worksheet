/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
void finddate2(char *, int *);
int getvalue2(char *, int, int);
int check2(int *, int *);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j = 0, k = -1, key, d1[3], d2[3];
	struct transaction common[10];
	if ((A == nullptr) || (B==nullptr))
		return NULL;
	while ((i<ALen) && (j<BLen))
	{
		finddate2(A[i].date, d1);
		finddate2(B[j].date, d2);
		key = check2(d1, d2);
		if (key == -1)
		{
			i++;
		}
		else if (key == 0)
		{
			common[++k] = A[i];
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	if (k == -1)
		return NULL;
	return common;
}
int check2(int d1[], int d2[])
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
void finddate2(char *date, int d[])
{
	d[0] = getvalue2(date, 0, 1);
	d[1] = getvalue2(date, 3, 4);
	d[2] = getvalue2(date, 6, 9);
}
int getvalue2(char *date, int x, int y)
{
	int i, num = 0;
	for (i = x; i <= y; i++)
	{
		num = (num * 10) + (date[i] - 48);
	}
	return num;
}