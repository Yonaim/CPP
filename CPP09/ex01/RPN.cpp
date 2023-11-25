#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

/*
ex) "8 9 * 9 - 9 - 9 - 4 - 1 +"
1. split
2. push
    - 숫자인 경우에는 그냥 푸쉬
    - 연산자인 경우에는 두 개 꺼내서 연산 마친 후 다시 푸쉬
3. 남아있는 토큰 없는지 확인 후 출력, 마무리
*/
RPN::RPN(std::string exp)
{
    skipSpaces(exp);
    std::stringstream ss(exp);
    std::string token;

    while (ss >> token)
	{
        std::cout << "Expression: \"" << exp << "\"" << std::endl;
        std::cout << "Token: \'" << token << "\'" << std::endl;

        exp = exp.substr(1);
        skipSpaces(exp);

        ss.clear();
        ss.str(exp);
        this->push(token);
		std::cout << "----------------------------------" << std::endl;
    }
}

RPN &RPN::operator=(const RPN &orig)
{
    if (this != &orig)
        _stack = orig._stack;
    return (*this);
}

RPN::~RPN()
{
}

void RPN::skipSpaces(std::string &str)
{
    size_t start = str.find_first_not_of(" ");
    if (start != std::string::npos)
        str = str.substr(start);
}

void RPN::push(const std::string &str)
{
    static const std::string operators = "+-/*";

    if (str.length() != 1)
        throw(UnexpectedTokenException(str));
    t_token token;
    if (operators.find(str) != std::string::npos)
    {
        token.type = TOKEN_OPERATOR;
        token.value = str[0];
    }
    else if (isdigit(str[0]))
    {
        token.type = TOKEN_NUMBER;
        token.value = str[0] - '0';
    }
    else
        throw(UnexpectedTokenException(str));

    if (token.type == TOKEN_OPERATOR)
    {
        const int opd_2 = this->pop_number();
        const int opd_1 = this->pop_number();
        int result = operate_basic4(token.value, opd_1, opd_2);
		std::cout << '\n' << opd_1 << ' ' << static_cast<char>(token.value) << ' ' << opd_2 << " = " << result << ", ";
		token.type = TOKEN_NUMBER;
		token.value = result;
    }
	std::cout << "pushed " << token.value << "...\n\n";
    _stack.push(token);
	std::cout << "After push: \n\n";
	print_stack();
}

int RPN::pop_number(void)
{
    if (_stack.empty())
        throw(InvalidExpressionException());

    // pop되어 나온 것은 무조건 숫자여야함 (오퍼레이터면 x)
    // 처음에 push할때 숫자 혹은 오퍼레이터 리터럴만 push하게 되어있으므로 오퍼레이터 여부만 체크하면 됨
    t_token popped = _stack.top();
    _stack.pop();
    if (popped.type != TOKEN_NUMBER)
        throw(InvalidExpressionException());
    return (popped.value);
}

int RPN::result(void)
{
    if (_stack.size() != 1)
        throw(UnclosedExpressionException());
    t_token last = _stack.top();
    if (last.type == TOKEN_OPERATOR)
        throw(std::logic_error("does not make sence"));
    return (last.value);
}

int RPN::operate_basic4(int op, int opd_1, int opd_2)
{
    switch (op)
    {
    case '+':
        return (opd_1 + opd_2);
    case '-':
        return (opd_1 - opd_2);
    case '/':
        return (opd_1 / opd_2);
    case '*':
        return (opd_1 * opd_2);
    default:
        break;
    }
    throw(std::logic_error("does not make sence"));
}

void RPN::print_stack(void)
{
	std::stack<t_token> stack = _stack;
    while (!stack.empty())
    {
        t_token popped = stack.top();
		stack.pop();
		std::cout << "\t|" << std::setw(5) << std::internal << popped.value \
        << std::setw(0) << "|" << '\n';
    }
	std::cout << "\t ----- " << '\n';
}

/* ----------------------------- EXCEPTIONS --------------------------------- */

RPN::UnexpectedTokenException::UnexpectedTokenException(const std::string &token)
{
    errormsg = "unexpected token \'" + token + "\'"; 
}

const char *RPN::UnexpectedTokenException::what(void) const throw()
{
    return (errormsg.c_str());
}

const char *RPN::InvalidExpressionException::what() const throw()
{
    return ("invalid expression");
}

const char *RPN::UnclosedExpressionException::what() const throw()
{
    return ("unclosed expression");
}
