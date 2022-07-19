/*
musaab imran
20i-1794
section- A
*/

#include <iostream>
using namespace std;


// using template
template <class T>
class stack
{
private:

	// private member
	T array[100];
	int top;

public:

	// constructor
	stack()
	{
		top = -1;
		//array[100] = {};
	}

	// if stack is empty
	bool isEmpty()
	{
		return (top == -1);
	}

	// if full
	bool isFull()
	{
		return (top == 100 - 1);
	}

	// push func
	void push(T ch)
	{
		top++;
		array[top] = ch;
	}

	// pop func
	T pop()
	{
		T val;
		if (isEmpty())
		{
			return NULL;
		}


		// if not empty
		else
		{
			val = array[top];
			top--;
			return val;
		}
	}

	// top value
	T topval()
	{
		return array[top];
	
	}

	// if operand or not
	bool operand(char op)
	{
		if (op >= '0' && op <= '9')
		{
			return true;
		}

		else
		{
			return false;
		}
	}
	
	//giving precedence
	int check(char ck)
	{
		switch (ck)
		{
		case '+':
		case '-':
			return 1;

		case '*':
		case '/':
		case '^':
			return 2;

		case '%':
			return 4;

		case '(':
			return 0;

		// if noone break
		default:
			break;
		}

	}

	// checking for precendence
	bool precedence(char oper1, char oper2)
	{
		int p_oper1, p_oper2;

		p_oper1 = check(oper1);
		p_oper2 = check(oper2);

		// equal
		if (p_oper1 == p_oper2)
		{
			return true;
		}

		// greater
		else if (p_oper1>p_oper2)
		{
			return true;
		}

		// less
		else
		{
			return false;
		}

	}

	// conversion of infix to postfix
	string infix_to_postfix(string str)
	{
		// variable declaration
		stack<char> stk;
		char symb;
		string  post;

		
		int num = 0;
		num = str.length();

		// iterate through the string
		for (int i = 0; i < num ; i++)
		{
			
			symb = str[i];

			// if ( push
			if (symb == '(')
			{
				stk.push(symb);
		
			}

			// if ) pop till (
			else if (symb == ')')
			{
				while (!stk.isEmpty() && stk.topval() != '(')
				{
					post += ' ';
					post += stk.pop();
					
				}

				stk.pop();
			}

			// if operand
			else if (operand(symb))
			{
				post += symb;
			}

			// if operator
			else
			{
				while (!stk.isEmpty() && stk.precedence(stk.topval(), symb))
				{
					post += ' ';
					post += stk.pop();
				}

				post += ' ';
				stk.push(symb);
			}

		}

		// left over string print
		while (!stk.isEmpty())
		{
			post += ' ';
			post += stk.pop();
			
		}

		// reutrn string
		return post;
	}
	
