#include <basicAbility.h>
#include <iostream>

// attack the target after blocking its attack
void Counter::effect(Character* target, Character* self) {

    int random_direction = (std::rand() % 3) + 1;

    if (std::rand() % 2) {
        self->attack(target, (direction) random_direction);
    } else {
        self->addStamina((int) (staminaCost / 2));
    }

    std::cout << "\nCOUNTER\n";
}

// heal yourself after getting hit
void Heal::effect(Character* target, Character* self) {
    
    if (std::rand() % 2) {
        self->heal();
    } else {
        self->addStamina((int) (staminaCost / 2));
    }
}

// a chance to hit again after hitting once
void Combo::effect(Character* target, Character* self) {
    
    int random_direction = (std::rand() % 3) + 1;

    if (std::rand() % 2) {
        self->attack(target, (direction) random_direction);
    } else {
        self->addStamina((int) (staminaCost / 2));
    }
}

// a chance to stop the target from attacking for 1 turn after being blocked
void Stun::effect(Character* target, Character* self) {
    
    if (std::rand() % 2) {
        target->stun();
    } else {
        self->addStamina((int) (staminaCost / 2));
    }
}

