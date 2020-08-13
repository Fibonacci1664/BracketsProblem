#include<iostream>

int nums[10], indexPos;

void push(int value)
{
	++indexPos;

	nums[indexPos] = value;
}

void pop()
{
	nums[indexPos] = 0;
	--indexPos;
}

bool isEmpty()
{
	if (indexPos == 0)
	{
		return true;
	}

	return false;
}

int top()
{
	return nums[indexPos];
}

int main()
{
	indexPos = 0;

	push(5);
	push(4);
	push(7);

	pop();
	pop();

	if (!isEmpty())
	{
		std::cout << top() << '\n';
	}

	return 0;
}