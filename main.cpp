/* experiment of Monty Hall problem */
#include <iostream>
#include <time.h>
#include "door.h"

int main() {

  Door doors;
  int playerChoosen;
  int runs = 100000;
  int choosenCarDoor = 0;
  /* initialize random seed */
  srand (time(NULL));

  /*** run for no change version ***/
  for(int i=0; i<runs; i++)
  {
    /* decide which door has car */
    doors.randPresent();
    /* player choose a door */
    playerChoosen = rand() % 3;
    /* if player choosen the car door */
    if(doors.doorPresent(playerChoosen) == CAR) {
      choosenCarDoor++;
    }
  }
  std::cout<<"Probability of choosing car door in no changing the door is "<<((double)choosenCarDoor/(double)runs)<<std::endl;

  //*** run for change door version ***/
  choosenCarDoor = 0;
  for(int i=0; i<runs; i++)
  {
    /* decide which door has car */
    doors.randPresent();
    /* player choose a door */
    playerChoosen = rand() % 3;
    /* open one of the goat door and change the choosen door to another */
    if(playerChoosen == 0) {
        /* open a goat door, and change the choosen */
        if(doors.doorPresent(1) == GOAT) {
          playerChoosen = 2;
        } else {
          playerChoosen = 1;
        }
    }else if(playerChoosen == 1) {
        if(doors.doorPresent(2) == GOAT) {
          playerChoosen = 0;
        } else {
          playerChoosen = 2;
        }
    }else {
      if(doors.doorPresent(0) == GOAT) {
        playerChoosen = 1;
      } else {
        playerChoosen = 0;
      }
    }
    if(doors.doorPresent(playerChoosen) == CAR) {
      choosenCarDoor++;
    }
  }
  std::cout<<"Probability of choosing car door in changing the door is "<<((double)choosenCarDoor/(double)runs)<<std::endl;

  return 0;
}
