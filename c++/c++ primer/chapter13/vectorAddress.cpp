#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{

    using namespace std;
    vector<string> vec{"aa", "bbb", "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc", "dddd"};
    cout << "vec " << &vec << endl
         << "vec[0] " << &vec[0] << endl
         << "vec[1] " << &vec[1] << endl
         << "vec[2] " << &vec[2] << endl
         << "vec[3] " << &vec[3] << endl
         << "sizeof(vec)  " << sizeof(vec) << endl;

    vec.push_back("eeeeeee");
    vec.push_back("eeeeeee");
    vec.push_back("eeeeeee");
    vec.push_back("eeeeeeec1111");
    vec.push_back("eeeeeee");
    vec.push_back("eeeeeee");
    vec.push_back("eeeeeee");
    vec.push_back("eeeeeee");
    vec.push_back("eeeeeee");
    vec.push_back("eeeeeee");
    cout << "vec " << &vec << endl
         << "vec[0] " << &vec[0] << endl
         << "vec[1] " << &vec[1] << endl
         << "vec[2] " << &vec[2] << endl
         << "vec[3] " << &vec[3] << endl
         // 结果是1，指针地址相减，结果是等于元素下表的差值（p++）。string是32bit对齐
         << "&vec[3]-&vec[2] " << &vec[3] - &vec[2] << endl
         << "sizeof(vec)  " << sizeof(vec) << endl;
    return 0;
}
