#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class copyConstucter
{
private:
    int num;
    string *str;

public:
    copyConstucter(int num, string *str);
    // 拷贝赋值操作符
    copyConstucter &operator=(const copyConstucter &copy)
    {

        cout << "copyConstucter::operator=" << endl;
        num = copy.num;
        str = copy.str;
        return *this;
    }
    // copy constructer
    copyConstucter(const copyConstucter &copy)
    {
        cout << "&copyConstucter(const copyConstucter &copy)" << endl;
        num = copy.num;
        str = copy.str;
    }

    // 加了friend会在main里面可以调到这个函数
    friend void swap(copyConstucter &copy1, copyConstucter &copy2)
    {
        cout << "copyConstucter::swap()" << endl;
        std::swap(copy1.num, copy2.num);
        std::swap(copy1.str, copy2.str);
    }
    int getNum() { return num; }
    string *getStr() { return str; }
    ~copyConstucter();
};

copyConstucter::copyConstucter(int num, string *str) : num(num), str(str)
{
    cout << "copyConstucter()" << endl;
}

copyConstucter::~copyConstucter()
{
}

void f(vector<int> vec)
{
    cout << "vec size in function: " << vec.size() << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> vec(10);
    cout << "vec size: " << vec.size() << endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << "vec size: " << vec[i] << endl;
        /* code */
        vec.pop_back();
    }

    cout << "vec size: " << vec.size() << endl;
    f(vector<int>(10));
    // f(10);
    string str("aabb");
    // int num(3);
    copyConstucter inst(3, &str);
    cout << "copyConstucter.num:" << inst.getNum() << endl
         << " copyConstucter.str:" << inst.getStr() << endl
         << "copyConstucter.*str:" << *inst.getStr() << endl
         << "str:" << str << endl;

    copyConstucter inst2(inst);
    cout << "copyConstucter.num:" << inst2.getNum() << endl
         << " copyConstucter.str:" << inst2.getStr() << endl
         << "copyConstucter.*str:" << *inst2.getStr() << endl;
    // 拷贝初始化
    copyConstucter inst3 = inst2;
    // 拷贝赋值操作符
    inst3 = inst;
    cout << "all done!" << endl;
    int a = 1, b = 2;
    swap(a, b);

    string str5("aaa");
    string str6("bbb");
    copyConstucter inst5(1, &str5);
    copyConstucter inst6(1, &str6);
    // 即使加了using std::swap;，仍然匹配到我们定义的swap
    using std::swap;
    swap(inst5, inst6);


    string s1 = "s1";
    string s2 = "s2";
    //没有意义，可以限制
    //String & operator=(const string &) &; 后面加上了&, 使用=操作符，只能时左值
    s1 + s2 = "hello world!";

    cout << "s1+s2: " << s1 + s2 << endl
         << "s1: " << s1 << endl
         << "s2: " << s2 << endl;

    return 0;
}
