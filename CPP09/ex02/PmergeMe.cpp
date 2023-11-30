#include "PmergeMe.hpp"
#include <iostream>

// TODO: c++11 주석처리해서 제출하기
PmergeMe::PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &orig)
{
    (void)orig;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &orig)
{
    (void)orig;
    return (*this);
}

PmergeMe::PmergeMe(const char **argv)
{
    int i;
    float arg_f;

    i = 0;
    while (argv[i])
    {
        if (!isNumeric(argv[i]))
            throw(InvalidInputException(argv[i]));
        arg_f = strtof(argv[i], NULL);
        if (arg_f < 0 || truncf(arg_f) != arg_f)
            throw(InvalidInputException(argv[i]));
        _vec.push_back(arg_f);
        _lst.push_back(arg_f);
        i++;
    }
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::sortAndDisplay(void)
{
    std::cout << "Before: ";
    printVector(_vec);
    std::cout << "After: ";
    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());
    printVector(sorted);

    sortVector();
    sortList();

    if (!std::is_sorted(_vec.begin(), _vec.end())) // C++11
        throw(std::logic_error("sorting vector failed"));
    if (!std::is_sorted(_lst.begin(), _lst.end())) // C++11
        throw(std::logic_error("sorting list failed"));
}

/* -------------------------------- COMMON ---------------------------------- */

bool PmergeMe::isNumeric(const std::string &str)
{
    bool point_exist = false;
    bool digit_exist = false;
    int i = 0;

    if (str[0] == '-' || str[0] == '.')
        i++;
    else if (!isdigit(str[0]))
        return (false);

    while (str[i])
    {
        if (str[i] == '.')
        {
            if (point_exist == false)
                point_exist = true;
            else
                return (false);
        }
        else if (!isdigit(str[i]))
            return (false);
        digit_exist = true;
        i++;
    }
    return (digit_exist);
}

void PmergeMe::printProcessTime(const std::string &c_name)
{
    std::cout << "Time to process a range of " << _vec.size() << " elements with " << c_name << " : "
              << end_time - start_time << " ms" << std::endl;
}

/* -------------------------------- VECTOR ---------------------------------- */

void PmergeMe::sortVector(void)
{
    start_time = clock();
    _vec = vFordJohnson(_vec);
    printVector(_vec);
    end_time = clock();
    printProcessTime("vector");
}

void PmergeMe::printVector(const std::vector<int> &v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
        std::cout << v[i] << ", ";
    std::cout << *(v.end() - 1);
    std::cout << '\n';
}

std::vector<int> PmergeMe::vFordJohnson(std::vector<int> src)
{
    if (src.size() == 1)
        return (src);
    else if (src.size() == 2)
    {
        if (src[0] > src[1])
            std::swap(src[0], src[1]);
        return (src);
    }

    std::vector<int> larger, smaller, sorted;

    vDivide(src, larger, smaller);
    sorted = vFordJohnson(larger);
    vMatchOrder(larger, sorted, smaller);
    vMergeInsertion(sorted, smaller);
    return (sorted);
}

void PmergeMe::vDivide(const std::vector<int> &src, std::vector<int> &larger, std::vector<int> &smaller)
{
    std::vector<int>::const_iterator it = src.begin();
    const size_t half = src.size() / 2;

    while (it != src.begin() + half)
    {
        int e1 = *it;
        int e2 = *(it + half);
        larger.push_back(std::max(e1, e2));
        smaller.push_back(std::min(e1, e2));
        it++;
    }
    if (src.size() % 2 == 1)
        smaller.push_back(*(src.end() - 1));
}

int PmergeMe::vBinarySearch(const std::vector<int> &v, int find)
{
    int start = 0;
    int end = v.size();

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (find > v[mid])
            start = mid + 1;
        else
            end = mid;
    }
    return (start);
}

void PmergeMe::vInsert(std::vector<int> &v, int put)
{
    std::vector<int>::const_iterator it = v.begin() + vBinarySearch(v, put);
    v.insert(it, put);
}

/*
내림차순으로 삽입하기 시작할 인덱스 넘버 찾기 (부제: 왜 야콥스탈 수인가?)

이번 삽입이 n회째일 때, sub에서 t(n-1)개 만큼이 sorted에 이미 삽입되었다.

이번 삽입에서 탐색해야하는 원소의 개수
= sorted의 t(n)번째까지의 원소 개수
= t(n-1) * 2 + (t(n) - (t(n - 1) +1))
= 2^n - 1

구현상 편의를 위해 점화식 형태로 바꾼다. t(n-2)를 포함해 식을 정리하면 된다.
=> t(n) = t(n-1) + 2t(n-2)
*/
void PmergeMe::vMergeInsertion(std::vector<int> &sorted, std::vector<int> &sub)
{
    size_t t, t_p, t_pp;

    t = 0;
    t_p = 1;
    t_pp = 1;
    sorted.insert(sorted.begin(), sub[0]);
    while (t < sub.size())
    {
        t = t_p + (2 * t_pp);
        for (size_t i = std::min(t, sub.size()); i > t_p; i--)
        {
            vInsert(sorted, sub[i - 1]);
        }
        t_pp = t_p;
        t_p = t;
    }
}

