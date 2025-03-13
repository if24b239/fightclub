#include <basicAbility.h>
#include <character.h>

int main() {
    std::random_device rd;
    unsigned int seed = rd();

    std::srand(seed);

    Character me((BasicAbility*) new Counter(), (BasicAbility*) new Heal());
    Character target((BasicAbility*) new Counter(), (BasicAbility*) new Heal());

    target.defend(UP);
    me.attack(&target, UP);
}