#include <algorithm>
#include <iostream>
#include <vector>

typedef struct s_number
{
    int n;
    std::vector<int> *v;
} t_number;

void print_vector(const std::vector<int> &v, const char *name)
{
    std::cout << name << ": ";
    for (size_t i = 0; i < v.size() - 1; i++)
        std::cout << v[i] << ", ";
    std::cout << *(v.end() - 1);
    std::cout << '\n';
}

// ok
void divide(const std::vector<int> &src, std::vector<int> &larger, std::vector<int> &smaller)
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

// ok
int binary_search(const std::vector<int> &v, int find)
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
    return (start); // 해당 원소가 들어갈 인덱스 위치 반환
}

// ok
void insert(std::vector<int> &v, int put)
{
    std::vector<int>::const_iterator it = v.begin() + binary_search(v, put);
    v.insert(it, put);
}

/*
1, (3, 2), (5, 4) , (11, 10, 9, 8, 7, 6), (21, 20, ... 12)

매 insert마다 이진탐색에 필요한 비교횟수가 가능한 적도록 특정 순서대로 십입.
- 그래서 앞쪽거부터 삽입. 메인 체인에 삽입된 개수가 늘어날 수록 앞쪽 것을 삽입할 때 필요한 비교 횟수가 늘어나니까
- 그러나 그와 동시에 특정 숫자에서는 거슬러 올라가면서(뒤쪽거부터, 거꾸로) 삽입하는데...
    비교군 숫자의 수를 2^n-1개로 유지하면서 안정적으로 삽입하기 위함

t(n) = t(n-1) + 2t(n-2)
n은 n번째 t라는 뜻.
*/
void merge(std::vector<int> &main, std::vector<int> &sub)
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
            insert(main, sub[i - 1]);
		}
        t_pp = t_p;
        t_p = t;
    }
}

// ok
// target 벡터 원소의 순서를 before와 after에 알맞게 변경하기
void match_order(const std::vector<int> &before, const std::vector<int> &after, std::vector<int> &target)
{
    std::vector<int> result;

    for (size_t i = 0; i < after.size(); i++)
    {
        std::vector<int>::const_iterator find_it = std::find(before.begin(), before.end(), after[i]);
        int idx = std::distance(before.begin(), find_it);
        result.push_back(target[idx]);
    }
	if (target.size() > after.size())
	{
		result.push_back(target[target.size() - 1]);
		printf("push odd\n");
	}
    target = result;
}

/*
0. 인자로 들어온 벡터의 원소 개수 체크 (1일시 재귀 종료)
1. 분할
    - 페어로 묶고 페어 내부는 정렬
2. 재귀 호출
    - 메인 체인 정렬
3. 병합
    - 이진탐색 후 삽입해주기
    - 야콥스탈의 수를 따르는 순서로 삽입
*/
std::vector<int> ford_johnson(std::vector<int> src)
{
    print_vector(src, "\nford_johnson called src");
    if (src.size() == 1)
        return (src);
    else if (src.size() == 2)
    {
        if (src[0] > src[1])
        {
            int tmp = src[0];
            src[0] = src[1];
            src[1] = tmp;
        }
        return (src);
    }

    std::vector<int> larger, smaller, sorted;

    divide(src, larger, smaller);
	print_vector(larger, "larger");
	print_vector(smaller, "smaller");
    sorted = ford_johnson(larger);
    // print_vector(sorted, "ford sorted");
    match_order(larger, sorted, smaller);
    // print_vector(smaller, "ford smaller");
	printf("TRY TO MERGE...");
	print_vector(sorted, "sorted");
	print_vector(smaller, "smaller");
    merge(sorted, smaller);
    // print_vector(sorted, "after sorted");
    return (sorted);
}

// 중복 허용 안함
int main()
{
    int arr1[] = {10, 5, 8, 2, 3, 4, 12, 7, 11, 100, -1};

    // std::vector<int> v1, v2;
    // for (size_t i = 0; i < sizeof(arr1)/ sizeof(int); i++)
    // 	v1.push_back(arr1[i]);
    // for (int i = 1; i <= 10; i++)
    // 	v2.push_back(i * 2);

    std::vector<int> src, result;
    for (size_t i = 0; i < sizeof(arr1)/ sizeof(int); i++)
    	src.push_back(arr1[i]);
    result = ford_johnson(src);

	print_vector(result, "\nFINAL RESULT");

    // int before[] = {1, 2, 3, 4};
    // int after[] = {3, 1, 4, 2};
    // int target[] = {5, 6, 7, 8};
    // std::vector<int> before_v, after_v, target_v;
    // for (int i = 0; i < 4; i++)
    // {
    // 	before_v.push_back(before[i]);
    // 	after_v.push_back(after[i]);
    // 	target_v.push_back(target[i]);
    // }
    // match_order(before_v, after_v, target_v);
    // print_vector(target_v, "target");
}
