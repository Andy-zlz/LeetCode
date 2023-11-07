//
// Created by 张力 on 2023/11/7.
// LeetCode热题100的第20题
//
#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef struct SqStack
{
    char *base;
    char *top;
    int stacksize;
}SqStack;

class Solution {
public:
    void InitStack(SqStack &S)
    {
        S.base = new char[MAXSIZE];
        S.top = S.base;
        S.stacksize = MAXSIZE;
    }
    int findIndex(char &c1, char cArray[])
    {
        for(int i = 0; i < 6; i++)
        {
            if(c1 == cArray[i])
            {
                int index = i;
                return index;
            }
        }
    }
    bool isValid(string s)
    {
        SqStack S;
        InitStack(S);
        int index;
        int EnStackCount = 0;
        int DeStackCount = 0;
        char cArray[6] = {'(',')','[',']','{','}'};


        for(auto it = s.begin(); it != s.end(); it++)
        {
            char c = *it;
            if(c == '(' || c == '[' || c == '{')
            {
                // 入栈
                EnStackCount++;
                *S.top = c;
                ++S.top;
            }
            else
            {
                // 出栈
                if(S.top == S.base) return false; // 如果存在"}"或者"{}()}"这种情况，即当栈为空时不能直接出栈
                char c1 = *(--S.top);
                DeStackCount++;
                // 当c1是左括号(，c是右括号,找到c1在数组中的索引index，
                // 那么index+1处就是c1对应的右括号
                // 将字符串中c与index+1处的括号比对
                index = findIndex(c1, cArray);
                if(cArray[index+1] != c)
                {
                    return false;
                }
            }

        }
        // 入栈次数必须等于出栈次数
        if(EnStackCount == DeStackCount)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution solution;
    string s = "}";
    bool b = solution.isValid(s);
    if(b == 1)
        cout << s << " 括号对匹配" << endl;
    else
        cout << s <<" 括号对不匹配" << endl;
}
