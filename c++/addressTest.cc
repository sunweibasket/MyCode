#include <iostream>
#include <vector>
#include <cstring>

extern void printA(uint32_t a);
int main(int argc, char const *argv[])
{
    /* code */
    int a = 3;
    uint16_t k = 5;
    uint64_t kk = 55;
    int *p = &a;
    std::vector<int> vec{12};
    std::cout << "a address: " << &a << std::endl;
    std::cout << " type:" << typeid(kk).name() << std::endl;
    std::cout << " size:" << vec.size() << std::endl;

    std::cout << "p: " << p << std::endl;
    printf("%x ", p);
    return 0;
}
void printA(uint32_t a)
{
    std::cout << a << std::endl;
}