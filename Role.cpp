#include "Role.hpp"
#include <iostream>

namespace final {

int Base::aliveNumber = 0;

static const char* role_name(Base* p){
    if (dynamic_cast<Fighter*>(p)) return "Fighter";
    if (dynamic_cast<Protector*>(p)) return "Protector";
    return "Caster";
}

static int effectiveness_multiplier(Base* attacker, Base* target){
    if (dynamic_cast<Fighter*>(attacker) && dynamic_cast<Caster*>(target)) return 2;
    if (dynamic_cast<Caster*>(attacker) && dynamic_cast<Protector*>(target)) return 2;
    if (dynamic_cast<Protector*>(attacker) && dynamic_cast<Fighter*>(target)) return 2;
    return 1;
}

void Fighter::launch_attack(Base *target) {
    int coeff = effectiveness_multiplier(this, target);
    if (!target->defensive) {
        int damage = attack * coeff;
        target->health -= damage;
        if (target->alive && target->health <= 0) {
            target->alive = false;
            --Base::aliveNumber;
            std::cout << role_name(target) << ' ' << target->name << " is killed\n";
        }
    } else {
        int damage = attack * coeff - target->attack;
        if (damage < 0) damage = 0;
        target->health -= damage;
        bool targetDied = (target->alive && target->health <= 0);
        if (targetDied) {
            target->alive = false;
            --Base::aliveNumber;
            std::cout << role_name(target) << ' ' << target->name << " is killed\n";
        }
        // reflect damage to attacker (Fighter is not Caster)
        health -= target->attack;
        if (alive && health <= 0) {
            alive = false;
            --Base::aliveNumber;
            std::cout << "Fighter " << name << " is killed\n";
        }
    }
}

void Protector::launch_attack(Base *target) {
    int coeff = effectiveness_multiplier(this, target);
    if (!target->defensive) {
        int damage = attack * coeff;
        target->health -= damage;
        if (target->alive && target->health <= 0) {
            target->alive = false;
            --Base::aliveNumber;
            std::cout << role_name(target) << ' ' << target->name << " is killed\n";
        }
    } else {
        int damage = attack * coeff - target->attack;
        if (damage < 0) damage = 0;
        target->health -= damage;
        bool targetDied = (target->alive && target->health <= 0);
        if (targetDied) {
            target->alive = false;
            --Base::aliveNumber;
            std::cout << role_name(target) << ' ' << target->name << " is killed\n";
        }
        // reflect damage to attacker (Protector is not Caster)
        health -= target->attack;
        if (alive && health <= 0) {
            alive = false;
            --Base::aliveNumber;
            std::cout << "Protector " << name << " is killed\n";
        }
    }
}

void Caster::launch_attack(Base *target) {
    int coeff = effectiveness_multiplier(this, target);
    if (!target->defensive) {
        int damage = attack * coeff;
        target->health -= damage;
        if (target->alive && target->health <= 0) {
            target->alive = false;
            --Base::aliveNumber;
            std::cout << role_name(target) << ' ' << target->name << " is killed\n";
        }
    } else {
        int damage = attack * coeff - target->attack;
        if (damage < 0) damage = 0;
        target->health -= damage;
        bool targetDied = (target->alive && target->health <= 0);
        if (targetDied) {
            target->alive = false;
            --Base::aliveNumber;
            std::cout << role_name(target) << ' ' << target->name << " is killed\n";
        }
        // reflect damage to attacker: Caster is immune (0)
        // no HP change to caster from reflect
    }
}

} // namespace final

