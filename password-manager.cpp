// Compile: g++ -IBcrypt.cpp/src -IBcrypt.cpp/include password-manager.cpp Bcrypt.cpp/src/bcrypt.cpp Bcrypt.cpp/src/blowfish.cpp
// g++ password-manager.cpp sqlite3.o -Idatabase/sqlite-amalgamation-3500300
#include <string>
#include <iostream>
#include <fstream>
#include <array>
//#include <bcrypt.h>
#include <vector>
#include <sqlite3.h>

using namespace std;

class Account
{
    private:
        string username;
        string password;
        string email;
        bool isSaved = false;

        void readFile(vector<string>& lines)
        {
            ifstream inputFile("user-records.txt");
            string text;
            do
            {
                getline(inputFile, text);

                lines.push_back(text);
            } while(text !="");
            inputFile.close();
            
            if(lines[lines.size() - 1] == "")
            {
                lines.pop_back();
            }
        }
        
        bool usernameIsValid(string u)
        {
            if(u.size() < 2)
            {
                return false;
            }

            vector<string> usernames;
            /*readFile(usernames);

            if(usernames.size() == 0)
            {
                return true;
            }

            for(int i = 0; i < usernames.size(); i += 3)
            {
                if(usernames[i] == u)
                {
                    return false;
                }
            }
            return true;
            */
        }
        // Create a password manager that is
        // Password must be at least 8 characters
        // Password must include at least 1 number
        // Password must include at least one special character
        // Password must include at least one capital letter
        // Password must include at least one lowercase letter
        bool passwordIsValid(string p)
        {
            if(p.length() < 8)
            {
                return false;
            }

            if(!hasANumber(p))
            {
                return false;
            }

            if(!hasALower(p))
            {
                return false;
            }

            if(!hasACap(p))
            {
                return false;
            }
        
            if(!hasASpecial(p))
            {
                return false;
            }

            return true;
        }
        bool hasANumber(string p)
        {
            array<char, 10> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
            
            for(auto i: p)
            {
                for(auto n : nums)
                {
                    if(i == n)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        bool hasALower(string p)
        {
            array<char, 26> lowers = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            for(auto i : p)
            {
                for(auto l : lowers)
                {
                    if(i == l)
                    {
                        return true;
                    }
                }
            }
            return false;
        }        
        bool hasACap(string p)
        {
            array<char, 26> caps = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        for(auto i : p)
        {
                for(auto c : caps)
                {
                    if(i == c)
                    {
                        return true;
                    }
                }
            }
            return false;
        }      
        bool isALetter(char c)
        {
            array<char, 52> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                                         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
            for(auto l : letters)
            {
                if(c == l)
                    {
                        return true;
                    }
            }
            return false;
        }
              
        
        bool hasASpecial(string p)
        {
            for(auto i: p)
            {
                if(!(hasANumber(string(1, i)) || isALetter(i)))
                {
                    return true;
                }
            }
            return false;
        }
        bool emailIsValid(string e)
        {
            int index = getIndex(e, '@');

            if(index < 0)
            {
                return false;
            }

            string user = e.substr(0, (index - 1) - 0 + 1);
            string domain = e.substr(index + 1, (e.size() -1) - (index + 1) + 1);

            for (auto s : user)
            {
                if(!(isALetter(s) || isANumber(s) || isASpecial(s)))
                {
                    return false;
                }
            }
            if(user[0] == '.' || user[user.size() - 1] == '.')
            {
                return false;
            }

            bool flag = false;
            for(auto s : user)
            {
                if (isASpecial(s))
                {
                    if(flag)
                    {
                        return false;
                    }
                    else
                    {
                        flag = true;
                    }
                }
                else
                {
                    flag = false;
                }
            }
            if(flag)
            {
                return false;
            }

            if(domain[0] == '-' || domain[domain.size() - 1] == '-')
            {
                return false;
            }

            vector<string> parts;

            int start = 0;
            int end = 0;
            for(int i = 0; i < domain.size(); i++)
            {
                if(domain[i] == '.')
                {
                    end = i - 1;
                    parts.push_back(domain.substr(start, (end - start) + 1));
                    start = i + 1;
                }
            }

            if(parts[parts.size() - 1].size() < 2)
            {
                return false;
            }

            for(auto s : parts)
            {
                for(auto c : s)
                {
                    if(!(isALetter(c) || isANumber(c) || (c == '-')))
                    {
                        return false;
                    }
                }
            }

            return true;
        }
        bool isANumber(char c)
        {
            array<char, 10> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
            
            for(auto n : nums)
            {
                for(auto n : nums)
                {
                    if(c == n)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        bool isASpecial(char c)
        {
            array<char, 10> specials = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
            
            for(auto n : specials)
            {
                for(auto s : specials)
                {
                    if(c == s)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        int getIndex(string s, char c)
        {
            for(int i = 0; i <= s.size(); i++)
            {
                if(s[i] == c)
                {
                    return i;
                }
            }
            return -1;
        }

    public:
        Account() {};
        Account(string u, string p, string e)
        {
            setUsername(u);
            setPassword(p);
            setEmail(e);
        }

        void writeFile()
        {
            if(isSaved)
            {
                return;
            }
            /*
            ofstream outputFile("user-records.txt", ios::app);

            outputFile << username << endl;
            outputFile << password << endl;
            outputFile << email << endl;

            outputFile.close();
            */
           sqlite3* DB;
           int exit = 0;
           exit = sqlite3_open("database/PasswordManager.sql", &DB);
           if(exit)
           {
                std:cerr << "Error open DB" << sqlite3_errmsg(DB) << std::endl;
                return;
           }

           string sql= "INSERT INTO Account Values('" + username + "', '" + password + "', '" + email + "');";

           char* messageError;
           exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
           if(exit != SQLITE_OK)
           {
            std::cerr << "Error inserting" << std::endl;
            sqlite3_free(messageError);
           }

            sqlite3_close(DB);
            isSaved = true;
        }

        bool setUsername(string u)
        {
            if(usernameIsValid(u))
            {
                username = u;
                return true;
            }
            else
            {
                return false;
            }
        }
        string getUsername(string u)
        {
            return username;
        }

        bool setPassword(string p)
        {
            if(passwordIsValid(p))
            {
                password = p;
                return true;
            }
            else
            {
                return false;
            }
        }
        string getPassword()
        {
            return password;
        }

        bool setEmail(string e)
        {
            if(emailIsValid(e))
            {
                email = e;
                return true;
            }
            else
            {
                return false;
            }
        }
        string getEmail()
        {
            return email;
        }
};


int main()
{
    Account account;
    string password;
    string username;
    string email;
    cout << "Please enter a username: ";
    cin >> username;
    while(!account.setUsername(username))
    {
        cout << "The username you entered is invalid. Please enter a valid username." << endl << endl;
        cout << "Please enter a username: ";
        cin >> username;
    }
    
    cout << "Please enter a password: ";
    cin >> password;
    while(!account.setPassword(password))
    {
        cout << "The password you entered is invalid. Please enter a valid password." << endl << endl;
        cout << "Please enter a password: ";
        cin >> password;
    }

    cout << "Please enter an email: ";
    cin >> email;
    while(!account.setEmail(email))
    {
        cout << "The email you entered is invalid. Please enter a valid email." << endl << endl;
        cout << "Please enter an email: ";
        cin >> email;
    }
    account.writeFile();
}
