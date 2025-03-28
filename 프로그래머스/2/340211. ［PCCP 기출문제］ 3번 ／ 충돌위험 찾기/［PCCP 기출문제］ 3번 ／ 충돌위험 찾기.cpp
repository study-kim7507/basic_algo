#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

// r값이 먼저 바뀌는 쪽으로 검사를 진행해야함.
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// 로봇들의 현재 위치를 저장.
vector<pair<int, int>> curPos;

// 로봇들의 경로를 저장
vector<queue<pair<int, int>>> routePos;


// 도착한 로봇의 개수 저장 및 도착 여부 저장
bool isAlreadyArrived[101];
int cnt = 0;

// 충돌 횟수 저장.
int answer = 0;

int board[101][101];

// 충돌을 확인
void check()
{
    for (int i = 0; i < 101; i++)
        fill(board[i], board[i] + 101, 0);
    
    for (int i = 0; i < curPos.size(); i++)
    {
        if (isAlreadyArrived[i]) continue;
        board[curPos[i].X][curPos[i].Y]++;
    }
        
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            if (board[i][j] > 1) answer += 1;
}

// 모든 로봇들을 이동 시킴.
void moveNext()
{
    for (int i = 0; i < routePos.size(); i++)
    {
        // 이미 도착하였으면 더 이상 이동시키지 않음.
        if (isAlreadyArrived[i]) continue;
        
        auto curRobotPos = curPos[i];
        auto curRobotRoutePos = routePos[i].front();
        
        // 목적지까지의 거리 
        int dist = abs(curRobotRoutePos.X - curRobotPos.X) + abs(curRobotRoutePos.Y - curRobotPos.Y);
        
        for (int dir = 0; dir < 4; dir++)
        {
            // 이동 후 좌표
            int nx = curRobotPos.X + dx[dir];
            int ny = curRobotPos.Y + dy[dir];
            
            // 이동 후 거리가 늘어났다면 해당 방향으로의 이동은 옳지 못함
            if (abs(curRobotRoutePos.X - nx) + abs(curRobotRoutePos.Y - ny) >= dist) continue;
            
            // 이동 후 거리가 줄어들었다면, 로봇을 이동 시킴
            else
            {
                pair<int, int> newPos = {nx, ny};
                curPos[i] = newPos;
                break;
            }
        }
    }
    
    check();
    
    for (int i = 0; i < routePos.size(); i++)
    {
        if (routePos[i].empty()) continue;
        
        if (curPos[i] == routePos[i].front())
            routePos[i].pop();
        if (routePos[i].empty())
        {
            isAlreadyArrived[i] = true;
            cnt++;
        }
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {

    // 로봇들의 초기 위치 및 경로 위치를 저장.
    for (auto e : routes)
    {
        queue<pair<int, int>> routes;
        curPos.push_back({points[e[0] - 1][0], points[e[0] - 1][1]});
        for (int i = 1; i < e.size(); i++)
            routes.push({points[e[i] - 1][0], points[e[i] - 1][1]});
        routePos.push_back(routes);
    }
    
    check();
    while(cnt < routePos.size())
    {
        moveNext();
    }
    
    return answer;
}