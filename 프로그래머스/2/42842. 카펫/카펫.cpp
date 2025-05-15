#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int area = brown + yellow;
    
    for (int i = 1; i <= area; i++)
    {
        if (area % i != 0) continue;
        
        int width = area / i;
        int height = area / width;
        
        if (((area - (width * 2) - (height * 2) + 4)) == yellow)
        {
            return vector<int>{width, height};
        }
    }
}