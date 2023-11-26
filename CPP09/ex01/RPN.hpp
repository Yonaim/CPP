#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <stack>
#include <string>

enum token_types
{
    TOKEN_OPERATOR = 0,
    TOKEN_NUMBER,
    TOKEN_NONE,
};

typedef struct s_token
{
    int type;
    int value;
} t_token;

class RPN
{
  private:
    // pair 쓸까 했지만 문제가 더 복잡해지는 것 같으므로 그냥 구조체 사용.
    std::stack<t_token> _stack;

    // for OCF (not use)
    RPN();
    RPN(const RPN &orig);
    RPN &operator=(const RPN &orig);

    void push(const std::string &token);
    int pop_number(void);
    int operate_basic4(int op, int opd_1, int opd_2);
    void skipSpaces(std::string &str);
    void print_stack(void);

  public:
    RPN(std::string exp);
    ~RPN();

    int result(void);

    // exception
    class UnexpectedTokenException;
    class ExtraOperatorException;
    class ExtraNumberException;
};

class RPN::UnexpectedTokenException : public std::exception
{
  private:
    std::string errormsg;

  public:
    UnexpectedTokenException(const std::string &token);
    virtual ~UnexpectedTokenException() throw(){};
    const char *what(void) const throw();
};

class RPN::ExtraOperatorException : public std::exception
{
    const char *what(void) const throw();
};

class RPN::ExtraNumberException : public std::exception
{
    const char *what(void) const throw();
};

#endif
