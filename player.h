#include <vector>
#include <cstdlib>

using namespace std;

class Player {
private:
    int estrategia;
    // 1. Cinco números pares
    // 2. Cinco números impares
    // 3. Un número primo
    // 4. Tres números múltiplos de 10
    // 5. Dos números múltiplos de 25
public:
    Player(int n) {
        this->estrategia = n;
    }
    ~Player();
}