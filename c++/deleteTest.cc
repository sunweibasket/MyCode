#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 3;
    int *p = &a; // delete p; 出错，只能delete new的
    int *p2 = new int(8);
    cout << "point p address " << p << "end" << endl;
    cout << "point p2 address " << p2 << "end" << endl;

    delete p2; // delete prt后需要p2= NULL
    //free(p2); 效果和delete一样
    cout << "point address " << p2 << "end" << endl;
    if (p2)
    {
        p2 = NULL;
        cout << "P2 =NULL "
             << "end" << endl;
    }

    cout << "point address " << p2 << "end" << endl;

    return 0;
}
