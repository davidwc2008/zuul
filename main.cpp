#include "room.h"

using namespace std;

struct Item {
  char item_name[50];
  char item_description[100];
  Room *item_location;
};

void createItem(char *name, char *description, Room *location);
vector <Item> items;
vector <Room*> rooms;

int main() {
  int C; // counter
  char command[100];

  //directions (up and down refer to y-axis movement)
  bool n;
  bool e;
  bool s;
  bool w;
  bool up;
  bool down;

  //Rooms
  Room* player = new Room(0, "the character's inventory");
  Room* apple = new Room(1, "a room with many apple trees");
  Room* banana = new Room(2, "a room filled with yellow goo");
  Room* cherry = new Room(3, "a room titled cherry");
  Room* dates = new Room(4, "a room titled dates and it is very romantic");
  Room* eggplant = new Room(5, "the eggplant room");
  Room* fig = new Room(6, "a room filled with fresh and dried figs");
  Room* grape = new Room(7, "the grape room.  Welcome to wine country");
  Room* horseradish = new Room(8, "the horseradish room, also known as wasabi corner");
  Room* imbe = new Room(9, "a room titled imbe");
  Room* jackfruit = new Room(10, "a room titled jackfruit");
  Room* kiwi = new Room(11, "a room with kiwis as lights");
  Room* lime = new Room(12, "a room with limes everywhere");
  Room* mango = new Room(13, "a room with mangos splattered on the wall");
  Room* nectarine = new Room(14, "a room where the seed of nectarines can be found in every corner");
  Room* orange = new Room(15, "the orange room");

  //Items
  createItem("a cool bike", "This is the world's first foldable bike.", apple);
  //createItem("The iPhone X", "This is the new iPhone.", banana);
  //createItem("Cheese and crackers", "The most delicious snack!", cherry);
  createItem("the mona lisa painting", "This is the world's most valuable painting.", dates);
  //createItem("A pine cone", "It is pretty anticlimactic.", eggplant);
  //createItem("Headphones", "Listen to the best sounds.", fig);
  createItem("the statue of liberty", "This is a gift from the French people.", grape);
  //createItem("The Moon", "Never did you think you could capture the moon... until now", horseradish);
  //no item for imbe because it is the lose condition
  //createItem("A cool bike", "This is the world's first foldable bike.", imbe);
  //createItem("A USB", "Store all the information you want.", jackfruit);
  //createItem("Pizza from Italy", "Dozens of varieties for your chosing.", kiwi);
  createItem("teddy bear", "His name is Ted.", lime);
  //createItem("Chocolate", "Hersheys, almond joy, reces pieces...", mango);
  //createItem("Rolex watch", "This watch is worth five million US dollars.", nectarine);
  createItem("treasure chest", "Contains highly valued metals including gold and silver.", orange);

  //Player
  createItem("you", "You are the player!", apple);

  //Exits for every room (let us make 1=n, 2=s, 3-w, 4=e, 5=up, 6=down)
  //apple
  apple->setExit(3, banana);
  apple->setExit(1, cherry);
  //banana
  banana->setExit(4, apple);
  banana->setExit(3, lime);
  banana->setExit(6, nectarine);
  //cherry
  cherry->setExit(5, dates);
  cherry->setExit(2, apple);
  //dates
  dates->setExit(6, cherry);
  dates->setExit(3, eggplant);
  //eggplant
  eggplant->setExit(4, dates);
  //fig
  fig->setExit(5, nectarine);
  fig->setExit(3, mango);
  fig->setExit(4, orange);
  //grape
  grape->setExit(4, mango);
  grape->setExit(5, kiwi);
  //horseradish
  horseradish->setExit(6, jackfruit);
  //imbe - no exits; player loses
  //jackfruit
  jackfruit->setExit(3, orange);
  jackfruit->setExit(4, imbe);
  jackfruit->setExit(5, horseradish);
  //kiwi
  kiwi->setExit(6, grape);
  kiwi->setExit(1, lime);
  //lime
  lime->setExit(2, kiwi);
  lime->setExit(4, banana);
  //mango
  mango->setExit(3, grape);
  mango->setExit(4, fig);
  //nectarine
  nectarine->setExit(5, banana);
  nectarine->setExit(6, fig);
  //orange
  orange->setExit(3, fig);
  orange->setExit(4, jackfruit);

  //start the game for the user
  cout << "Welcome.  This is the Zuul Game: Fruit Edition." << endl;
  cout << "The objective of this game is to collect all 5 items before getting trapped in the special trap room.  Good luck!" << endl;

  while ((items[0].item_location != player) || (items[1].item_location != player) || (items[2].item_location != player) || (items[3].item_location != player) || (items[4].item_location !=player)) {
    C = 0;

    //location
    cout <<"You are in " << (items[5].item_location)->description << "." << endl;

    //If the user enters imbe, exit routine will begin.
    if (strcmp((items[5].item_location)->description, "a room titled imbe") == 0) {
      cout << "There is no exit to this room.  You lose." << endl;
      return 0;
    }

    //list items
    cout << "Available items: "<< endl;
    for (int i = 0; i < 5; i++) {
      if (items[i].item_location == items[5].item_location) {
	cout << items[i].item_name << " - " << items[i].item_description << endl;
	C++;
      }
    }
    if (C == 0) {
      cout << "NONE" << endl;
    }

    //output exits
    cout << "Available exits: " << endl;
    if ((items[5].item_location)->getExit(1) != NULL) {
      cout << "NORTH" << endl;
      n = true;
    } else {
      n = false;
    }
    if ((items[5].item_location)->getExit(2) != NULL) {
      cout << "SOUTH" << endl;
      s = true;
    } else {
      s = false;
    }
    if ((items[5].item_location)->getExit(3) != NULL) {
      cout << "WEST" << endl;
      w = true;
    } else {
      w = false;
    }
    if ((items[5].item_location)->getExit(4) != NULL) {
      cout << "EAST" << endl;
      e = true;
    } else {
      e = false;
    }
    if ((items[5].item_location)->getExit(5) != NULL) {
      cout << "UP" << endl;
      up = true;
    } else {
      up = false;
    }
    if ((items[5].item_location)->getExit(6) != NULL) {
      cout << "DOWN" << endl;
      down = true;
    } else {
      down = false;
    }

    //Input commands from the user for interaction
    cout << "Enter command (GO, INVENTORY, GET, DROP, QUIT): "<< endl;
    cin.getline(command, 30);
    //makes initial command lowercase
    for (int i = 0; i < strlen(command); i++) {
      command[i] = tolower(command[i]);
    }

    //quit command
    if (strcmp(command, "quit") == 0) {
      cout << "Goodbye" << endl;
      return 0;
    }

    //go command
    if (strcmp(command,"go") == 0) {
      cout << "Which exit?" << endl;
      cin.getline(command, 20);
      for (int i = 0; i < strlen(command); i++) {
	command[i] = tolower(command[i]);
      }
      if (strcmp(command, "north") == 0 && n) {
	items[5].item_location = items[5].item_location->getExit(1);
      } else if (strcmp(command, "south") == 0 && s) {
        items[5].item_location = items[5].item_location->getExit(2);
      } else if (strcmp(command, "west") == 0 && w) {
        items[5].item_location = items[5].item_location->getExit(3);
      } else if (strcmp(command, "east") == 0 && e) {
        items[5].item_location = items[5].item_location->getExit(4);
      } else if (strcmp(command, "up") == 0 && up) {
        items[5].item_location = items[5].item_location->getExit(5);
      } else if (strcmp(command, "down") == 0 && down) {
        items[5].item_location = items[5].item_location->getExit(6);
      } else {
	cout << "Exit not valid." << endl;
      }
    }

    //pick up and put in inventory command (get)
    if (strcmp(command, "get") == 0) {
      C = 0;
      int i;
      cout << "Which item? (Name is before the hyphen)" << endl;
      cin.getline(command, 80);
      for (i = 0; i < strlen(command); i++) {
	command[i] = tolower(command[i]);
      } //for

      for (i = 0; i < 5; i++) {
	if (items[i].item_location == items[5].item_location) {
	  C = 1;
	  break;
	}
      }

      
      if ((i == 4) && (C != 1)) {
	cout << "Error 1." << endl;
      }
      
      if (C == 1) {
	if (strcmp(command, items[i].item_name) == 0) {
	  items[i].item_location = player;
	} else {
	  cout << i << endl;
	  cout << "Error 2." << endl;
	}
      } 
    }
    
    //the original X method did not work because it just does not take into account the effect of drop and pick up
    
    //display what is inside inventory

    if (strcmp(command, "inventory") == 0) {
      cout << "Your inventory: " << endl;
      C = 0;
      for (int i = 0; i < 5; i++) {
	if (items[i].item_location == player) {
	  cout << " - " << items[i].item_name << endl;
	  C++;
	}
      }
      if (C == 0) {
	cout << "NONE" << endl;
      }
    }

    //drop command

    if (strcmp(command, "drop") == 0) {
      cout << "Type the item name: " << endl;
      cin.getline(command, 81);

      for (int i = 0; i < strlen(command); i++) {
	command[i] = tolower(command[i]);
      }

      for (int i = 0; i < 5; i++) {
	if (items[i].item_location == player) {
	  if (strcmp(command, items[i].item_name) == 0) {
	    items[i].item_location = items[5].item_location;
	  }
	}
      }
    }
  }
  cout << "You won.  Congratulations." << endl;
  return 0;
}

void createItem(char *name, char *description, Room *location) {
  Item i;
  strcpy(i.item_name, name);
  strcpy(i.item_description, description);
  i.item_location = location;

  items.push_back(i);
}
