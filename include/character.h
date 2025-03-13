#pragma once

#include <entity.h>
#include <functional>

class BasicAbility;

enum direction {
    NONE = 0,
    UP,
    MIDDLE,
    DOWN
};

class Character : public Entity {
    private:
    BasicAbility* firstAbility;
    BasicAbility* secondAbility;

    direction defendPosition;

    bool stunned;

    public:
    Character(BasicAbility* first, BasicAbility* second);
    ~Character();

    std::function<void(Character*, Character*)> f_hit = nullptr;
    std::function<void(Character*, Character*)> f_got_hit = nullptr;
    std::function<void(Character*, Character*)> f_blocked = nullptr;
    std::function<void(Character*, Character*)> f_got_blocked = nullptr;

    // returns true if fight is won
    bool attack(Character* target, direction dir);
    void defend(direction dir) { defendPosition = dir; }
    void stun() { stunned = true; }
    void runAbility(Character* target, Character* self, std::function<void(Character*, Character*)> fp_) { if (fp_ != nullptr) { fp_(target, self); } }
};



