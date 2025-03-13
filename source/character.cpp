#include <character.h>
#include <basicAbility.h>

Character::Character(BasicAbility* first, BasicAbility* second): firstAbility(first), secondAbility(second), defendPosition(NONE), stunned(false) {

    // get first ability lambda
    std::function<void(Character*, Character*)> first_lambda = [this, first](Character* target, Character* self) {
        // use ability and update stamina
        removeStamina(first->use(target, this));
    };

    // get second ability lambda
    std::function<void(Character*, Character*)> second_lambda = [this, second](Character* target, Character* self) {
        // use ability and update stamina
        removeStamina(second->use(target, this));
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
}

Character::~Character() {
    delete firstAbility;
    delete secondAbility;
}


bool Character::attack(Character* target, direction dir) {

    // dont run if stunned
    if (stunned) {
        stunned = false;
        return false;
    }

    // call functions depending on what happened
    if (dir == target->defendPosition) {
        target->runAbility(this, target, target->f_blocked);
        runAbility(target, this, f_got_blocked);
    } else {
        target->runAbility(this, target, target->f_got_hit);
        runAbility(target, this, f_hit);

        if (target->damage()) {
            target->fightLost();
            fightWon();
            return true;
        };
    }
    return false;

}