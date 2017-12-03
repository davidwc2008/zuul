//include necessary librarieds
#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

//build the room class here (No private needed)
class Room {
 public:
  Room(int, char *);

  int getID();
  char *getDescription();
  void setExit(int direction, Room *exit);
  Room *getExit(int exit);

  int id;
  char *description;
  map<int, Room *> exits; //use the map function here for exits

};
