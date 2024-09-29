// 신장 트리 : 방향성이 없는 그래프의 부분 그래프들 중에서 모든 정점을 포함하는 트리
// 모든 정점을 포함하는 서브 그래프 중 '사이클이 없는'(트리) 그래프
// 트리의 성질에 따라 정점이 V개이면 간선은 V - 1

// 최소 신장 트리 : 신장 트리 중, 간선의 합이 최소인 신장 트리
	// 여러개 일 수 있음

// 크루스칼 알고리즘 -> 유니온 파인드
	// 1. 간선의 크기를 오름차순으로 정렬 후, 제일 낮은 비용의 간선을 선택
	// 2. 현재 선택한 간선이 정점 u, v를 연결하는 간선이라고 할 때, 만약 u와 v가 같은 그룹이라면
	//    아무것도 하지 않고 넘어감, u와 v가 다른 그룹이라면 같은 그룹으로 만들고 현재 선택한 간선을 최소 신장 트리에 추가
	// 3. 최소 신장 트리에 V-1개의 간선을 추가시켰다면 종료, 그렇지 않다면 그 다음으로 비용이 작은 간선을 선택 후 2번 반복