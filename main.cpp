#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "player.h"

using namespace std;


// Nota: 

//cada jugador sera representado por una estrategia concreta
//se utilizarán los patrones strategy y observer.
//el observer será el vector de numeros el cual notificará a los jugadores que representan cada una de las estrategias




class Strategy
{
private:
    vector<int> numeros;
public:
    virtual ~Strategy() {}
    virtual void get(vector<int> n) = 0;
};


class Context
{
private:
    Strategy *strategy_;
public:
    Context(Strategy *strategy = nullptr) : strategy_(strategy)
    {
    }
    ~Context()
    {
        delete this->strategy_;
    }

    void set_strategy(Strategy *strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }

};


// Cinco numeros pares
class ConcreteStrategyA : public Strategy
{ 
public:
    void get(vector<int> n) override {
        int count=0;
        while (count != 5) {
            for (auto i: n) {
                if (i%2==0) count++;
            }
        }
        if (count == 5) cout << "Listo";
        
    } 
    
};

// Cinco numeros impares
class ConcreteStrategyB : public Strategy
{
public:   
    void get(vector<int> n) override {
        int count=0;
        while (count != 5) {
            for (auto i: n) {
                if (i%2!=0) count++;
            }
        }
        if (count == 5) cout << "Listo";
    }
};

// Un numero primo
class ConcreteStrategyC : public Strategy
{
public:  
    void get(vector<int> n) override {
        
    }
};

// Tres numeros multiplos de 10
class ConcreteStrategyD : public Strategy
{
public:  
    void get(vector<int> n) override {
        int count=0;
        while (count != 3) {
            for (auto i: n) {
                if (i%10==0) count++;
            }
        }
        if (count == 3) cout << "Listo";
    }
};

// Dos numeros multiplos de 25
class ConcreteStrategyE : public Strategy
{
public:  
    void get(vector<int> n) override {
        int count=0;
        while (count != 2) {
            for (auto i: n) {
                if (i%25==0) count++;
            }
        }
        if (count == 2) cout << "Listo";
    }
};

class Observer {
private:
    //random
    vector<int> numeros;
public:
    Observer() {}

    void nuevo_numero() {
        int a = rand() % 100 + 1; 
    }

    void notify();
};



void Initialize()
{
    vector<Player*> jugadores;
    for (int i=1; i<=5; i++) {
        Player* jugador = new Player(i);
    }
    
}

int main()
{
    Initialize();
    return 0;
}