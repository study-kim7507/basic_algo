#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, int> m;

bool solution(vector<string> phone_book) {
    for (int i = 0; i < phone_book.size(); i++)
        m[phone_book[i]]++;
    
    for (int i = 0; i < phone_book.size(); i++)
    {
        string str;
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            str += phone_book[i][j];
            if (m[str] != 0 && str != phone_book[i]) return false;
        }
    }
    return true;
}