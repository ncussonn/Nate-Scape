// Main Functions for NateScape

using namespace std;

#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <string>
#include <algorithm>

// Generic Class Template
class Class {

    // Access Specifiers
    private:
        // Private Attributes and Methods
               
    public:
        // Public Attributes and Methods

};


// base class defining the player
class Character {

    // Access Specifiers
    private:
        // Private Attributes
        string name;
        string gender;
        char userGender;
        int room;
        vector<string> bag; // ADD INITIAL STARTING ITEMS TO BAG

    public:
        // Public Attributes and Methods

        // Methods
        void setGender() {       

            // Set the gender of the player based on user input
            cout << "What gender are you? Male [m] or Female [f]?"<< endl;
            cin >> userGender;

            if(userGender == 'm') {
                gender = "male";
            } else if(userGender == 'f') {
                gender = "female";
            } else {
                cout << "Invalid gender type." <<  endl;
                setGender();
            }
        }

        // poll player for name, and set it
        void setName() {
            // Set the name of the character based on user input
            cout << "What's your name? (Please type your name)" << endl;
            cin >> name;
        }

        // return the gender of the character as a string
        string getGender() {
            // Get the current gender of the character
            cout << gender << endl;
            return gender;
        }

        // return the name of the character as a string
        string getName() {
            // Get the current name of the character
            cout << name << endl;
            return name;
        }

        // check if name and gender of player were entered correctly
        void nameGenderCheck() {

            cout << "So you're a " << gender << " and your name is " << name <<"? [y/n]" << endl;

            char input;
            cin >> input;

            if(input == 'y') {
                // Proceed
                cout << "Great, let's get going!\n" << endl;
            } else if(input == 'n') {
                // start up sequence again
                cout << "Let's try that again." << endl;
                initialize();
            } else {
                // invalid input
                cout << "Invalid input." << endl;
                nameGenderCheck();
            }
        }
        
        // set the room number of player to new room
        void setRoom(int roomNum) {
            room = roomNum;
        }

        // return the current room of the player as an int
        int getRoom() {
            return room;
        }

        // add an item to the player's bag
        void addToBag(string item) {
            bag.push_back(item);
        }

        // remove an item from the player's bag
        void removeFromBag(string item) {
            // removes all instances of item from bag - may need to be changed
            // slower than finding the item and removing it as it searches entire vector
            // vector size is expected to be small so this implementation will suffice
            bag.erase(remove(bag.begin(), bag.end(), item), bag.end());
            
        }

        // print player bag
        void printBag() {
            cout << "Your bag contains: " << endl;
            for(int i = 0; i < bag.size(); i++) {
                cout << bag[i] << endl;
            }
        }

        // initialize properties of player
        void initialize() {
            setGender();
            setName();
            nameGenderCheck();
            setRoom(0);
        }
};


// base class defining a room
class Room {

    // Access Specifiers
    private:
        // Private Attributes and Methods
        int roomNumber;
        string roomDescription;
        bool dark;
        bool chest;

        // Door possibilities
        bool northDoor;
        bool eastDoor;
        bool southDoor;
        bool westDoor;
        
        // dictionary of objects in room
        unordered_map<string, Item> roomObjects {

        };
        
    public:
        // Public Attributes and Methods

        // Room constructor
        Room(int number, string description, bool dark_state, bool chest_state, bool nd, bool ed, bool sd, bool wd) {
            roomNumber = number;            // define the room number
            roomDescription = description;  // define the room description
            dark = dark_state;              // is the room dark?
            chest = chest_state;            // does the room contain a chest?
            northDoor = nd;                 // is there a north door?
            eastDoor  = ed;                 // is there an east door?
            southDoor = sd;                 // is there a south door?
            westDoor  = wd;                 // is there a west door?
        }
};

// main game class, contains all game logic
class Game {

    private:
        int turn = 0;   // initial turn is 0
        char action;    // current player action as a character

        // REMOVE LATER
        // hashmap of rooms and their descriptions
        unordered_map<int, string> roomDescriptions {
            {0, "The room is pitch black with the exception of a Northern doorway, which shines brightly."},
            {1, "The room's walls are covered in torches. Two doors are on the west and east side of the room. The western door is covered in a blue slime. The eastern door is covered in red slime."},
            {2, "Placeholder"},
            {3, "Placeholder"},
            {4, "Placeholder"},
            {5, "Placeholder"},
            {6, "Placeholder"},
            {7, "Placeholder"},
            {8, "Placeholder"},
            {9, "Boss Room"},
            {10,"Placeholder"}
        };

    public:

        // create global player instance
        Character player;

        // Create all instances of rooms
        Room room1;
        Room room2;
        Room room3;
        Room room4;
        Room room5;
        Room room6;
        Room room7;
        Room room8;
        Room room9;

        // Room hashmap called Rooms
        unordered_map<int, Room> Rooms {
            {1, room1},
            {2, room2},
            {3, room3},
            {4, room4},
            {5, room5},
            {6, room6},
            {7, room7},
            {8, room8},
            {9, room9}
        };

