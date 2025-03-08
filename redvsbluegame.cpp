#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void playGame(int red, int blue) {
    vector<char> deck;
    for (int i = 0; i < red; ++i) deck.push_back('R');
    for (int i = 0; i < blue; ++i) deck.push_back('B');

    srand(time(0));
    
    while (deck.size() > 1) {
        int index1 = rand() % deck.size();
        int index2 = rand() % deck.size();
        while (index2 == index1) {
            index2 = rand() % deck.size();
        }

        char card1 = deck[index1];
        char card2 = deck[index2];

        if (index1 > index2) {
            swap(index1, index2);
        }
        deck.erase(deck.begin() + index2);
        deck.erase(deck.begin() + index1);

        if (card1 == 'R' && card2 == 'R') {
            deck.push_back('R'); 
        } else if (card1 == 'B' && card2 == 'B') {
            deck.push_back('R');
        } else if (card1 == 'R' && card2 == 'B') {
        } else if (card1 == 'B' && card2 == 'R') {
        }
    }
    
    cout << "Winner: " << (deck[0] == 'R' ? "Player1 (Red)" : "Player2 (Blue)") << endl;
}

int main() {
    int red, blue;
    cout << "Enter the number of red cards: ";
    cin >> red;
    cout << "Enter the number of blue cards: ";
    cin >> blue;
    
    playGame(red, blue);
    return 0;
}
