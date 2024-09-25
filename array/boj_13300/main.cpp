#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 1학년부터 6학년까지 남,녀 구분하기 위한 2차원 배열
	// 여학생인 경우 0, 남학생인 경우 1
	int student[7][2] = { 0 };

	// 학생의 수
	int n;
	cin >> n;

	// 한 방에 배정할 수 있는 최대 인원 수
	int k;
	cin >> k;

	for (int i = 0; i < n; i++)
	{
		int gender;
		int grade;
		cin >> gender >> grade;
		student[grade][gender]++;
	}

	int roomCount = 0;

	// 1학년부터 6학년까지 순회, 각 학년마다 필요한 방의 개수를 카운트
	for (int i = 1; i <= 6; i++)
	{	
		// 성별 순회
		for (int j = 0; j <= 1; j++)
		{
			student[i][j] % k == 0 ? roomCount += (student[i][j] / k) : roomCount += ((student[i][j] / k) + 1);
		}
	}

	cout << roomCount << "\n";
	return 0;
}