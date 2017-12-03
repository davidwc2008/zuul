//include the appropriate header file
#include "room.h"

using namespace std;

//room constructor
Room:: Room(int _id, char *_description) {
  id = _id;
  description = _description;
}

//get ID method or function
int Room::getID() {
  return id;
}

//get description method or function
char *Room::getDescription() {
  return description;
}

//set exit function
void Room::setExit(int direction, Room *exit) {
  exits[direction] = exit;
}

//get exit function
Room *Room::getExit(int exit) {
  map<int, Room *>::iterator it;
  it = exits.find(exit);

  if (it != exits.end()) {
    return exits.find(exit)->second;
  } else {
    return NULL;
  }
}
