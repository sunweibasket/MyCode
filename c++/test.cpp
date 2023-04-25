#include <iostream>
#include <vector>
#include <cstring>

extern void printA(uint32_t a);
int main(int argc, char const *argv[])
{
    /* code */
    std::cout << "11" << std::endl;
    uint32_t b[] = {5, 6, 7, 8};

    std::vector<int16_t> vec{1, 2, 3};
    std::cout << "vector size: " << vec.size() << std::endl;
    if (!vec.size())
    {
        std::cout << "不是空则是true " << std::endl;
    }
    else
    {
        std::cout << "空则是false " << std::endl;
    }

    // strncmp 入参为空，会引发未定义
    const char *cha1 = std::string("").c_str();; //char *cha1 =nullptr; core dump
    const char *cha2 = std::string("hello").c_str();
    std::cout << "cha1: " << cha1 << std::endl;
    std::cout << "result: " << strncmp(cha1, cha2, 2) << std::endl;

    return 0;
}
void printA(uint32_t a)
{
    std::cout << a << std::endl;
}