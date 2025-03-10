#include <character.h>

Character::Character(BasicAbility* first, BasicAbility* second): firstAbility(first), secondAbility(second), defendPosition(MIDDLE) {

    // get first ability lambda
    std::function<void(Character&)> first_lambda = [this, first](Character& target) {
        // use ability and update stamina
        removeStamina(first->use(target));
    };

    // get second ability lambda
    std::function<void(Character&)> second_lambda = [this, second](Character& target) {
        // use ability and update stamina
        removeStamina(second->use(target));
    };

    switch (first->getUsedWhen()) {
        case HIT:
            f_hit = first_lambda;
            break;
        case GOT_HIT:
            f_got_hit = first_lambda;
            break;
        case BLOCKED:
            f_blocked = first_lambda;
            break;
        case GOT_BLOCKED:
            f_got_blocked = first_lambda;
            break;
    }

    switch (second->getUsedWhen()) {
        case HIT:
            f_hit = second_lambda;
            break;
        case GOT_HIT:
            f_got_hit = second_lambda;
            break;
        case BLOCKED:
            f_blocked = second_lambda;
            break;
        case GOT_BLOCKED:
            f_got_blocked = second_lambda;
            break;
    }
};


void Character::attack(Character& target, direction dir) {

    if (dir == target.defendPosition) {
        target.runAbility(this, f_blocked);
        runAbility(&target, f_got_blocked);
    } else {
        target.runAbility(this, f_got_hit);
        runAbility(&target, f_hit);
    }

}