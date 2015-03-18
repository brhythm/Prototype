/**
 Given an absolute path for a file (Unix-style), simplify it.
 
 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"
 */
#include <string>
#include <vector>
#include <deque>
#include <assert.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty())
        {
                return path;//TODO maybe redundant
        }
        deque<string> simplifiedDirs;
        vector<string> dirs= split(path, "/");
        for (string& dir : dirs) {
            if (dir.empty() ||  dir.compare(".") == 0 ) {
                continue;
            }
            else if (dir.compare("..") == 0 )
            {
                if (!simplifiedDirs.empty())
                {
                    simplifiedDirs.pop_back();
                }
            }
            else
            {
                simplifiedDirs.push_back(dir);
            }
        }
        //generate result
        string result = "/";
        for (string& dir : simplifiedDirs) {
            result += dir;
            result += "/";
        }
        if (result.length() > 1 ) {
            size_t len = result.length();
            if (result[len-1] == '/') {
                //remove last /
                result.erase(len-1, 1);
            }
        }
        return result;
    }
    
    vector<string> split(const string& path, const string delimiter)
    {
        vector<string> result;
        assert(path[0] == '/');
        size_t firstDelimiter = 0;
        while ( path.find_first_of(delimiter, firstDelimiter+1) != string::npos)
        {
            size_t nextDelimiter = path.find_first_of(delimiter, firstDelimiter+1);
            result.push_back(path.substr(firstDelimiter+1, nextDelimiter-firstDelimiter-1));
            firstDelimiter = nextDelimiter;
        }
        if (firstDelimiter != path.length()-1) {
            result.push_back(path.substr(firstDelimiter+1));
        }
        return result;
    }
};

int main()
{
    Solution test;
    string input = "";
    string output = test.simplifyPath(input);
    printf("output = %s\n", output.c_str());
}



