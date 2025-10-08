#include "Orders.h"
#include <iostream>

// ================= Orders =================

// default constructor
Orders::Orders() {
    player = new Player();
}

// parameterized constructor
Orders::Orders(Player* playr) {
    this->player = playr;
}

// copy constructor
Orders::Orders(const Orders& order) {
    player = new Player(*order.player);
}

// destructor
Orders::~Orders() {
    delete player;
}

// assignment operator
Orders& Orders::operator=(const Orders& order) {
    if (this != &order) {
        if (this->player != nullptr) {
            delete player;
        }
        this->player = new Player(*order.player);
    }
    return *this;
}

// stream insertion
std::ostream& operator<<(std::ostream& os, const Orders& order) {
    os << "These orders belong to: " << order.player;
    return os;
}

// getters/setters
Player Orders::getPlayer() const {
    return *player;
}

void Orders::setPlayer(Player playr) {
    *player = playr;
}


// No implementation for Orders::clone() since it's pure virtual in the base class.

// ================= Deploy =================

// default constructor
Deploy::Deploy() : Orders(nullptr) {
    targ = nullptr;
    armyNum = nullptr;
}

// parameterized constructor
Deploy::Deploy(Player* playr, Territory* target, int* armynum) {
    this->player = playr;
    this->targ = target;
    this->armyNum = armynum;
}

// copy constructor
Deploy::Deploy(const Deploy& order) {
    player = new Player(*order.player);
    targ = new Territory(*order.targ);
    armyNum = new int(*order.armyNum);
}

// destructor
Deploy::~Deploy() {
    delete player;
    delete targ;
    delete armyNum;
}

// assignment operator
Deploy& Deploy::operator=(const Deploy& order) {
    if (this != &order) {
        if (this->player != nullptr) delete player;
        if (this->targ != nullptr) delete targ;
        if (this->armyNum != nullptr) delete armyNum;

        this->player = new Player(*order.player);
        this->targ = new Territory(*order.targ);
        this->armyNum = new int(*order.armyNum);
    }
    return *this;
}

// stream insertion
std::ostream& operator<<(std::ostream& os, const Deploy& order) {
    os << "This is a Deploy order belonging to " << order.player
       << " to deploy " << *order.armyNum
       << " armies to the territory " << order.targ;
    return os;
}

// getters/setters
Player Deploy::getPlayer() const {
    return *player;
}

void Deploy::setPlayer(Player playr) {
    *this->player = playr;
}

Territory Deploy::getTarg() const {
    return *targ;
}

void Deploy::setTarget(Territory targ) {
    *this->targ = targ;
}

int Deploy::getArmynum() const {
    return *armyNum;
}

void Deploy::setArmynum(int armies) {
    *armyNum = armies;
}

// validate
bool Deploy::validate() const {
    if (player == nullptr || targ == nullptr || *armyNum <= 0) return false;
    // NOTE: adjust this check depending on your Player/Territory API
    return true;
}

// execute
bool Deploy::execute() const {
    if (!validate()) return false;
    // actual logic would go here
    return true;
}

// clone
Deploy* Deploy::clone() const {
    return new Deploy(*this);
}

// ================= Advance =================

// default constructor
Advance::Advance() : Orders(nullptr) {
    targ = nullptr;
    source = nullptr;
    armyNum = nullptr;
}

// parameterized constructor
Advance::Advance(Player* playr, Territory* target, Territory* source, int* armynum) {
    this->player = playr;
    this->targ = target;
    this->source = source;
    this->armyNum = armynum;
}

// copy constructor
Advance::Advance(const Advance& order) {
    player = new Player(*order.player);
    targ = new Territory(*order.targ);
    source = new Territory(*order.source);
    armyNum = new int(*order.armyNum);
}

// destructor
Advance::~Advance() {
    delete player;
    delete targ;
    delete source;
    delete armyNum;
}

// assignment operator
Advance& Advance::operator=(const Advance& order) {
    if (this != &order) {
        if (this->player != nullptr) delete player;
        if (this->targ != nullptr) delete targ;
        if (this->source != nullptr) delete source;
        if (this->armyNum != nullptr) delete armyNum;

        this->player = new Player(*order.player);
        this->targ = new Territory(*order.targ);
        this->source = new Territory(*order.source);
        this->armyNum = new int(*order.armyNum);
    }
    return *this;
}

// stream insertion
std::ostream& operator<<(std::ostream& os, const Advance& order) {
    os << "This is an Advance order belonging to " << order.player
       << " to Advance " << *order.armyNum
       << " armies to the territory " << order.targ
       << " from source territory " << order.source;
    return os;
}

// getters/setters
Player Advance::getPlayer() const {
    return *player;
}

void Advance::setPlayer(Player playr) {
    *this->player = playr;
}

Territory Advance::getTarg() const {
    return *targ;
}

void Advance::setTarget(Territory targ) {
    *this->targ = targ;
}

Territory Advance::getSource() const {
    return *source;
}

void Advance::setSource(Territory source) {
    *this->source = source;
}

int Advance::getArmynum() const {
    return *armyNum;
}

void Advance::setArmynum(int armies) {
    *armyNum = armies;
}

