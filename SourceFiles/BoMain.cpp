//
// Created by Bộ Nguyễn on 13/4/24.
//
#include "iostream"
#include "vector"

using namespace std;

vector<string> tokenise(string csvLine, char separator) {
    vector<string> tokens;
    string token;
    int start, end;
    start = csvLine.find_first_not_of(separator, 0);
    do {
        end = csvLine.find_first_of(separator, start);
        if (start == csvLine.length() || start == end) {
            break;
        }
        if (end >= 0) token = csvLine.substr(start, end - start);
        else token = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(token);
        start = end + 1;
    } while (end != string::npos);
}

int main() {
    return 0;
}