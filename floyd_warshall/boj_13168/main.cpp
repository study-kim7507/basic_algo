#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <limits>
using namespace std;

int n, r, m, k;
map<string, int> cities;			// 도시 번호로 매핑하기 위함
vector<int> tourCities;				// 여행하기로 한 도시들 번호 저장
double ticketCost[101][101];				// 티켓을 구매했을 때 비용
double cost[101][101];					// 티켓을 구매하지 않았을 때의 비용
const long long INF = numeric_limits<long long>::max() / 3;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> r;					// 도시의 개수, 내일로 티켓의 비용
	for (int i = 0; i < n; i++)
	{
		fill(ticketCost[i], ticketCost[i] + n, INF);
		fill(cost[i], cost[i] + n, INF);
		ticketCost[i][i] = 0;
		cost[i][i] = 0;
	}


	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		cities[name] = i;			// 입력받은 순서대로 도시를 숫자로 매핑 (0 ~ n)
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;
		tourCities.push_back(cities[name]);		// 여행하기로 한 도시들을 번호로 저장
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		string type, u, v;
		double c;
		cin >> type >> u >> v >> c;

		// 티켓을 구매했을 경우 무료
		if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun")
		{
			ticketCost[cities[u]][cities[v]] = min(ticketCost[cities[u]][cities[v]], 0.0);
			ticketCost[cities[v]][cities[u]] = min(ticketCost[cities[v]][cities[u]], 0.0);
		}


		// 티켓을 구매했을 경우 절반의 가격
		else if (type == "S-Train" || type == "V-Train")
		{
			ticketCost[cities[u]][cities[v]] = min(ticketCost[cities[u]][cities[v]], c * 0.5);
			ticketCost[cities[v]][cities[u]] = min(ticketCost[cities[v]][cities[u]], c * 0.5);
		}


		// 티켓을 구매했어도 할인을 받지 못함
		else
		{
			ticketCost[cities[u]][cities[v]] = min(ticketCost[cities[u]][cities[v]], c);
			ticketCost[cities[v]][cities[u]] = min(ticketCost[cities[v]][cities[u]], c);
		}


		cost[cities[u]][cities[v]] = min(cost[cities[u]][cities[v]], c);						// 티켓을 구매하지 않았을 경우
		cost[cities[v]][cities[u]] = min(cost[cities[v]][cities[u]], c);
	}

	// floyd-washall
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ticketCost[i][j] = min(ticketCost[i][j], ticketCost[i][k] + ticketCost[k][j]);
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	double ticketSum = r;				// 티켓을 구매했을 때 총 비용
	double sum = 0;						// 티켓을 구매하지 않았을 때 총 비용

	int st = tourCities[0];
	for (int i = 1; i < tourCities.size(); i++)
	{
		ticketSum += ticketCost[st][tourCities[i]];
		sum += cost[st][tourCities[i]];
		st = tourCities[i];
	}


	if (ticketSum < sum) cout << "Yes" << "\n";
	else cout << "No" << "\n";

	return 0;
}


