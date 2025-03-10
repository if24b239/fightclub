#pragma once

class Entity {
    
    int healthPoints;
    int stamina;

    int wins;
    int losses;


    public:
    Entity(): healthPoints(5), stamina(10), wins(0), losses(0) {}
    virtual ~Entity() {};

    //getters
    int getWins() { return wins; }
    int getLosses() { return losses; }
    int getHealthPoints() { return healthPoints; }
    int getStamina() { return stamina; }

    //setter
    bool damage() { return (--healthPoints <= 0) ? true : false; }
    void fightWon() { wins++; }
    void fightLost() { losses++; }
    void removeStamina(int loss) { stamina = loss; }
};