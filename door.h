#include <iostream>

enum Present {CAR, GOAT};

class Door {
public:
    /* randomly put the present to each door */
    void randPresent() {
      _door[0] = GOAT;
      _door[1] = GOAT;
      _door[2] = GOAT;
      int carDoor = rand() % 3;
      _door[carDoor] = CAR;
    }
    /* return the present of the door */
    Present doorPresent(int playerChoosen) {
      return _door[playerChoosen];
    }
    
private:
  Present _door[3];
};
