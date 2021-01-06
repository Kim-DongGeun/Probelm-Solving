/*
	idea : 배열로 표현하면 복잡하다 큐를 이용하자
*/
#include <iostream>
using namespace std;

int heap[100001] = { 0 };

int main()
{
	int n, input;
	int size = 0, root = 1;
	scanf("%d", &n);

	while (n--)
	{
		scanf("%d", &input);
		if (!input) {
			if (size == 0) {
				printf("0\n");
				continue;
			}
			printf("%d\n", heap[root]);

			int last = heap[size--];
			int cur = root;
			int child = 2;
			while (child <= size)
			{
				if (child < size && heap[child] < heap[child + 1]) //left < right
					child++;
				if (heap[child] <= last) break;

				heap[cur] = heap[child];
				cur = child;
				child *= 2;
			}
			heap[cur] = last;
		}
		else {
			int cur = ++size;

			while (cur != 1 && heap[cur/2] < input) //add
			{
				heap[cur] = heap[cur / 2];
				cur /= 2;
			}
			heap[cur] = input;
		}
	}
	return 0;
}