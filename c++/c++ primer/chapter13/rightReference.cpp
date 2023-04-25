#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "right reference test start" << std::endl;
    int &&rr1 = 42;
    rr1 = 56;
    int &&rr2 = std::move(rr1);
    std::cout << "rr1 valee: " << rr1 << std::endl; // 56
    std::cout << "rr2 valee: " << rr2 << std::endl; // 56

    rr1 = 92;
    std::cout << "rr1 valee: " << rr1 << std::endl; // 92
    std::cout << "rr2 valee: " << rr2 << std::endl; // 92

    rr2 = 66;
    std::cout << "rr1 valee: " << rr1 << std::endl; // 66
    std::cout << "rr2 valee: " << rr2 << std::endl; // 66
    std::cout << "right reference test done" << std::endl;

    return 0;
}
