// Functions for nateScape

using namespace std;

#include <iostream>
#include <cstdio>
#include <unordered_map>

// Generic Class Template
class Class {

    // Access Specifiers
    private:
        // Private Attributes and Methods
               
    public:
        // Public Attributes and Methods

};


// Class defining the player
class Character {

    // Access Specifiers
    private:
        // Private Attributes
        string name;
        string gender;
        char userGender;
        int room;
        
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

        // initialize properties of player
        void initialize() {
            setGender();
            setName();
            nameGenderCheck();
            setRoom(0);
        }
};

// object for game with helper functions and properties
class Game {

    private:
        int turn = 0; // initial turn is 0
        char action;

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
        };

    public:

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
            cout << "[M]ove to another room."
            cout << "\n";
            // poll the player for the action
            cin >> action;
        }

        // perform the current action based on the room the player is in
        void act(int room_number) {
            // perform the current action
            switch(action) {
                case 'L':
                case 'l':
                    // look around
                    cout << "You look around the room...\n" << endl;
                    describeRoom(room_number);
                    break;
                case 'I':
                case 'i':
                    // Interact with an object
                    cout << "What would you like to interact with?" << endl;
                    cout << "You interact with the object. (Placeholder)\n" << endl;
                    break;
                case 'P':
                case 'p':
                    // Pickup an object
                    cout << "What would you like to pickup?" << endl;
                    cout << "You pickup the object... (Placeholder)\n" << endl;
                    break;
                case 'C':
                case 'c':
                    // Check your bag / inventory
                    cout << "You check your bag... (Placeholder)\n" << endl;
                    cout << "Bag contents:\n" << endl;
                    // print contents of bag
                    //for (auto& x: bag)
                    //    cout << x.first << ": " << x.second << endl;
                    break;
                case 'M':
                case 'm':
                    // move player to an adjacent room
                    cout << "Which room would you like to move to?\n" << endl;
                    cout << "Room options:\n" << endl; 

                    cout << "You move to room" << "insert" << endl;
                    break;
                default:
                    // invalid input
                    cout << "Invalid action." << endl;
                    setAction();
                    act(number);
                    break;
            }
        }

        // describe the room to the player based on where player is
        // calls hashmap of room descriptions
        void describeRoom(int roomNum) {           
            cout << roomDescriptions[roomNum] << endl;
        }

};

// Generic Class Template
class Item {

    // Access Specifiers
    private:
        // Private Attributes and Methods
        float weight;
        
    public:
        // Public Attributes and Methods

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
        Room(int number, string description, bool dark_state, bool chest_state) {
            roomNumber = number;            // define the room number
            roomDescription = description;  // define the room description
            dark = dark_state;              // is the room dark?
            chest = chest_state;            // does the room contain a chest?
            northDoor = nd_state;           // is there a north door
            eastDoor = ed_state;            // is there an east door
            southDoor = sd_state;           // is there a south door
            westDoor = wd_state;            // is there a west door
        }
};

// Creating the room objects

Room Room_Zero (0, roomDescriptions[0],  true,  true);
Room Room_One  (1, roomDescriptions[1],  false, false);
Room Room_Two  (2, roomDescriptions[2],  false, false);
Room Room_Three(3, roomDescriptions[3],  false, true);
Room Room_Four (4, roomDescriptions[4],  false, false);
Room Room_Five (5, roomDescriptions[5],  false, false);
Room Room_Six  (6, roomDescriptions[6],  true,  true);
Room Room_Seven(7, roomDescriptions[7],  false, false);
Room Room_Eight(8, roomDescriptions[8],  false, false);
Room Room_Nine (9, roomDescriptions[9],  false, false);
Room Room_Ten  (10,roomDescriptions[10], false, false);


// hashmap of rooms
//unordered_map<int, Room> roomMap {
//    {0, Room_Zero},
//    {1, Room_One},
//    {2, Room_Two},
//};
