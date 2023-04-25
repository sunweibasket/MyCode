#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vecPass{31, 5, 4, 6, 40, 24, 37, 9, 3, 33, 21, 44, 16, 50, 19, 45, 13, 18, 42, 17, 11, 46, 20, 34, 7, 12, 8, 29, 27, 23, 25, 41, 36, 49, 52, 1, 39, 48, 30, 22, 47, 38, 51, 35, 43, 32};
    vector<int> vecUnPass;
    bool flag = false;

    flag = false;
    for (size_t i = 1; i < 53; i++)
    {
        for (int v : vecPass)
        {
            if (v == i)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            vecUnPass.push_back(i);
        flag = false;
    }
    flag = true;
    cout << "没有过关的人是：";
    for (int v : vecUnPass)
    {
        if (v == 42)
            flag = false;
        cout << to_string(v) + "  ";
    }
    cout << endl;
    cout << string(flag ? "大睿过关" : "大睿不过关") << endl;
}