        // generate the rooms
        void generateRooms() {
            // TODO: generate rooms
        }

        // flag to check if the game has been won
        int win_flag = 0;

        // check if the game has been won
        void checkWin() {
            if(win_flag == 1) {
                cout << "You reached the exit!" << endl;
            }
        }

        // print the rules to the player
        void printRules() {
            cout << "Welcome to Nate-scape, a text-based dungeon crawl game. Your objective is to reach the exit of the dungeon. Every action you perform will progress the turn count, with every turn that passes the game will become harder. So choose them wisely!\n" << endl;
        }

        // set the turn count to a specific number
        void setTurn(int turnCount) {
            turn = turnCount;
        }

        // increment the current turn by the amount specified
        void incrementTurn(int increment) {
            for (int i = 0; i < increment; i++) {
                turn++;
            }                    
        }

        // return the current turn as an integer
        int getTurn() {
            return turn;
        }

        // print the current turn to console
        void printTurn() {
            cout << "Current turn: " << turn << endl;
        }

        // set the current action based on user input
        void setAction() {
            // present the player's options
            cout << "What would you like to do?" << endl;
            cout << "[L]ook around the room." << endl;
            cout << "[I]nteract with an object." << endl;
            cout << "[P]ick up an object." << endl;  
            cout << "[C]heck bag." << endl;
            cout << "[M]ove to another room.";
            cout << "\n";

            // poll the player for the action
            cin >> action;
        }

        // add item to player's bag
        void addToBag(Character player, string item) {
            player.addToBag(item);
        }

        // perform the current action based on the room the player is in
        void act(int room_number) {
            // perform the current action
            switch(action) {
                case 'L':
                case 'l':              
                    // Look around
                    cout << "You look around the room...\n" << endl;
                    describeRoom(room_number);
                    break;
                case 'I':
                case 'i':               
                    // Interact with an object
                    cout << "What would you like to interact with?" << endl;
                    cout << "You interact with the object. (Placeholder)\n" << endl;
                    // TO DO
                    break;
                case 'P':
                case 'p':
                    // Pickup an object
                    cout << "What would you like to pickup?" << endl;
                    // PRESENT OBJECTS IN ROOM
                    // TODO
                    string object = "<placeholder>";
                    cout << "You pickup the" << object << "\n" << endl;
                    // Add item to bag
                    addToBag(player, object);
                    break;
                case 'C':
                case 'c':
                    // Check your bag / inventory
                    cout << "You check your bag... (Placeholder)\n" << endl;
                    cout << "Bag contents:\n" << endl;
                    // print contents of inventory
                    player.printBag();
                    break;
                case 'M':
                case 'm':
                    // move player to an adjacent room
                    cout << "Which room would you like to move to?\n" << endl;
                    cout << "Room options:\n" << endl;
                    // TODO: print room options
                    cout << "You move to room" << "<placeholder>" << endl;
                    break;
                default:
                    // invalid input
                    cout << "Invalid action." << endl;
                    setAction();
                    act(room_number);
                    break;
            }
        }
        // describe the room to the player based on where player is
        // calls hashmap of room descriptions
        // TO BE REPLACED WHEN ROOM DESCRIPTION TIED TO ROOM CLASS
        void describeRoom(int roomNum) {           
            cout << roomDescriptions[roomNum] << endl;
        }
};

// Item
class Item {

    // Access Specifiers
    private:
        // Private Attributes and Methods
        float weight;
        
    public:
        // Public Attributes and Methods
        string category;

};

// Creating instances of rooms
Room Room_Zero (0, roomDescriptions[ 0],  true,  true, true, false, false, false, false);
Room Room_One  (1, roomDescriptions[ 1],  false, false);
Room Room_Two  (2, roomDescriptions[ 2],  false, false);
Room Room_Three(3, roomDescriptions[ 3],  false, true);
Room Room_Four (4, roomDescriptions[ 4],  false, false);
Room Room_Five (5, roomDescriptions[ 5],  false, false);
Room Room_Six  (6, roomDescriptions[ 6],  true,  true);
Room Room_Seven(7, roomDescriptions[ 7],  false, false);
Room Room_Eight(8, roomDescriptions[ 8],  false, false);
Room Room_Nine (9, roomDescriptions[ 9],  false, false);
Room Room_Ten  (10,roomDescriptions[10],  false, false);

    Room room1;
    Room room2;
    Room room3;
    Room room4;
    Room room5;
    Room room6;
    Room room7;
    Room room8;
    Room room9;

    // hashmap
    unordered_map<int, Room> Rooms {
        {1, room1},
        {2, room2},
        {3, room3},
        {4, room4},
        {5, room5},
        {6, room6},
        {7, room7},
        {8, room8},
        {9, room9}
    };

    Rooms[0].helloWorld();
    Rooms[1].helloWorld();

    Rooms[0].getDescription();
    Rooms[1].getDescription();
