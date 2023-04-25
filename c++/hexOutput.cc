#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <iomanip>


using namespace std;

int main(int argc, char const *argv[])
{

    long long int num = 99931313154;
    ostringstream os;
    os << hex << setw(16) << setfill('0') << num;
    cout << os.str() << endl;
    printf("%08x \n", num);
    

    // ostream os1; ostream 默认构造函数是protected的
}