// validate
bool Advance::validate() const {
    if (player == nullptr || targ == nullptr || source == nullptr || *armyNum <= 0) return false;
    // NOTE: placeholder, adapt to your Player/Territory API
    return true;
}

// execute
bool Advance::execute() const {
    if (!validate()) return false;
    return true;
}

// clone
Advance* Advance::clone() const {
    return new Advance(*this);
}


// ================= Bomb =================

// default constructor
Bomb::Bomb() : Orders(nullptr) {
    targ = nullptr;
}

// parameterized constructor
Bomb::Bomb(Player* playr, Territory* target) {
    this->player = playr;
    this->targ = target;
}

// copy constructor
Bomb::Bomb(const Bomb& order) {
    player = new Player(*order.player);
    targ = new Territory(*order.targ);
}

// destructor
Bomb::~Bomb() {
    delete player;
    delete targ;
}

// assignment operator
Bomb& Bomb::operator=(const Bomb& order) {
    if (this != &order) {
        if (this->player != nullptr) delete player;
        if (this->targ != nullptr) delete targ;

        this->player = new Player(*order.player);
        this->targ = new Territory(*order.targ);
    }
    return *this;
}

// stream insertion
std::ostream& operator<<(std::ostream& os, const Bomb& order) {
    os << "This is a Bomb order belonging to " << order.player
       << " to Bomb territory " << order.targ;
    return os;
}

// getters/setters
Player Bomb::getPlayer() const {
    return *player;
}

void Bomb::setPlayer(Player playr) {
    *this->player = playr;
}

Territory Bomb::getTarg() const {
    return *targ;
}

void Bomb::setTarget(Territory targ) {
    *this->targ = targ;
}

// validate
bool Bomb::validate() const {
    if (player == nullptr || targ == nullptr) return false;
    // NOTE: placeholder for adjacency rules
    return true;
}

// execute
bool Bomb::execute() const {
    if (!validate()) return false;
    return true;
}

// clone
Bomb* Bomb::clone() const {
    return new Bomb(*this);
}

// ================= Blockade =================

// default constructor
Blockade::Blockade() : Orders(nullptr) {
    targ = nullptr;
}

// parameterized constructor
Blockade::Blockade(Player* playr, Territory* target) {
    this->player = playr;
    this->targ = target;
}

// copy constructor
Blockade::Blockade(const Blockade& order) {
    player = new Player(*order.player);
    targ = new Territory(*order.targ);
}

// destructor
Blockade::~Blockade() {
    delete player;
    delete targ;
}

// assignment operator
Blockade& Blockade::operator=(const Blockade& order) {
    if (this != &order) {
        if (this->player != nullptr) delete player;
        if (this->targ != nullptr) delete targ;

        this->player = new Player(*order.player);
        this->targ = new Territory(*order.targ);
    }
    return *this;
}

// stream insertion
std::ostream& operator<<(std::ostream& os, const Blockade& order) {
    os << "This is a Blockade order belonging to " << order.player
       << " to Blockade territory " << order.targ;
    return os;
}

// getters/setters
Player Blockade::getPlayer() const {
    return *player;
}

void Blockade::setPlayer(Player playr) {
    *this->player = playr;
}

Territory Blockade::getTarg() const {
    return *targ;
}

void Blockade::setTarget(Territory targ) {
    *this->targ = targ;
}

// validate
bool Blockade::validate() const {
    if (player == nullptr || targ == nullptr) return false;
    // NOTE: logic should check ownership
    return true;
}

// execute
bool Blockade::execute() const {
    if (!validate()) return false;
    return true;
}

// clone
Blockade* Blockade::clone() const {
    return new Blockade(*this);
}



// ================= Airlift =================

// default constructor
Airlift::Airlift() : Orders(nullptr) {
    targ = nullptr;
    source = nullptr;
    armyNum = nullptr;
}

// parameterized constructor
Airlift::Airlift(Player* playr, Territory* target, Territory* source, int* armynum) {
    this->player = playr;
    this->targ = target;
    this->source = source;
    this->armyNum = armynum;
}

// copy constructor
Airlift::Airlift(const Airlift& order) {
    player = new Player(*order.player);
    targ = new Territory(*order.targ);
    source = new Territory(*order.source);
    armyNum = new int(*order.armyNum);
}

// destructor
Airlift::~Airlift() {
    delete player;
    delete targ;
    delete source;
    delete armyNum;
}

// assignment operator
Airlift& Airlift::operator=(const Airlift& order) {
    if (this != &order) {
        if (this->player != nullptr) delete player;
        if (this->targ != nullptr) delete targ;
        if (this->source != nullptr) delete source;
        if (this->armyNum != nullptr) delete armyNum;

        this->player = new Player(*order.player);
        this->targ = new Territory(*order.targ);
        this->source = new Territory(*order.source);
        this->armyNum = new int(*order.armyNum);
    }
    return *this;
}

// stream insertion
std::ostream& operator<<(std::ostream& os, const Airlift& order) {
    os << "This is an Airlift order belonging to " << order.player
       << " to Airlift " << *order.armyNum
       << " armies to the territory " << order.targ
       << " from source territory " << order.source;
    return os;
}

