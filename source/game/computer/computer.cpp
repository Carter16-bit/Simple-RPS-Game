#include <iostream>
#include <ctime>

int computerDecision(){
    srand(time(0));
    int botDecision = rand() % 3 + 1;
    return botDecision;
}

// Planned future reference