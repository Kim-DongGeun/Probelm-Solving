#include <iostream>
#include <string>
using namespace std;

struct Deque
{
	int num;
	Deque* next;
	Deque* pre;
};

int main()
{
	int N, top = -1, Int;
	string input;
	cin >> N;
	cin.ignore();

	Deque* first = new Deque;
	Deque* last = new Deque;
	first->num = 0;
	first->pre = nullptr;
	last->next = nullptr;
	first->next = last;
	last->pre = first;

	for (int i = 0; i < N; i++)
	{
		getline(cin, input);

		if (input.find(' ') != string::npos)
		{
			Int = atoi(input.substr(input.find_first_of(' ') + 1).c_str());
			input = input.substr(0, input.find_first_of(' '));
		}

		if (input == "push_front")
		{
			Deque* New = new Deque;
			New->num = Int;
			New->next = first->next;
			New->pre = first;
			first->next->pre = New;
			first->next = New;
			first->num++;
		}
		else if(input == "push_back")
		{
			Deque* New = new Deque;
			New->num = Int;
			New->next = last;
			New->pre = last->pre;
			last->pre->next = New;
			last->pre = New;
			first->num++;
		}
		else if (input == "pop_front")
		{
			if (first->next == last)
				cout << -1 << "\n";
			else
			{
				cout << first->next->num << "\n";
				first->next = first->next->next;
				first->next->pre = first;
				first->num--;
			}
		}
		else if (input == "pop_back")
		{
			if (first->next == last)
				cout << -1 << "\n";
			else
			{
				cout << last->pre->num << "\n";
				last->pre = last->pre->pre;
				last->pre->next = last;
				first->num--;
			}
		}
		else if (input == "size")
		{
			cout << first->num << "\n";
		}
		else if (input == "empty")
		{
			if (first->next == last)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (input == "front")
		{
			if (first->next == last)
				cout << -1 << "\n";
			else
				cout << first->next->num << "\n";
		}
		else if (input == "back")
		{
			if (first->next == last)
				cout << -1 << "\n";
			else
				cout << last->pre->num << "\n";
		}
	}



	return 0;
}