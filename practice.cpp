#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <array>
using namespace std;

string reverseString(string s) {
    string reverse = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        reverse += s[i];
    }
    return reverse;
}

bool isPalindrome(const string& s)
{
    return s == reverseString(s);
}

string oddReverseString(string s) {
    string rev = reverseString(s);
    string result = "";
    for (int i = 0; i < rev.size(); i += 2) {
        result += rev[i];
    }
    return result;
}

int getLargestPalindromeLength(const string& s)
{
    int largest = 0;
    string sub;

    for(int i = 0; i <= s.length() - 1; i++)
    {
        for(int j = i; j <= s.length() - 1; j++)
        {
            sub = s.substr(i, j - i + 1);
            if(isPalindrome(sub))
            {
                if(sub.length() > largest)
                {
                    largest = sub.length();
                }
            }
        }
    }
    return largest; // ✅ added return
}

// NEW FUNCTION: getLongestPalindromes
vector<string> getLongestPalindromes(const string& s)
{
    vector<string> result;
    int largest = getLargestPalindromeLength(s);
    string sub;

    for(int i = 0; i <= s.length() - 1; i++)
    {
        for(int j = i; j <= s.length() - 1; j++)
        {
            sub = s.substr(i, j - i + 1);
            if(isPalindrome(sub) && sub.length() == largest)
            {
                result.push_back(sub);
            }
        }
    }
    return result;
}

bool hasValidParens(const string& s)
{
    stack<int> parens;
    bool isValid;

    for(auto c : s)
    {
        if(c == '(')
        {
            parens.push(1);
        }
        
        if(c == ')')
        {
            if(parens.empty())
            {
                return false;
            }        
            parens.pop();  
        } 

    }
    if(parens.empty())
    {
        isValid = true;
    }
    else
    {
        isValid = false;
    }
    return isValid;
}

// NEW FUNCTION: hasEqualAmounts
bool hasEqualAmounts(const string& s, char x, char y)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == x)
        {
            st.push(x);
        }
        else if (c == y)
        {
            if (!st.empty() && st.top() == x)
            {
                st.pop(); // cancel x with y
            }
            else
            {
                st.push(y);
            }
        }
    }
    return st.empty(); // equal if nothing left unmatched
}

string stackReverseString(const string& s)
{
    stack <char> stk;
    string reverse = "";

    for (auto c : s)
    {
        stk.push(c);
    }

    while(!stk.empty())
    {
        reverse += stk.top();
        stk.pop();
    }

    return reverse;
}

string reverseWords(const string& s)
{
    stack<char> stk;
    string reverse = "";

    for(auto c : s)
    {
        if(c == ' ')
        {
            while(!stk.empty())
            {
                reverse += stk.top();
                stk.pop();
            }
            reverse += ' ';
        }
        stk.push(c);
    }
    while(!stk.empty())
    {
        reverse += stk.top();
        stk.pop();
    }

    return reverse;
}

stack<char> getReverseStack(stack<char> stk)
{
    stack<char> reverse;

    while(!stk.empty())
    {
        reverse.push(stk.top());
        stk.pop();
    }

    return reverse;
}

int getMaxEnergy(vector<int> energy, int k)
{
    int max;
    int sum = 0;

    for(int i = 0; i <= energy.size() - 1; i++) 
    {
        int j = i;
        while(j <= energy.size() - 1)
        {
            sum += energy[j];
            j += k;
        }
        if(i == 0)
        {
            max = sum;
        }
        else
        {
            if(sum > max)
            {
                max = sum;
            }
        }
        sum = 0;
    }

    return max;
}

bool canJump(vector<int>& nums)
{
    if(nums.size() == 1)
    {
        return true;
    }
    if(nums.size() == 0)
    {
        return false;
    }
    stack<int> jumps;
    int index = 0;
    int jump = 1;
    while(true)
    {
        if(jump <= nums[index])
        {
            jumps.push(jump);
            index += jump;
            jump = 1;
            if(index == nums.size() - 1)
            {
                return true;
            }
        }
        else
        {
            //backtrack
            if(jumps.empty())
            {
                return false;
            }
            jump = jumps.top();
            jumps.pop();
            index -= jump;
            jump += 1;
        }
    }
}

