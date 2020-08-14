#include<iostream>

//int nums[10],

// Given 100 elements, shouldn't anticipate a larger string of brackets, although possible seems unlikely.
char checker[100];

int indexPos;

void push(char value)
{
	/*
	 * Icrement from index 0 to index 1 before adding data, this allows us to check if the array
	 * is empty by checking if the curr index pos is zero, if it is we no that the array is empty.
	 */
	++indexPos;

	checker[indexPos] = value;
}

void pop()
{
	checker[indexPos] = ' ';
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

char top()
{
	return checker[indexPos];
}



int main()
{
	indexPos = 0;
	

	/*push(5);
	push(4);
	push(7);

	pop();
	pop();

	if (!isEmpty())
	{
		std::cout << top() << '\n';
	}*/

	std::cout << "Please enter a string of brackets to assess syntactical correctness:> ";

	std::string check;

	std::cin >> check;


	// Loop over the string of brackets that has been passed and feed that data into a new array.
	for (auto iter = check.begin(); iter != check.end(); ++iter)
	{
		// If we find an opening bracket push it onto the stack.
		if (*iter == '(' || *iter == '{' || *iter == '[')
		{
			push(*iter);

			std::cout << checker[indexPos] << ", ";
		}
		else if (*iter == ')' || *iter == '}' || *iter == ']')		// Other wise check the closing brackets
		{
			// If the array is empty then we have an expression that begins with a closing bracket and so therfore is NOT syntactically correct.
			if (isEmpty())
			{
				return false;
			}
			else
			{
				if (top() == '(' && *iter == ')')
				{
					pop();

					std::cout << checker[indexPos] << ", ";
				}
				else if (top() == '{' && *iter == '}')
				{
					pop();

					std::cout << checker[indexPos] << ", ";
				}
				else if (top() == '[' && *iter == ']')
				{
					pop();

					std::cout << checker[indexPos] << ", ";
				}
			}		
		}
	}

	if (isEmpty())
	{
		std::cout << "The expression was syntactically correct!\n";
	}
	else
	{
		std::cout << "The expression was not syntactically correct!\n";
	}

	std::cout << "\n##################################################################\n";

	// Double check the final array is empty.
	for (int i = 0; i < 100; ++i)
	{
		std::cout << checker[i] << ", ";
	}

	return 0;
}