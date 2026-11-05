#include "task.h"
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>

using namespace std;

int calc_d(ifstream &file, double &d)
{
    double number = 0;
    long long count = 0;
    long double mean = 0;
    long double sum = 0;
    long double difference;
    long double change;
    long double rest;
    long double addition;
    int next;

    while (true) {
        file >> ws;

        if (file.bad()) return 2;
        if (file.eof()) break;

        file >> number;
        if (file.fail()) return 2;

        next = file.peek();

        if (file.bad()) return 2;
        if (file.eof() == false && isspace(next) == 0) return 2;

        if (count == LLONG_MAX) return 2;

        count = count + 1;
        difference = number - mean;
        change = difference / count;
        mean = mean + change;
        rest = number - mean;
        addition = difference * rest;
        sum = sum + addition;
    }

    if (count == 0) return 1;

    sum = sum / count;

    if (isfinite(sum) == false) return 2;

    if (sum > DBL_MAX) return 2;

    if (sum < 0) return 2;

    d = sum;

    return 0;
}