template <std::size_t M, std::size_t N>
// Determines whether a word is in a word search according to standard word search rules.
bool hasWord(array<array<char, N>, M>& wordSearch, const string& word) // M x N array
{
    bool found = false;
    const int LENGTH = word.size();

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(wordSearch[i][j] == word[0])
           {
                if(j + LENGTH - 1 < N)
                {
                    string temp = "";
                    for(int k = 0; k < LENGTH; k++)
                    {
                        temp += wordSearch[i][j + k];
                    }
                    if(temp == word)
                    {
                        return true;
                    }
                }


                if(j - (LENGTH - 1) >= 0)
                {
                    string temp = "";
                    for(int k = 0; k < LENGTH; k++)
                {
                    temp += wordSearch[i][j - k];
                }
                    if(temp == word || reverseString(temp) == word)
                    {
                        return true;
                    }
                }
                
                if(i - (LENGTH - 1) >= 0)
                {
                    string temp = "";
                    for(int k = 0; k < LENGTH; k++)
                    {
                        temp += wordSearch[i - k][j];
                    }
                    if(temp == word || reverseString(temp) == word)
                    {
                        return true;
                    }
                }    
                
                
                if (i + LENGTH - 1 < M)
                {   
                    string temp = "";
                    for (int k = 0; k < LENGTH; k++)
                    {
                    temp += wordSearch[i + k][j];
                    }
                    if(temp == word | reverseString(temp) == word)
                    {
                    return true;
                    };
                }

                if(i - (LENGTH - 1) >= 0 && j + LENGTH - 1 < N)
                {
                    string temp = "";
                    for(int k = 0; k < LENGTH; k++)
                    {
                        temp += wordSearch[i - k][j + k];
                    }
                    if(temp == word || reverseString(temp) == word)
                    {
                        return true;
                    }
                }

                if(i - (LENGTH - 1) >= 0 && j - (LENGTH - 1) >= 0)
                {
                    string temp = "";
                    for(int k = 0; k < LENGTH; k++)
                    {
                        temp += wordSearch[i - k][j - k];
                    }
                    if(temp == word || reverseString(temp) == word)
                    {
                        return true;
                    }
                }
                
                // Case 7: South-East
                if(i + LENGTH - 1 < M && j + LENGTH - 1 < N)
                {
                    string temp = "";
                    for(int k = 0; k < LENGTH; k++)
                    {
                        temp += wordSearch[i + k][j + k];
                    }
                    if(temp == word || reverseString(temp) == word)
                    {
                        return true;
                    }
                }
                // Case 8: South-West
                if(i + LENGTH - 1 < M && j - (LENGTH - 1) >= 0)
                {
                    string temp = "";
                    for(int k = 0; k < LENGTH; k++)
                    {
                        temp += wordSearch[i + k][j - k];
                    }
                    if(temp == word || oddReverseString(temp) == word)
                    {
                        return true;
                    }
                }

                int end = word.length() + j - 1;
                if(end < N)
                {
                    string temp = "";
                    for(int k = j; (k - j + 1) != word.length() + 1; k++)
                    {
                        temp += wordSearch[i][k];
                    }
                    if(temp == word)
                    {
                        return true;
                    }
                }                                    
            }
        }
    }

    return false;
}

int main() 
{
    string s = "hello";
    cout << reverseString(s) << endl;

    string p = "kayak";
    if(isPalindrome(p))
    {
        cout << p << " is a palindrome" << endl;
    }
    else
    {
        cout << p << " is not a palindrome" << endl;
    }

    cout << oddReverseString(s) << endl;

    string l = "abcdnevenxyz";
    cout << "The length of the palindrome is " << getLargestPalindromeLength(l) << endl;

    string test = "abcnevenxyzkayak";
    vector<string> longest = getLongestPalindromes(test);
    cout << "Longest palindromes: ";
    for(string pal : longest)
    {
        cout << pal << " ";
    }
    cout << endl;

    string parens1 = "(1 + 2) + (3 * 4)";
    string parens2 = "((1 + 2) + (3 * 4)";
    string parens3 = "(1 + 2) + )3 * 4)";
    
    cout << hasValidParens(parens1) << endl;
    cout << hasValidParens(parens2) << endl;
    cout << hasValidParens(parens3) << endl;


    vector<int> energy = {5, 2, -10, -5, 1};
    int k = 3;
    cout << getMaxEnergy(energy, k) << endl;
    energy = {-2, -3, -1};
    k = 2;
    cout << getMaxEnergy(energy, k) << endl;

    cout << "canJump" << endl;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << canJump(nums) << endl;
    nums = {3, 2, 1, 0, 4};
    cout << canJump(nums) << endl;
    nums = {3, 1, 0, 1, 4};
    cout << canJump(nums) << endl;
    nums = {400, 0, 0, 0, 0};
    cout << canJump(nums) << endl;

    array<array<char, 5>, 6> grid; // 6 (rows) x 5 (columns) array
    // example word search from https://www.eslprintables.com/previews/845364_1-Simple_Word_Search.jpg
    grid = {{{'C', 'A', 'T', 'C', 'M'},
             {'Y', 'Z', 'A', 'B', 'A'},
             {'D', 'O', 'G', 'B', 'T'},
             {'V', 'P', 'Q', 'O', 'B'},
             {'Q', 'D', 'A', 'X', 'A'},
             {'S', 'B', 'S', 'S', 'T'}}};

    string word = "BAT";
    cout << word << endl;
    cout << hasWord(grid, word) << endl;
    word = "VOA";
    cout << word << endl;
    cout << hasWord(grid, word) << endl;
    word = "ABC";
    cout << word << endl;
    cout << hasWord(grid, word) << endl;

    string words = "hello world";
    cout << reverseWords(words) << endl;

    // ✅ Tests for hasEqualAmounts
    string eqTest1 = "aabcdd";
    cout << "Equal a & d in aabcdd? " << hasEqualAmounts(eqTest1, 'a', 'd') << endl;

    string eqTest2 = "xxxyyy";
    cout << "Equal x & y in xxxyyy? " << hasEqualAmounts(eqTest2, 'x', 'y') << endl;

    string eqTest3 = "xxxyy";
    cout << "Equal x & y in xxxyy? " << hasEqualAmounts(eqTest3, 'x', 'y') << endl;

    return 0;
}
