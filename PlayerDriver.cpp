#include <iostream>
#include <vector>
#include "Player.h"
#include "Map.h"

using namespace std;

void testPlayer() {
    // ===== Create some territories =====
    std::vector<Territory*> territories;
    Territory* t1 = new Territory("T1", "C1", "Joe", 2, 1, nullptr);
    territories.push_back(t1);
    Territory* t2 = new Territory("T2", "C2", "Joe", 3, 2, nullptr);
    territories.push_back(t2);
    Territory* t3 = new Territory("T3", "C1", "Lily", 2, 3, nullptr);
    territories.push_back(t3);
    Territory* t4 = new Territory("T4", "C2", "Joe", 1, 4, nullptr);
    territories.push_back(t4);

    // ===== Create a deck dynamically (Player expects Deck*) =====
    std::vector<Card*> cards1;
    Card* c1 = new Card(cardType::Bomb);
    cards1.push_back(c1);
    Card* c2 = new Card(cardType::Diplomacy);
    cards1.push_back(c2);
    Card* c3 = new Card(cardType::Airlift);
    cards1.push_back(c3);

    Deck* d1 = new Deck(cards1);

    // ===== Create an OrdersList dynamically (Player expects OrdersList*) =====
    OrdersList* ordli1 = new OrdersList();

    // ===== Create Player =====
    Player p1("Joe", territories, d1, ordli1);

    // ===== Test methods =====
    auto defendList = p1.toDefend(p1);
    cout << "toDefend() returned " << defendList.size() << " territories\n";

    auto attackList = p1.toAttack(p1);
    cout << "toAttack() returned " << attackList.size() << " territories\n";

    p1.issueOrder();
    cout << "issueOrder() called successfully\n";

    // ===== Cleanup dynamically allocated memory =====
    delete d1;
    delete ordli1;
    for (auto* t : territories) delete t;
    for (auto* c : cards1) delete c;
}


int main() {
    cout << "----- Player Driver Test -----\n";
    testPlayer();
    return 0;
}

