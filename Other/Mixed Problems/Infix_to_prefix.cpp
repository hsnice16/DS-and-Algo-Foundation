// Infix to prefix conversion for one digit numbers

// assuming expression will contain only this ( ) bracket and expression is correct
// , means it doesn't match the missing things

#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// function for giving precedence
int get_prec(char ch)
{
    // values are assumed for calculation
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 1;
}

// function to check that passed char is an operend or not
bool check_oprnd(char ch)
{
    return ((ch - '0' >= 0) && (ch - '0' <= 9));
}

// function to convert infix expression into prefix expression
string infx_to_prefx(string infix_exp)
{

    string rvrs_prefx = ""; // reverse of prefix expression
    stack<char> stk;        // stack for operators

    for (int i = infix_exp.length() - 1; i >= 0; i--) // loop from right to left of infix expression
    {
        if (check_oprnd(infix_exp[i]))
        {
            rvrs_prefx += infix_exp[i];
        }
        else if (infix_exp[i] == ')')
        {
            stk.push(infix_exp[i]);
        }
        else if (infix_exp[i] == '(')
        {
            char pop_val = stk.top();
            while (pop_val != ')')
            {
                rvrs_prefx += pop_val;
                stk.pop();
                pop_val = stk.top();
            }
            stk.pop();
        }
        else
        {
            if (stk.empty())
            {
                stk.push(infix_exp[i]);
            }
            else
            {
                char pop_val = stk.top();
                if (pop_val == '^' && infix_exp[i] == '^') // '^' has right associativity
                {
                    rvrs_prefx += pop_val;
                }
                else if (pop_val == ')' || get_prec(pop_val) == get_prec(infix_exp[i]))
                {
                    stk.push(infix_exp[i]);
                }
                else if (get_prec(pop_val) < get_prec(infix_exp[i]))
                {
                    stk.push(infix_exp[i]);
                }
                else if (get_prec(pop_val) > get_prec(infix_exp[i]))
                {
                    char pop_val = stk.top();
                    while ((!stk.empty() && get_prec(pop_val) > get_prec(infix_exp[i])) || pop_val == ')')
                    {
                        rvrs_prefx += pop_val;
                        stk.pop();
                        if(!stk.empty())
                            pop_val = stk.top();
                    }
                    stk.push(infix_exp[i]);
                }
            }
        }
    }

    while (!stk.empty())
    {
        rvrs_prefx += stk.top();
        stk.pop();
    }

    // get prefix expression by reversing the rvrs_prefix
    reverse(rvrs_prefx.begin(), rvrs_prefx.end());

    return rvrs_prefx;
}

int main()
{
    string infix_exp; // infix expression

    cout << "\nenter your expression (without any space): ";
    cin >> infix_exp;

    string prefix_exp;                     // prefix expression
    prefix_exp = infx_to_prefx(infix_exp); // infx_to_prefx() function call

    cout << "\nprefix expression for entered infix : " << prefix_exp;

    return 0;
}