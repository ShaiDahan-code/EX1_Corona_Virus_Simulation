#include <iostream>
#include "ExecuteProgram.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./a.out <First Gen File> <Config File> " << endl;
        return 1;
    }

    ExecuteProgram a(argv[1],argv[2]);
    a.execute();
    return 0;
}
