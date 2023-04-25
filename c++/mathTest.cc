#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

#include "mathTest.h"

using namespace std;

class mathTest
{
private:
    /* data */
public:
    mathTest(/* args */);
    ~mathTest();
};

mathTest::mathTest(/* args */)
{
}

mathTest::~mathTest()
{
}




double calMw(double dBm)
{
    return pow(10.0, dBm / 10.0);
}

double calDBm(double mw)
{
    return 10 * log10(mw);
}
int main(int argc, char const *argv[])
{
    double val0 = 3.1415;
    int val1 = 3796;
    float val2 = val1 / 10;
    std::cout << std::fixed
              << "floor(+2.7) = " << std::floor(val0 * 100 + 0.5) / 100 << '\n'
              << "floor(-2.7) = " << std::floor(-2.7) << '\n'
              << "floor(-0.0) = " << std::floor(-0.0) << '\n'
              << "floor(-Inf) = " << std::floor(-INFINITY) << '\n'
              << "3796 / 10   = " << val2 << '\n';
    // dBm mw conversion
    double dBm = 37.96;

    double mw = 0.003 * 1000;
    std::cout << "dBm->mw: " << calMw(dBm) << "mw" << std::endl;
    std::cout << "mw->dBm: " << calDBm(mw) << "dBm" << std::endl;
}
