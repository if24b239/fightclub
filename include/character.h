#pragma once

#include <entity.h>
#include <basicAbility.h>
#include <functional>

enum direction {
    NONE = 0,
    UP,
    MIDDLE,
    DOWN
};

class Character : Entity {
    private:
    BasicAbility* firstAbility;
    BasicAbility* secondAbility;

    direction defendPosition;

    std::function<void(Character&)> f_hit = nullptr;
    std::function<void(Character&)> f_got_hit = nullptr;
    std::function<void(Character&)> f_blocked = nullptr;
    std::function<void(Character&)> f_got_blocked = nullptr;

    public:
    Character(BasicAbility* first, BasicAbility* second);

    void attack(Character& target, direction dir);
    void defend(direction dir) { defendPosition = dir; };
    void runAbility(Character* target, std::function<void(Character&)> fp_) { if (fp_ != nullptr) { fp_(*target); } }
};



