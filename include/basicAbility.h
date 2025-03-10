#pragma once

#include <string>
#include "character.h"

#include <iostream>

enum usedOn {
    HIT,
    GOT_HIT,
    BLOCKED,
    GOT_BLOCKED,
};

class BasicAbility {
    private:
    std::string name;
    int staminaCost;
    usedOn usedWhen;
    
    protected:
    virtual void effect(Character& target) {};

    public:
    
    BasicAbility(std::string name, int cost, usedOn usedWhen): name(name), staminaCost(cost), usedWhen(usedWhen) {}
    virtual ~BasicAbility() {};

    // runs the effect function and returns staminaCost
    int use(Character& target) { effect(target); return staminaCost; }

    usedOn getUsedWhen() { return usedWhen; }

};

class Counter : public BasicAbility {

    void effect(Character& target);

    public:
    Counter(): BasicAbility("Counter", 1, BLOCKED) {}
};

class Heal : public BasicAbility {

    void effect(Character& target);

    public:
    Heal(): BasicAbility("Heal", 4, GOT_HIT) {}
};

class Combo : public BasicAbility {

    void effect(Character& target);

    public:
    Combo(): BasicAbility("Combo", 2, HIT) {}
};

class Stun : public BasicAbility {

    void effect(Character& target);

    public:
    Stun(): BasicAbility("Stun", 2, GOT_BLOCKED) {}
};

