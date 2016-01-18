/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
void finddate(char *,int *);
int getvalue(char *, int, int);
int check(int *, int *);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0, givendate[3], currdate[3], key;
	finddate(date, givendate);
	while (i<len)
	{
		finddate(Arr[i].date, currdate);
		key = check(currdate, givendate);
		if (key == 1)
		{
			break;
		}
		i++;
	}
	if (i == len)
	{
		return 0;
	}
	while (i<len)
	{
		i++;
		finddate(Arr[i].date, currdate);
		key = check(currdate, givendate);
		if (key == 0)
		{
			break;
		}
	}
	return len - i;
}
int check(int d1[], int d2[])
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (d1[i] != d2[i])
		{
			return 0;
		}
	}
	return 1;
}
void finddate(char *date, int d[])
{
	d[0] = getvalue(date, 0, 1);
	d[1] = getvalue(date, 3, 4);
	d[2] = getvalue(date, 6, 9);
}
int getvalue(char *date, int x, int y)
{
	int i, num = 0;
	for (i = x; i <= y; i++)
	{
		num = (num * 10) + (date[i] - 48);
	}
	return num;
}
