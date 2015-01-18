/**
 */
//
//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//For example:
//Given "25525511135",
//
//return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
#include <vector>
#include <string>
using namespace std;

class Solution {
public://TODO what is time complexity??
    vector<string> restoreIpAddresses(string s) {
        vector<string> solution;
        vector<string> path;
       // printf("debug length:%d\n", s.length());
        restoreAddress(0, s, path, solution);
        return solution;
    }
    
    void restoreAddress( const int startIndex, const string& IP, vector<string>& path, vector<string>& solution)
    {
        size_t length = IP.length();
        if (path.size() > 4) {
            return;//invalid parse, no need to continue
        }
        else if (path.size() == 4)
        {
            if (startIndex >= length)
            {//construct solution
                solution.push_back(constructSolution(path));
            }
            //else, invalid parse, ignore, return
        }
        else
        {
            vector<string> restorePath = path;
            int existingDigits = path.size();
            if (isPossible(length-1-startIndex, 4-1-existingDigits)) {
             //try to parse is one digit
                    path.push_back(IP.substr(startIndex,1));
                    restoreAddress(startIndex+1, IP, path, solution);
            }
            if (IP[startIndex] != '0') {
                if (startIndex+1 < length &&
                    isPossible(length-2-startIndex, 4-1-existingDigits))
                {//try parse as two digits
                    path = restorePath;
                    path.push_back(IP.substr(startIndex, 2));
                    restoreAddress(startIndex+2, IP, path, solution);
                }
                if (startIndex+2 < length &&
                    isPossible(length-3-startIndex, 4-1-existingDigits)) {
                    //try parse as three digits
                    if (isValidIP(IP.substr(startIndex,3))) {
                        path = restorePath;
                        path.push_back(IP.substr(startIndex,3));
                        restoreAddress(startIndex+3, IP, path, solution);
                    }
                    //else, invalid three digits, invalid parse
                }
            }
        }
    }
    
    bool isValidIP(const string& candidate)
    {
        //assert string.length == 3
        //we don't validate whether first digit is zero or not
        //cos it should have be validated out before calling this func
        int first = candidate[0]-'0';
        int second = candidate[1]-'0';
        int third = candidate[2]-'0';
        int value = 100*first + 10*second + third;
        //printf("debug value = %d, string = %s\n", value, candidate.c_str());
        if (value >=0 && value <= 255) {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    string constructSolution(const vector<string>& path)
    {
        string ip;
        //assert path.size == 4
        for (int i=0; i <3; ++i) {
            ip += path[i];
            ip += ".";
        }
        ip += path[3];
        return ip;
    }
    
    bool isPossible(const int remainDigitsLength, const int remainDigits)
    {
        int min = remainDigits*1;
        int max = remainDigits*3;
        if (remainDigitsLength >= min && remainDigitsLength <= max) {
            return true;
        }
        else
        {
            return false;
        }
    }
};

//A Valid ip addr should be 0 <= x <= 255, note that 010 is invalid


//int main()
//{
//    Solution test;
//    string ipString = "25525511135";
//    //string ipString = "1111";
//    vector<string> result = test.restoreIpAddresses(ipString);
//    for (string& oneIP : result) {
//        printf("[%s]\n", oneIP.c_str());
//    }
//    return 0;
//}


