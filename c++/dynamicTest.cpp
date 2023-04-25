
#include <stdlib.h>
#include <iomanip>

class dynamicTest
{
private:
    /* data */
public:
    dynamicTest(/* args */);
    ~dynamicTest();
};

dynamicTest::dynamicTest(/* args */)
{
}

dynamicTest::~dynamicTest()
{
}

int main(int argc, char const *argv[])
{
    dynamicTest *ptr2(nullptr);
    dynamicTest *ptr = dynamic_cast<dynamicTest *>(ptr2);
    printf("OK~");
    return 0;
}