// getters/setters
Player Airlift::getPlayer() const {
    return *player;
}

void Airlift::setPlayer(Player playr) {
    *this->player = playr;
}

Territory Airlift::getTarg() const {
    return *targ;
}

void Airlift::setTarget(Territory targ) {
    *this->targ = targ;
}

Territory Airlift::getSource() const {
    return *source;
}

void Airlift::setSource(Territory source) {
    *this->source = source;
}

int Airlift::getArmynum() const {
    return *armyNum;
}

void Airlift::setArmynum(int armies) {
    *armyNum = armies;
}

// validate
bool Airlift::validate() const {
    if (player == nullptr || targ == nullptr || source == nullptr || *armyNum <= 0) return false;
    // NOTE: adjust to your rules
    return true;
}

// execute
bool Airlift::execute() const {
    if (!validate()) return false;
    return true;
}

// clone
Airlift* Airlift::clone() const {
    return new Airlift(*this);
}



// ================= Negotiate =================

// default constructor
Negotiate::Negotiate() : Orders(nullptr) {
    targ = nullptr;
}

// parameterized constructor
Negotiate::Negotiate(Player* playr, Player* target) {
    this->player = playr;
    this->targ = target;
}

// copy constructor
Negotiate::Negotiate(const Negotiate& order) {
    player = new Player(*order.player);
    targ = new Player(*order.targ);
}

// destructor
Negotiate::~Negotiate() {
    delete player;
    delete targ;
}

// assignment operator
Negotiate& Negotiate::operator=(const Negotiate& order) {
    if (this != &order) {
        if (this->player != nullptr) delete player;
        if (this->targ != nullptr) delete targ;

        this->player = new Player(*order.player);
        this->targ = new Player(*order.targ);
    }
    return *this;
}

// stream insertion
std::ostream& operator<<(std::ostream& os, const Negotiate& order) {
    os << "This is a Negotiate order belonging to " << order.player
       << " to Negotiate Player " << order.targ;
    return os;
}

// getters/setters
Player Negotiate::getPlayer() const {
    return *player;
}

void Negotiate::setPlayer(Player playr) {
    *this->player = playr;
}

Player Negotiate::getTarget() const {
    return *targ;
}

void Negotiate::setTarget(Player targ) {
    *this->targ = targ;
}

// validate
bool Negotiate::validate() const {
    if (player == nullptr || targ == nullptr) return false;
    return targ != player;
}

// execute
bool Negotiate::execute() const {
    if (!validate()) return false;
    return true;
}

// clone
Negotiate* Negotiate::clone() const {
    return new Negotiate(*this);
}

// ================= OrdersList =================

// default constructor
OrdersList::OrdersList() {
    orders = new std::vector<Orders*>();   // allocate empty vector
}

// copy constructor
OrdersList::OrdersList(const OrdersList& other) {
    orders = new std::vector<Orders*>();
    for (int i = 0; i < other.orders->size(); i++) {
        Orders* ord = other.orders->at(i)->clone(); // deep copy using clone
        this->orders->push_back(ord);
    }
}

// destructor
OrdersList::~OrdersList() {
    // free all Orders objects
    for (auto* ord : *orders) {
        delete ord;
    }
    delete orders;  // free vector itself
}

// assignment operator
OrdersList& OrdersList::operator=(const OrdersList& other) {
    if (this != &other) {
        // clear current orders
        for (auto* ord : *orders) {
            delete ord;
        }
        orders->clear();

        // deep copy from other
        for (int i = 0; i < other.orders->size(); i++) {
            Orders* ord = other.orders->at(i)->clone();
            this->orders->push_back(ord);
        }
    }
    return *this;
}

// stream insertion operator
std::ostream& operator<<(std::ostream& os, const OrdersList& orderList) {
    os << "Orders: ";
    for (int i = 0; i < orderList.orders->size(); i++) {
        os << *orderList.orders->at(i);
        if (i < orderList.orders->size() - 1) os << ", ";
    }
    os << ".";
    return os;
}

// getter
std::vector<Orders*> OrdersList::getOrders() const {
    return *orders;
}

// setter
void OrdersList::setOrders(std::vector<Orders*> orderss) {
    // clean current before setting
    for (auto* ord : *orders) {
        delete ord;
    }
    *this->orders = orderss;
}

// add order
void OrdersList::add(Orders* order) {
    this->orders->push_back(order);
}

// remove order
void OrdersList::remove(Orders* order) {
    for (auto it = orders->begin(); it != orders->end(); ++it) {
        if (*it == order) {
            delete *it;               // free memory
            orders->erase(it);        // remove from vector
            break;
        }
    }
}

// move order1 to order2 position
void OrdersList::move(Orders* order1, Orders* order2) {
    int p1 = -1;
    int p2 = -1;

    for (int i = 0; i < orders->size(); i++) {
        if (order1 == orders->at(i)) p1 = i;
        if (order2 == orders->at(i)) p2 = i;
    }

    if (p1 > -1 && p2 > -1) {
        std::swap(orders->at(p1), orders->at(p2));
    }
}

