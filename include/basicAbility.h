#pragma once

#include <string>
#include <random>
#include <character.h>

class Character;

enum usedOn {
    HIT,
    GOT_HIT,
    BLOCKED,
    GOT_BLOCKED,
};

class BasicAbility {
    private:
    std::string name;
    usedOn usedWhen;
    
    protected:
    int staminaCost;
    virtual void effect(Character* target, Character* self) {};

    public:
    BasicAbility(std::string name, int cost, usedOn usedWhen): name(name), usedWhen(usedWhen), staminaCost(cost) {}
    virtual ~BasicAbility() {};

    // runs the effect function and returns staminaCost
    int use(Character* target, Character* self) { effect(target, self); return staminaCost; }

    usedOn getUsedWhen() { return usedWhen; }

} typedef BasicAbility;

class Counter : public BasicAbility {

    void effect(Character* target, Character* self);

    public:
    Counter(): BasicAbility("Counter", 1, BLOCKED) {}
};

class Heal : public BasicAbility {

    void effect(Character* target, Character* self);

    public:
    Heal(): BasicAbility("Heal", 4, GOT_HIT) {}
};

class Combo : public BasicAbility {

    void effect(Character* target, Character* self);

    public:
    Combo(): BasicAbility("Combo", 2, HIT) {}
};

class Stun : public BasicAbility {

    void effect(Character* target, Character* self);

    public:
    Stun(): BasicAbility("Stun", 2, GOT_BLOCKED) {}
};

