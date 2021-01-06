#include <iostream>
using namespace std;

int main()
{
	int N, biggest = -1000001, smallest = 1000001, input;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (input > biggest)
			biggest = input;
		if (input < smallest)
			smallest = input;
	}
	cout << smallest << " " << biggest << "\n";
	
	return 0;
}