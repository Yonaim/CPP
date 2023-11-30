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
    void printProcessTime(const std::string &c_name);

    // vector
    void sortVector(void);
    bool isVectorAscendingSorted(void) const;
    void printVector(const std::vector<int> &v);

    std::vector<int> vFordJohnson(std::vector<int> src);
    void vDivide(const std::vector<int> &src, std::vector<int> &larger, std::vector<int> &smaller);
    int vBinarySearch(const std::vector<int> &v, int find);
    void vInsert(std::vector<int> &v, int put);
    void vMergeInsertion(std::vector<int> &sorted, std::vector<int> &sub);
    void vMatchOrder(const std::vector<int> &before, const std::vector<int> &after, std::vector<int> &target);

    // list
    void sortList(void);
    bool isListAscendingSorted(void) const;
    int getListElem(const std::list<int> &l, int idx) const;

    std::list<int> lFordJohnson(std::list<int> src);
    void lDivide(const std::list<int> &src, std::list<int> &larger, std::list<int> &smaller);
    int lBinarySearch(const std::list<int> &v, int find);
    void lInsert(std::list<int> &v, int put);
    void lMergeInsertion(std::list<int> &sorted, std::list<int> &sub);
    void lMatchOrder(const std::list<int> &before, const std::list<int> &after, std::list<int> &target);


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
