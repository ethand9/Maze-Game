#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <string>
using namespace std;

const int TOTAL = 8; // total number of rooms

enum Direction
{
    NORTH, EAST, SOUTH, WEST
};

struct room
{
    string roomName = "?"; //Room name
    string roomDesc = "?"; //Room description
    bool visited = false; //If room has been visited
    int roomNum = -1; //Number of the room

    //room*next = NULL;

    room*north = NULL;
    room*east = NULL;
    room*south = NULL;
    room*west = NULL;
};

class location
{
    public:
        location(); //constructor
        virtual ~location(); //destructor

        void createMaze(); //creates maze
        void display(); //display
        void currentLocation();

        bool hasNeighbor(); //Returns true if neighbor in spec dir
        void getNeighbor(); //Returns pointer to neighbor of spec dir
        void setNeighbor(); //Stores indicated location pointer
        bool visit(int roomNum); //Marks a room as visited
        bool isVisited(int roomNum); //Returns true if visited
        bool isExit(int roomNum); //Returns true if current location is exit
        void getName(int roomNum); //Returns name of current location
        void getDescription(int roomNum); //Name, desc, available dir, if visited
        void test0(); //test f(x)

    //protected:

    private:
        room*head;
        room*current;
        room*previous;
        room*last;
        room*temp;
        room*sections[TOTAL+1];
};

#endif // LOCATION_H


