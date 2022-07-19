/*
musaab imran
20i-1794
section- A
*/

// include stack.cpp
#include "stack.cpp"


// driver function
int main()
{
	// stack object
	stack<char> s;

	// variable declaration
	string infix, postfix_exp, rev_infix, prefix_exp, rev_prefix_exp;
	int choice;

// main menu for input
menu2:
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
	cout << "\t\t\t\t | ::WELCOME TO POSTIX AND PREFIX CONVERTER:: |" << endl;
	cout << "\t\t\t\t | 1. Enter 1 to INPUT:                       |" << endl;
	cout << "\t\t\t\t | 2. Enter 2 to CONVERT INFIX to POSTFIX:    |" << endl;
	cout << "\t\t\t\t | 3. Enter 3 to CONVERT INFIX to PREFIX:     |" << endl;
	cout << "\t\t\t\t | 4. Enter 4 to EVALUATE POSTFIX:            |" << endl;
	cout << "\t\t\t\t | 5. Enter 5 to EXIT:                        |" << endl;
	cout << "\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;

	cout << "\t\t\t\t ENTER: ";
	cin >> choice;
	cout << endl;
	
	// to deal with diff cases
	switch (choice)
	{

	// take input from the user
	case 1:

	menu1:
		cout << "\n\n\t\t\t\t\t\t :::INPUT::: " << endl;
		cout << endl;

		
		cout << "\t\t\t\t Enter INFIX expression: ";
		cin >> infix;


		cout << "\n\t\t\t\t The INFIX expression that you entered: ";
		cout << infix;


		// checking all three validations
		//1. brackets
		//2. characters
		//3.operators

		cout << "\n\n\t\t\t\t\t\t:::VALIDATION::: " << endl;
		cout << endl;
		// check 1
		if (s.validation1(infix))
		{
			cout << "\t\t\t\t 1. VALID BRACKETS in the expression. " << endl;

			
			// check 2
			if (s.validation2(infix))
			{
				cout << "\t\t\t\t 2. VALID CHARACTER in the expression. " << endl;

				// check 3
				if (s.validation3(infix))
				{
					cout << "\t\t\t\t 3. VALID POSITION of operators in the expression. " << endl;
				}

				// wrong operator
				else
				{
					cout << endl;
					cout << "\t\t\t\t INVALID/MISSING OPERATOR!!! " << endl;
					cout << "\n\t\t\t\t ENTER again!!! " << endl;
					goto menu1;
				}
			}

			// wrong characters
			else 
			{
				cout << endl;
				cout << "\t\t\t\t INVALID CHARACTERS!!! " << endl;
				cout << "\n\t\t\t\t ENTER again!! " << endl;
				goto menu1;
			}
		}

		// wrong brackets
		else
		{
			cout << endl;
			cout << "\t\t\t\t INVALID BRACKETS!!! " << endl;
			cout << "\n\t\t\t\t ENTER again!!! " << endl;
			goto menu1;
		}

		// coverting {,[ to ) and },] to )
		// making it easier to solve
		for (int i = 0; i < infix.length(); i++)
		{
			char c1 = infix[i];

			if (c1 == '[' || c1 == '{')
			{
				infix[i] = '(';
			}

			else if (c1 == ']' || c1 == '}')
			{
				infix[i] = ')';
			}

		}

		// going to main menu
		goto menu2;
		break;

	// case to covert infix to postfix
	case 2:
		cout << "\n\n\t\t\t\t\t\t :::POSTFIX::: " << endl;
		cout << endl;
		// function call to print postfix
		postfix_exp = s.infix_to_postfix(infix);

		cout << endl;
		cout << "\t\t\t\t POSTFIX expression: ";
		cout << postfix_exp;
		cout << endl;

		// going to main menu
		goto menu2;
		break;

	// coversion to prefix
	case 3:
		cout << "\n\n\t\t\t\t\t\t :::PREFIX::: " << endl;
		cout << endl;
		rev_infix = " ";
		// reversing infix
		for (int i = infix.length() - 1; i >= 0; i--)
		{
			rev_infix += infix[i];
		}

		// setting the brackets after reversing
		for (int i = 0; i < rev_infix.length(); i++)
		{
			if (rev_infix[i] == '(')
			{
				rev_infix[i] = ')';
			}

			else if (rev_infix[i] == ')')
			{
				rev_infix[i] = '(';
			}
		}

		// reversed infix
		cout << endl;
		cout << "\t\t\t\t Reversed INFIX expression: " << rev_infix;

		// function call to print prefix
		rev_prefix_exp = s.infix_to_postfix(rev_infix);

		prefix_exp = " ";
		for (int i = rev_prefix_exp.length() - 1; i >= 0; i--)
		{
			prefix_exp += rev_prefix_exp[i];
		}

		// prefix
		cout << endl;
		cout << "\t\t\t\t PREFIX expression: " << prefix_exp;
		cout << endl;

		// going to main menu
		goto menu2;
		break;

	// evaluation of postfix expression
	case 4:
		cout << "\n\n\t\t\t\t\t\t :::EVALUATION::: " << endl;
		cout << endl;
		// infix exp
		cout << "\t\t\t\t INFIX expression: ";
		cout << infix;
		cout << endl;

		// function call to print postfix
		postfix_exp = s.infix_to_postfix(infix);

		// postfix exp
		cout << "\t\t\t\t POSTFIX expression: ";
		cout << postfix_exp;

		// evaluation function call
		s.evalution_pos(postfix_exp);
		cout << endl;

		// going to main menu
		goto menu2;
		break;

	// exit case
	default:
		break;

	}

	// return 
	// exit
	return 0;

}