#include <basicAbility.h>
#include <character.h>
#include <iostream>

bool validInput(char input, std::vector<char> valid_characters) {
    for (auto v : valid_characters) {
        if (v == input) return true;
    }
    return false;
}

int startMenu() {
    std::cout << "1. Start Fight" << std::endl
    << "2. Add Character " << std::endl
    << "3. Make Team " << std::endl;

    char input;

    std::cin >> input;

    std::vector<char> v_input = {'1', '2', '3'};

    if (!validInput(input, v_input)) {
        system("clear");
        startMenu();
        return;
    }

    return (int) input;
}

int main() {
    
    // random seeding
    std::random_device rd;
    unsigned int seed = rd();
    std::srand(seed);

    // predefined Characters
    Character Defensive((BasicAbility*) new Counter(), (BasicAbility*) new Heal());
    Character Offensive((BasicAbility*) new Stun(), (BasicAbility*) new Combo());

    // start menu

    while (1) {
        
        

    }
}