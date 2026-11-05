#include "task.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string file_name;
    ifstream file;
    double d = 0;
    int code;

    cout << "File name: ";
    getline(cin, file_name);

    if (cin.fail()) {
        cout << "Cannot read file name\n";
        return 2;
    }

    file.open(file_name);

    if (file.is_open() == false) {
        cout << "Cannot open file\n";
        return 3;
    }

    code = calc_d(file, d);
    file.close();

    if (code == 1) {
        cout << "Empty file\n";
        return 1;
    }

    if (code == 2) {
        cout << "Incorrect data or result is too large\n";
        return 2;
    }

    cout.precision(17);

    cout << "D = ";
    cout << d;
    cout << '\n';

    return 0;
}
