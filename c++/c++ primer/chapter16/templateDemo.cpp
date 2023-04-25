#include <iostream>
#include <cstring>

//模板函数
template <typename T>
int compare1(T t1, T t2)
{
    if (std::less<T>()(t1,t2)) //不直接用t1 < t2, 防止实参可能指针。模板函数应尽量减少对实参的要求
        return -1;
    if (std::less<T>()(t2,t1))
        return 1;
    return 0;
}

//非类型模板。NOTE: 在调用时，实参必须时常量，或者static类型
template <unsigned N, unsigned M>
int compare2(const char (&p1)[N], const char (&p2)[M] ) //const char (&p1)[N] 因为数组是不可以copy的，p1是数组的引用。
{
    return strcmp(p1,p2);
}

int main(int argc, char const *argv[])
{
    std::cout << "compare1(2, 1):  " << compare1(2, 1) << std::endl; //编译器自动生成compare(int t1, int t2)
    std::cout << "compare2(\"hello\", \"hi\"):  " << compare2("hello", "hi") << std::endl; //编译器自动生成compare(const char (&p1)[6], const char (&p1)[3])
    return 0;
}
