#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <exception>
#include <list>
#include <string>
#include <vector>

class PmergeMe
{
  private:
    typedef void (*sort_f)(void);

    std::vector<int> _vec;
    std::list<int> _lst;
    clock_t start_time;
    clock_t end_time;

    // for OCF (not use)
    PmergeMe();
    PmergeMe(const PmergeMe &orig);
    PmergeMe &operator=(const PmergeMe &orig);

    // common
    bool isNumeric(const std::string &str);
    void printVector(const std::vector<int> &v);
    void printProcessTime(const std::string &c_name);

    // vector
    void sortVector(void);
    std::vector<int> vFordJohnson(std::vector<int> src);
    void vDivide(const std::vector<int> &src, std::vector<int> &larger, std::vector<int> &smaller);
    int vBinarySearch(const std::vector<int> &v, int find);
    void vInsert(std::vector<int> &v, int put);
    void vMergeInsertion(std::vector<int> &main, std::vector<int> &sub);
    void vMatchOrder(const std::vector<int> &before, const std::vector<int> &after, std::vector<int> &target);

    // list
    // void sortList(void);

  public:
    PmergeMe(const char **argv);
    ~PmergeMe();

    void sortAndDisplay();
    class InvalidInputException;
};

class PmergeMe::InvalidInputException : public std::exception
{
  private:
    std::string errormsg;

  public:
    InvalidInputException(const std::string &arg);
    virtual ~InvalidInputException() throw(){};
    const char *what(void) const throw();
};

#endif
