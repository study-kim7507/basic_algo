#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<int>& citations, int curH)
{
    int count = 0;
    for (const auto& citation : citations)
    {
        if (citation >= curH) count++;
    }
    
    return count >= curH;
}

int solution(vector<int> citations) {    
    vector<int> sortedCitations(citations);
    sort(sortedCitations.begin(), sortedCitations.end());
    
    int answer = 0;
    int st = 0;
    int en = sortedCitations[sortedCitations.size() - 1];
    
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (check(sortedCitations, mid))
        {
            answer = max(answer, mid);
            st = mid + 1; 
        }
        else en = mid - 1;
    }
    return answer;
}