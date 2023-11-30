#include <vector>
#include <iostream>
#include <algorithm>

void print_vector(const std::vector<int> &v)
{
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
	int check;

	if (!std::is_sorted(v.begin(), v.end())) // C++11
	{
		print_vector(v);
		throw (std::logic_error("try to binary search with unsorted data"));
	}

	while (start <= end)
	{
		check = (start + end + 1) / 2;
		if (find == v[check])
			break ;
		else if (find < v[check])
			end = check - 1;
		else
			start = check + 1;
	}
	return (check);
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
	main.push_back(sub[0]);
	while (t < sub.size())
	{
		// printf("t: %lu\n", t);
		t = t_p + (2 * t_pp);
		for (size_t i = t; i > t_p; i--)
			insert(main, sub[i - 1]);
		t_pp = t_p;
		t_p = t;
	}
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
void ford_johnson(std::vector<int> &v)
{
	printf("current vector: ");
	print_vector(v);
	if (v.size() == 1)
		return ;
	else if (v.size() == 2)
	{
		int e1 = v[0];
		int e2 = v[1];
		v[0] = std::min(e1, e2);
		v[1] = std::max(e1, e2);
		return ;
	}

	std::vector<int> larger;
	std::vector<int> smaller;
	
	divide(v, larger, smaller);
	ford_johnson(larger); // 재귀
	merge(larger, smaller);
	v = larger;
}

// 중복 허용 안함
int main()
{
	std::vector<int> v1, v2;
	int arr1[] = {10, 5, 8, 2, 3, 4, 12, 7, 11};
	for (size_t i = 0; i < sizeof(arr1)/ sizeof(int); i++)
		v1.push_back(arr1[i]);
	for (int i = 1; i <= 10; i++)
		v2.push_back(i * 2);

	std::vector<int> src, larger, smaller;
	for (size_t i = 0; i < sizeof(arr1)/ sizeof(int); i++)
		src.push_back(arr1[i]);
	print_vector(src);
	ford_johnson(src);
	print_vector(src);


}