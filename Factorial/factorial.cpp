/* The following program is based on tutorial : https://discuss.codechef.com/questions/7349/computing-factorials-of-a-huge-number-in-cc-a-tutorial
For calculating large factorials which are not possible by using stadard iterations.
*/

#include <iostream>

using namespace std;

int main()
{
	int t;
	int a[200]; //Array having capacity to store 200 digits
	int n, i, j, temp, m, x;
	
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		a[0] = 1; //Initializing array with only 1 digit, the digit 1
		m = 1; //Initializing digit counter
		temp = 0; //Initializing carry variable to 0
		
		for(i = 1; i <= n; i++)
		{
			for(j = 0; j < m; j++)
			{
				x = a[j]*i + temp; //x contains the digit by digit product
				a[j] = x%10;
				temp = x/10;
			}
			while(temp > 0)
			{
				a[m] = temp%10;
				temp = temp/10;
				m++;
			}
		}
		for(i = m-1; i >= 0; i--)
		{
			cout << a[i];
		}
	}
	return 0;
}