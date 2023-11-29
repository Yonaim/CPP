#include <vector>
#include <iostream>
#include <algorithm>

// 반환형 고민
void divide(std::vector<int> &orig, std::vector<int> &larger, std::vector<int> &smaller)
{
	const size_t half_size = orig.size() / 2;

	// 반을 기준으로 대소 비교해서 작은 것은 smaller에, 더 큰 것은 larger에 넣기
	for (size_t i = 0; i < half_size; i++)
	{
		int e1 = orig[i];
		int e2 = orig[i + half_size];
		larger.push_back(std::max(e1, e2));
		smaller.push_back(std::min(e1, e2));
	}
}

// 인덱스 반환
int binary_search(std::vector<int> v, int find);

void insert(std::vector<int> &main, int put);


/*
1, (3, 2), (5, 4) , (11, 10, 9, 8, 7, 6), (21, 20, ... 12)
*/
std::vector<int> merge(std::vector<int> &main, std::vector<int> &sub)
{
	std::vector<int> merged;

	merged.push_back(sub[0]);
	for (size_t i = 0; i < main.size(); i++)
		merged.push_back(main[i]);
	for (size_t i = 0; i < sub.size() - 1; i++)
	{
		// TODO: 적절한 인덱스 순으로 binary search하여 insert하기
	}
	return (merged);
}

/*
0. 인자로 들어온 벡터의 원소 개수 체크 (1일시 재귀 종료)
1. 분할
	- 페어로 묶고 페어 내부는 정렬
2. 재귀 호출
	- 메인 체인 정렬
3. 병합
	- 이진탐색 후 삽입해주기
	- 야콥스탈의 수에 맞춰줘야하는데... 어떻게 하지?
*/
void ford_johnson(std::vector<int> &v)
{
	if (v.size() == 1)
		return ;
	
	std::vector<int> larger;
	std::vector<int> smaller;
	
	divide(v, larger, smaller);
	ford_johnson(larger); // 재귀
	v = merge(larger, smaller);
}

void print_vector(const std::vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << ", ";
	std::cout << '\n';
}

// 중복 허용 안함
int main()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(5);
	v.push_back(8);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(1);

	print_vector(v);
	ford_johnson(v);
	print_vector(v);
}