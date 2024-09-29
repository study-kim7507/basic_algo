// 유니온 파인드
	// 그래프 알고리즘 '합집합 찾기'
	// 서로소 집합으로 불리기도 함
	// 여러 노드 중 두 노드를 선택하여 같은 그래프에 속해있는 지 확인하는 알고리즘


// 2가지 연산이 존재
	// Find(x) : 원소 x가 속한 부분집합을 찾는다.
		// x가 속한 부분집합의 대표 원소를 반환
	// Union(x, y) : 원소 x가 속한 부분집합과 원소 y가 속한 부분집합의 합집합을 구함


#include <iostream>
using namespace std;

int parent[10001];

int find(int x)
{
	if (parent[x] != x)
		return parent[x] = find(parent[x]);
	return x;
}

void Union(int x, int y)
{
	int a = find(x);
	int b = find(y);

	if (a != b)
	{
		if (a < b)
			parent[b] = a;
		else
			parent[a] = b;
	}
}