	// evaluating the postfix
	void evalution_pos(string convert)
	{
		int len = convert.length();
		double result=0.0, val1=0.0, val2=0.0;
		stack<double> obj;
		double final;


		// full string traversal
		for (int i = 0; i < len ; i++)
		{
			char ch = convert[i];

			// if number
			if (ch >= '0' && ch <= '9')
			{
				result = result * 10 + (ch - '0');
			}
			
			// push when space
			// multidigitl number
			else if (ch == ' ')
			{

				obj.push(result);
				result = 0;

			}

			// add
			else if (ch == '+')
			{
				if (convert[i++] == ' ')
				{
					i++;
				}
				
				val1 = obj.pop();
				val2 = obj.pop();

				final = val2 + val1;
				obj.push(final);
			}

			// subtract
			else if (ch == '-')
			{
				if (convert[i++] == ' ')
				{
					i++;
				}


				val1 = obj.pop();
				val2 = obj.pop();

				final = val2 - val1;
				obj.push(final);
			}

			// multiply
			else if (ch == '*')
			{
				if (convert[i++] == ' ')
				{
					i++;
				}

				val1 = obj.pop();
				val2 = obj.pop();

				final = val2 * val1;
				obj.push(final);
			}


			// divide
			else if (ch == '/')
			{
				if (convert[i++] == ' ')
				{
					i++;
				}

				val1 = obj.pop();
				val2 = obj.pop();

				final = val2 / val1;
				obj.push(final);
			}

			// mod
			else if (ch == '%')
			{
				if (convert[i++] == ' ')
				{
					i++;
				}

				int va1 = obj.pop();
				int va2 = obj.pop();

				final = va2 % va1;
				obj.push(final);
			}

			// power
			else if (ch == '^')
			{
				if (convert[i++] == ' ')
				{
					i++;
				}

				
				val1 = obj.pop();
				val2 = obj.pop();
				double res = val2;
				
				for (double i = val1-1; i > 0.0; i--)
				{
					res = res* val2;
				}

				obj.push(res);
				
			}
		}

		// if only a number is entered and stack is empty
		// the number will be printed
		if (obj.isEmpty())
		{
			cout << endl;
			cout << "\t\t\t\t Answer: " << convert;
		}

		// print the final top of the stack
		else
		{
			cout << endl;
			cout << "\t\t\t\t Answer: " << obj.pop();
		}
	}

	
	// validation 1 
	// bracket check
	bool validation1(string check1)
	{
		stack<char> sv1;
		int count=0;
		char cv1 = '0';
		sv1.push('(');
		check1 += ')';

		// full string traversal
		for (int i = 0; i < check1.length(); i++)
		{
			char c22 = check1[i];

			// if not brackets
			if (c22 == '(' || c22 == ')' || c22 == '[' || c22 == ']' || c22 == '{' || c22 == '}')
			{
				count++;
			}

		}

		// return true
		if (count == 0)
		{
			return true;
		}

		// if brackets
		for (int i = 0; i < check1.length(); i++)
		{

			char c2 = check1[i];

			//if open brackets push
			if (c2 == '(' || c2 == '{' || c2 == '[')
			{
				sv1.push(c2);
				continue;
			}

			// if stack is empty till now false
			if (sv1.isEmpty())
			{
				return false;
			}

			// if ) check the rest two
			if (c2 == ')')
			{
				cv1 = sv1.pop();
				if (cv1 == '{' || cv1 == '[')
				{
					return false;
				}
			}

			// if ] check the rest two
			if (c2 == ']')
			{
				cv1 = sv1.pop();
				if (cv1 == '{' || cv1 == '(')
				{
					return false;
				}

			}

			// if } check the rest two
			if (c2 == '}')
			{
				cv1 = sv1.pop();
				if (cv1 == '(' || cv1 == '[')
				{
					return false;
				}

			}
		}
			
		// return the stack
		// check of empty
		return (sv1.isEmpty());
	}

	// second validation
	// extra/ unwanted characters
	bool validation2(string check2)
	{
		stack<char> sv2;
		for (int i = 0; i < check2.length(); i++)
		{

			char c3 = check2[i];

			// if all of the below then true
			switch (c3)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '(':
			case ')':
			case '[':
			case ']':
			case '{':
			case '}':
			case '*':
			case '-':
			case '/':
			case '+':
			case '%':
			case '^':
			case ' ':
				continue;
			
			// else false
			default:
				return false;
			}


		}

		// final bool return
		return true;
	}

	// third validation
	bool validation3(string check3)
	{
		stack<char> sv3;
		int len3 = check3.length();

		// full string traversal
		for (int i = 0; i < len3; i++)
		{
			char cv3 = check3[i];

			// if any of the operands
			if (cv3 == '+' || cv3 == '-' || cv3 == '/' || cv3 == '*' || cv3 == '^' || cv3 == '%')
			{
				// check the next one
				// to avoid consecutive operands
				i++;
				if (check3[i] == '+' || check3[i] == '-' || check3[i] == '/' || check3[i] == '*' || check3[i] == '^' || check3[i] == '%' || check3[i] == ')')
				{
					return false;
				}
			}

			// check for operand inbetween ) and (
			if (check3[i] == ')')
			{
				i++;
				if (check3[i] == '(')
				{
					return false;
				}
			}
		}

		// check if the last character is an operand
		len3--;
		if (check3[len3] == '+' || check3[len3] == '-' || check3[len3] == '/' || check3[len3] == '*' || check3[len3] == '^' || check3[len3] == '%')
		{
			// return bool false
			return false;
		}
		else
		{
			return true;
		}
	}

	// end of the used function
};
