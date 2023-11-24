#include "RPN.hpp"
#include <sstream>
#include <iostream>

/*
ex) "8 9 * 9 - 9 - 9 - 4 - 1 +"
1. split
2. push
	- 숫자인 경우에는 그냥 푸쉬
	- 연산자인 경우에는 두 개 꺼내서 연산 마친 후 다시 푸쉬
3. 남아있는 토큰 없는지 확인 후 출력, 마무리
*/
RPN::RPN(const std::string &exp)
{
	std::stringstream ss(exp);
	std::string buf;
	while (std::getline(ss, buf, ' '))
	{
		if (buf == "")
			continue ;
		this->push(buf);
	}
}

RPN::~RPN()
{}

void RPN::push(const std::string &str)
{
	static const std::string operators = "+-/*";
	
	if (str.length() != 1)
		throw(UnexpectedTokenException());
	
	t_token token;
	if (operators.find(str) == std::string::npos)
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
		throw(UnexpectedTokenException());
	
	if (token.type == TOKEN_OPERATOR)
	{
		const int opd_1 = this->pop_number();
		const int opd_2 = this->pop_number();
		int result = operate_basic4(token.value, opd_1, opd_2);
		_stack.push((t_token){TOKEN_NUMBER, result});
	}
	else
		_stack.push(token);
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
		throw(InvalidExpressionException());
	return (last.value);
}

const char *RPN::UnexpectedTokenException::what() const throw()
{
	return ("unexpected token");
}
