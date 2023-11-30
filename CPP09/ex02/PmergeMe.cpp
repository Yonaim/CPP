#include "PmergeMe.hpp"
#include <iostream>

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

// _vec, _lis 채우기
// 음수, 소수, 숫자가 아닌 문자열 예외처리
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

void PmergeMe::printVector(const std::vector<int> &v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
        std::cout << v[i] << ", ";
    std::cout << *(v.end() - 1);
    std::cout << '\n';
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
    // sortList();

    if (!std::is_sorted(_vec.begin(), _vec.end())) // C++11
        throw(std::logic_error("sorting vector failed"));
    // if (!std::is_sorted(_lst.begin(), _lst.end())) // C++11
    //     throw(std::logic_error("sorting list failed"));
}

void PmergeMe::printProcessTime(const std::string &c_name)
{
    std::cout << "Time to process a range of " << _vec.size() << " elements with " << c_name << " : "
              << end_time - start_time << "ms" << std::endl;
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
    vMerge(sorted, smaller);
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

void PmergeMe::vMerge(std::vector<int> &main, std::vector<int> &sub)
{
    size_t t, t_p, t_pp;

    t = 0;
    t_p = 1;
    t_pp = 1;
    main.insert(main.begin(), sub[0]);
    while (t < sub.size())
    {
        t = t_p + (2 * t_pp);
        for (size_t i = std::min(t, sub.size()); i > t_p; i--)
        {
            vInsert(main, sub[i - 1]);
        }
        t_pp = t_p;
        t_p = t;
    }
}

void PmergeMe::vMatchOrder(const std::vector<int> &before, const std::vector<int> &after, std::vector<int> &target)
{
    std::vector<int> result;

    for (size_t i = 0; i < after.size(); i++)
    {
        std::vector<int>::const_iterator find_it = std::find(before.begin(), before.end(), after[i]);
        int idx = std::distance(before.begin(), find_it);
        result.push_back(target[idx]);
    }
    if (target.size() > after.size())
        result.push_back(target[target.size() - 1]);
    target = result;
}

/* --------------------------------- LIST ----------------------------------- */

// void PmergeMe::sortList(void)
// {
//     start_time = clock();
//     _vec = vFordJohnson(_vec);
//     end_time = clock();
//     printProcessTime("list");
// }

/* ----------------------------- EXCEPTIONS --------------------------------- */

PmergeMe::InvalidInputException::InvalidInputException(const std::string &arg)
{
    errormsg = "invalid input \'" + arg + "\'";
}

const char *PmergeMe::InvalidInputException::what(void) const throw()
{
    return (errormsg.c_str());
}
