#include <iostream>
#include <string>
using namespace std;

// Write a C++ function that takes a string 's' and a character 'c' as input and returns true if 'c' appears in 's' an odd number of times and returns false otherwise. Hint: Use the counter technique we talked about in class.

bool appearsOddTimes(const string& s, char c) {
    int count = 0;

    for (char ch : s) {
        if (ch == c) {
            count++;
        }
    }

    return count % 2 != 0;
}

int main() {
    string s = "hello world";
    char c = 'l';

    if (appearsOddTimes(s, c)) {
        cout << "The character '" << c << "' appears an odd number of times in \"" << s << "\"." << endl;
    } else {
        cout << "The character '" << c << "' appears an even number of times in \"" << s << "\"." << endl;
    }

    return 0;
}
