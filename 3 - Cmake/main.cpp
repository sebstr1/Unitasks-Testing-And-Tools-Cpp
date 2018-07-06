#ifdef DEBUG
#include <memstat.hpp>
#endif

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello CMake!" << endl;
    int *tal = new int;
    int *array = new int[10];

    delete array;

    return 0;

    delete tal;
    return 0;
}

