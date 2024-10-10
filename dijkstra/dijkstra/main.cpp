// 플로이드 알고리즘
// '모든 정점 쌍' 사이의 최단거리를 구하는 알고리즘
// 음수인 간선은 문제가 되지 않지만, 음수인 사이클이 있을 경우 불가능

// 다익스트라 알고리즘
// '하나의 시작점'으로부터 다른 모든 정점까지의 최단 거리를 구하는 알고리즘
// 음수인 간선이 있는 경우 아예 사용 불가능

// 우선 순위 큐를 이용
// 1. 우선순위 큐에 (0, 시작점)을 추가
// 2. 우선순위 큐에서 거리가 가장 작은 원소를 선택, 해당 거리가 최단 거리 테이블에 있는 값과 다를 경우 넘어감
// 3. 원소가 가리키는 정점을 v라고 할 때, v와 이웃한 정점들에 대해 최단 거리 테이블 값보다 v를 거쳐가는 것이
// 더 작은 값을 가질 경우 최단 거리 테이블의 값을 갱신하고 우선 순위 큐에 (거리, 이웃한 정점의 번호)를 추가
// 우선순위 큐가 빌 때 까지 2, 3번 과정을 반복
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
