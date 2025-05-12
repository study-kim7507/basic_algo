#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    multiset<string> comp;
    for (auto& e : participant)
        comp.insert(e);
    
    for (auto& e : completion)
    {
        auto it = comp.find(e);
        if (it != comp.end()) comp.erase(it);
    }
    
    for (auto& e : comp)
    {
        return e;
    }
}