// 바뀐 원소의 순서에 맞춰 target 내부 원소의 순서를 조정
void PmergeMe::vMatchOrder(const std::vector<int> &before, const std::vector<int> &after, std::vector<int> &target)
{
    std::vector<int> result;

    for (size_t i = 0; i < after.size(); i++)
    {
        std::vector<int>::const_iterator find_it = std::find(before.begin(), before.end(), after[i]);
        if (find_it == before.end())
            throw(std::logic_error("cannot match"));
        int idx = std::distance(before.begin(), find_it);
        result.push_back(target[idx]);
    }
    if (target.size() > after.size())
        result.push_back(target[target.size() - 1]);
    target = result;
}

/* --------------------------------- LIST ----------------------------------- */

void PmergeMe::sortList(void)
{
    start_time = clock();
    _lst = lFordJohnson(_lst);
    end_time = clock();
    printProcessTime("list");
}

int PmergeMe::getListElem(const std::list<int> &l, int idx)
{
    std::list<int>::const_iterator it = l.begin();
    std::advance(it, idx);
    return (*it);
}

std::list<int> PmergeMe::lFordJohnson(std::list<int> src)
{
    if (src.size() == 1)
        return (src);
    else if (src.size() == 2)
    {
        if (src.front() > src.back())
            std::swap(src.front(), src.back());
        return (src);
    }

    std::list<int> larger, smaller, sorted;

    lDivide(src, larger, smaller);
    sorted = lFordJohnson(larger);
    lMatchOrder(larger, sorted, smaller);
    lMergeInsertion(sorted, smaller);
    return (sorted);
}

void PmergeMe::lDivide(const std::list<int> &src, std::list<int> &larger, std::list<int> &smaller)
{
    const size_t half = src.size() / 2;
    std::list<int>::const_iterator it_first = src.begin();
    std::list<int>::const_iterator it_second = src.begin();
    std::advance(it_second, half);

    for (size_t i = 0; i < half; i++)
    {
        int e1 = *it_first;
        int e2 = *it_second;
        larger.push_back(std::max(e1, e2));
        smaller.push_back(std::min(e1, e2));
        it_first++;
        it_second++;
    }
    if (src.size() % 2 == 1)
        smaller.push_back(src.back());
}

int PmergeMe::lBinarySearch(const std::list<int> &l, int find)
{
    int start = 0;
    int end = l.size();

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (find > getListElem(l, mid))
            start = mid + 1;
        else
            end = mid;
    }
    return (start);
}

void PmergeMe::lInsert(std::list<int> &l, int put)
{
    std::list<int>::const_iterator it = l.begin();
    std::advance(it, lBinarySearch(l, put));
    l.insert(it, put);
}

// TODO: 리스트의 특징 활용해 최적화 가능
void PmergeMe::lMergeInsertion(std::list<int> &sorted, std::list<int> &sub)
{
    size_t t, t_p, t_pp;

    t = 0;
    t_p = 1;
    t_pp = 1;
    sorted.insert(sorted.begin(), sub.front());
    while (t < sub.size())
    {
        t = t_p + (2 * t_pp);
        for (size_t i = std::min(t, sub.size()); i > t_p; i--)
        {
            lInsert(sorted, getListElem(sub, i - 1));
        }
        t_pp = t_p;
        t_p = t;
    }
}

void PmergeMe::lMatchOrder(const std::list<int> &before, const std::list<int> &after, std::list<int> &target)
{
    std::list<int> result;

    for (size_t i = 0; i < after.size(); i++)
    {
        std::list<int>::const_iterator find_it = std::find(before.begin(), before.end(), getListElem(after, i));
        if (find_it == before.end())
            throw(std::logic_error("cannot match"));
        int idx = std::distance(before.begin(), find_it);
        result.push_back(getListElem(target, idx));
    }
    if (target.size() > after.size())
        result.push_back(target.back());
    target = result;
}

/* ----------------------------- EXCEPTIONS --------------------------------- */

PmergeMe::InvalidInputException::InvalidInputException(const std::string &arg)
{
    errormsg = "invalid input \'" + arg + "\'";
}

const char *PmergeMe::InvalidInputException::what(void) const throw()
{
    return (errormsg.c_str());
}
