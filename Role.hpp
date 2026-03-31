#include <string>
#include <iostream>
#ifndef ROLE_HPP
#define ROLE_HPP
namespace final{

    class Fighter;
    class Protector;
    class Caster;

    class Base{
        friend class Fighter;
        friend class Protector;
        friend class Caster;
    private:
        // WARNING: NO OTHER MEMBER VARIABLE IS ALLOWED TO BE ADDED HERE.
        std::string name;
        int health, attack;
        bool alive, defensive;
        // you only need to define aliveNumber here.
        static int aliveNumber;
    public:
        // WARNING: NO OTHER PUBLIC FUNCTION IS ALLOWED TO BE ADDED.
        // WARNING: THIS CLASS(Base) CAN NOT BE INSTANTIATED.
        // WARNING: THE FUNCTION PROVIDED NEED NO MODIFICATION
        // the function you need to implement or define is as follows.
        //(1) getAliveNumber
        //(2) Constructor
        //(3) launch_attack
        //(4) defend
        static int getAliveNumber(){
            return aliveNumber;
        }

        bool isAlive(){
            return alive;
        }

        bool isDefensive(){
            return defensive;
        }

        Base(const std::string& name, const int health, const int attack)
            : name(name), health(health), attack(attack), alive(true), defensive(false) {
            ++aliveNumber;
        }

        virtual ~Base(){
            if (alive) {
                --aliveNumber;
            }
        }

        virtual void launch_attack(Base* target) = 0;
        virtual void defend(bool flag) = 0;
    };

    class Fighter:public Base{
    public:
        // WARNING: NO OTHER PUBLIC FUNCTION IS ALLOWED TO BE ADDED.
        // WARNING: THE FUNCTION PROVIDED NEED NO MODIFICATION
        Fighter (const std::string& name, const int health,const int attack):Base(name,health,attack){}

        void launch_attack(Base* target);

        void defend(bool flag){
            if (flag) {
                defensive = 1;
                health += 3;
                attack += 2;
            } else {
                defensive = 0;
            }
        }
    };

    class Protector:public Base{
    public:
        // WARNING: NO OTHER PUBLIC FUNCTION IS ALLOWED TO BE ADDED.
        // WARNING: THE FUNCTION PROVIDED NEED NO MODIFICATION
        Protector (const std::string& name, const int health,const int attack):Base(name,health,attack){}

        void launch_attack(Base* target);

        void defend(bool flag){
            if (flag) {
                defensive = 1;
                health += 7;
                attack += 1;
            } else {
                defensive = 0;
            }
        }
    };

    class Caster:public Base{
    public:
        // WARNING: NO OTHER PUBLIC FUNCTION IS ALLOWED TO BE ADDED.
        // WARNING: THE FUNCTION PROVIDED NEED NO MODIFICATION
        Caster (const std::string& name, const int health,const int attack):Base(name,health,attack){}

        void launch_attack(Base* target);

        void defend(bool flag){
            if (flag) {
                defensive = 1;
                health += 5;
            } else {
                defensive = 0;
            }
        }
    };

}
#endif //ROLE_HPP
