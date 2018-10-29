#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Solution {
public:
    #define _MIN(x,y,z) ( (x < y) ? ( (x < z) ? x:z) : ( (y < z) ? y:z))

    int minDistance(string word1, string word2) {
        int word1_size = word1.size() + 1;
        int word2_size = word2.size() + 1;
        
        int dp_maze[word1_size][word2_size];
        
        for(int i = 0;i < word1_size; i++)
            dp_maze[i][0] = i;
        
        for(int j = 0;j < word2_size; j++)
            dp_maze[0][j] = j;
        
        for(int i = 1; i < word1_size; i++)
            for(int j = 1; j < word2_size; j++)
            {
                if( word1[i-1] == word2[j-1] )
                    dp_maze[i][j] = dp_maze[i-1][j-1];
                else
                    dp_maze[i][j] = 
                        _MIN(dp_maze[i-1][j]+1, dp_maze[i][j-1]+1, dp_maze[i-1][j-1]+1);
            }

        return dp_maze[word1_size-1][word2_size-1];
    }
};

int main()
{
  Solution s;
}
