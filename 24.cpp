#include <array>
#include <string>
#include <iostream>

/*Consider the following C++ code: array<int, 10> chars = {'w', 'n', 'a', 'q', 'X', 'i', 'F', 'g', 'b', 'E'}; string s = "ghellow";    
Write a function that will return true if s has at least two of the characters in chars and false otherwise.
(Hint: use nested for loops and a counter variable).*/

using namespace std;

bool hasAtLeastTwo(const string& s, const array<int, 10>& chars) {
    int count = 0;


    for (char c : s) {
        for (int ch : chars) {
            if (c == ch) {
                count++;
                break;
            }
        }
        if (count >= 2) {
            return true;
        }
    }
    return false;
}

int main() {
    array<int, 10> chars = {'w', 'n', 'a', 'q', 'X', 'i', 'F', 'g', 'b', 'E'};
    string s = "ghellow";

    if (hasAtLeastTwo(s, chars)) {
        cout << "The string has at least two characters from the array." << endl;
    } else {
        cout << "The string does not have at least two characters from the array." << endl;
    }

    return 0;
}