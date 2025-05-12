#include <string>
#include <vector>
#include <map>
using namespace std;


bool solution(vector<string> phone_book) {
    map<string, int> m;
    for (auto& e : phone_book)
        m[e]++;
    
    for (auto& e : phone_book)
    {
        string temp = "";
        for (int i = 0; i < e.size() - 1; i++)
        {
            temp += e[i];
            if (m[temp] != 0) return false;
        }
    }
    
    return true;
}