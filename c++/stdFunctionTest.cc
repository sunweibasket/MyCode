#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    using Func = function<bool()>;
    Func func1;
    //func1();
    vector<vector<int>> vec;

    // if (fun1())
    // {
    //     cout << "return true default! " << endl;
    // }
    // else
    // {
    //     cout << "return false default! " << endl;
    // }

    return 0;
}
