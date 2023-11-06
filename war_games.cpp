#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

enum Card{
    two,three,four,five,six,seven,eight,nine,T,J,Q,K,A
};

void addCards(deque<Card>& players, char ch) {
    switch (ch) {
        case '2': players.push_back(Card::two); break;
        case '3': players.push_back(Card::three); break;
        case '4': players.push_back(Card::four); break;
        case '5': players.push_back(Card::five); break;
        case '6': players.push_back(Card::six); break;
        case '7': players.push_back(Card::seven); break;
        case '8': players.push_back(Card::eight); break;
        case '9': players.push_back(Card::nine); break;
        case 'T': players.push_back(Card::T); break;
        case 'J': players.push_back(Card::J); break;
        case 'Q': players.push_back(Card::Q); break;
        case 'K': players.push_back(Card::K); break;
        case 'A': players.push_back(Card::A); break;
    }
}

inline void printQue(deque<Card> &player1) {
    for (auto &i : player1) 
        cout << i << "-";
    cout << "\n";
}

void doGame(deque<Card> player1, deque<Card> player2) {
    while (!player1.empty() || !player2.empty()) {
        if (player1.front() > player2.front()) {
            if (player1.size() < 1)
                break;
            if (player2.size() < 1)
                break;
            player1.pop_front();
            player1.push_back(player2.front());
            player2.pop_front();
            // printQue(player1);
            // printQue(player2);
        } else if (player1.front() < player2.front()) {
            if (player1.size() < 1)
                break;
            if (player2.size() < 1)
                break;
            player2.pop_front();
            player2.push_back(player1.front());
            player1.pop_front();
            // printQue(player1);
            // printQue(player2);
        } else if (player1.front() == player2.front()) {
            if (player1.size() < 1)
                break;
            if (player2.size() < 1)
                break;
            if (player1 == player2)
                break;
            deque<Card> temp = player2;
            reverse(temp.begin(), temp.end());
            if (player1 == temp)
                break;

            player1.push_back(player1.front());
            player1.pop_front();
            player2.push_back(player2.front());
            player2.pop_front();
            // printQue(player1);
            // printQue(player2);
        }
    }
    if (player2.empty()) {
        cout << "player 1" << "\n";
        return;
    } else if (player1.empty()) {
        cout << "player 2" << "\n";
        return;
    } else {
        cout << "draw" << "\n";
        return;
    }
    cout << "shouldnt be here" << "\n";
}


int main() {
    int n;
    std::cin >> n;
    std::string temp;
    std::getline(std::cin, temp);
    
    vector<deque<Card>> games;
    
    deque<Card> player1, player2;
    string playerCard1, playerCard2;

    for (int i = n; i > 0; --i) {
        player1.clear();
        player2.clear();
        getline(cin, playerCard1);
        getline(cin, playerCard2);
        for (auto &k : playerCard1)
            addCards(player1, k);
        for (auto &k : playerCard2)
            addCards(player2, k);
        games.push_back(player1);
        games.push_back(player2);
    }

    // for (auto &i : games)
    //     printQue(i);

    for (int i = 0; i < 2*n; i = i + 2) {
        int num1 = i;
        int num2 = i+1;

        deque<Card> temp1, temp2;

        temp1 = games[num1];
        temp2 = games[num2];
        
        // printQue(temp1);
        // printQue(temp2);

        doGame(temp1, temp2);

    }

    
   

    return 0;
}