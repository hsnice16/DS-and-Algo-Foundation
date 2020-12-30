/*Given some lines on the x coordinate on a paper, with some end points A , B. You have a leaky marker. Whenever you keep the marker on a coordinate , all the lines passing through the coordinate gets colored. 

What is the minimum number of times you need to keep the marker on the coordinates such that all the lines get colored?

You may have lines on the same coordinate.

Input Format
First line contains T, no of testcases.

First line of each test case has N, size of array.

Second line of each test case has N integers.

Output Format
For each testcase print a integer the answer to the question.

Constraints
1<=T<=10

1<=N<=1e5

0<=A,B<=1e9

SAMPLE INPUT 
2
3
0 5
7 10
4 8
2
3 6
1 4
SAMPLE OUTPUT 
2
1*/

#include <iostream>
using namespace std;

void swap(int arr[][2], int i, int j)
{
	for(int k=0; k<2; k++)
	{
		int temp = arr[i][k];
		arr[i][k] = arr[j][k];
		arr[j][k] = temp;
	}
}

void sort_2d(int arr[][2], int size)
{
	for(int i=0; i<size-1; i++)
	{
		if(arr[i][0] > arr[i+1][0])
		{
			swap(arr, i, i+1);
		}
	}
}

void count_color(int arr[][2], int size)
{
	sort_2d(arr, size);
	int count = 1; 
	int max = arr[0][1];

	for(int i=1; i<size; i++)
	{
		if (arr[i][0] > max)
		{
			count++;
			max = arr[i][1];
		}
	}	
	cout << count;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		int arr[n][2];

		for(int i = 0; i<n; i++)
		{
			cin >> arr[i][0] >> arr[i][1] ;
		}

		count_color(arr, n);
		cout << endl;
	}
	return 0;
}