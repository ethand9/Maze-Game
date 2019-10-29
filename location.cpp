#include <iostream>
#include "location.h"
using namespace std;

location::location() //constructor
{
    head = NULL;
    current = NULL;
    previous = NULL;
    last = NULL;
    temp = NULL;

    for(int i = 0; i < TOTAL; i++)
    {
        sections[i] = new room;
        sections[i]->roomNum = i;
    }
    sections[TOTAL] = NULL;
}

location::~location() //destructor
{
    current = last->east;
    delete last; //delete surface
    last = current;
    current = current->north;
    delete last; //delete passage
    last = current;
    current = current->west;
    delete last; //delete alcove
    last = current;
    current = current->west;
    delete last; //delete shaft
    last = current;
    current = head->north;
    delete last; //delete pass
    last = current;
    current = head->east;
    delete last; //delete lake shore
    last = current;
    current = head->south;
    delete last; //delete cavern
    last = head;
    current = head;
    delete last; //delete cave

    for(int i = 0; i < TOTAL; i++)
    {
        delete sections[i];
    }
    delete sections[TOTAL];
}

void location::createMaze()
{
    //Set room names
    sections[0]->roomName = "a deep, dark cave. ";
    sections[1]->roomName = "a collapsed cavern. ";
    sections[2]->roomName = "a musty pass. ";
    sections[3]->roomName = "an underground lakeshore. ";
    sections[4]->roomName = "a twisted shaft. ";
    sections[5]->roomName = "a dusty alcove. ";
    sections[6]->roomName = "a passage to the surface. ";
    sections[7]->roomName = "the surface! ";

    //Set room descriptions
    sections[0]->roomDesc = "There is a ray of light emanating from a \n"
        "the large hole in the ceiling from which you fell through and \n"
        "now illuminates the damp mud floor beneath you. You look for a \n"
        "clear path to the surface, but all your options appear the same.\n";
    sections[1]->roomDesc = "The ceiling has collapsed, blocking the tunnel.\n";
    sections[2]->roomDesc = "There is a foul stench from an unknown source \n"
        "polluting the air in this room. Best to move on quickly.\n";
    sections[3]->roomDesc = "You stumble upon a freshwater lake that is\n"
        "teeming with aquatic life.\n";
    sections[4]->roomDesc = "The corridor is riddled with twists and turns and \n"
        "the path continually narrows until finally leading you to the next room.\n";
    sections[5]->roomDesc = "Dust is everywhere making it difficult to breathe, \n"
        "but you power through to the next room.\n";
    sections[6]->roomDesc = "You discover an upwards ramp of earth with sunlight\n"
        "perched at the top of the hallway.\n";
    sections[7]->roomDesc = "You traversed your way out of the maze to safety!\n";

    //Link the rooms with a tree
    head = sections[0];
    current = head;
    temp = sections[1];
    current->south = temp; //cave to collapsed cavern
    temp = sections[2];
    current->north = temp; //cave to musty pass
    temp = sections[3];
    current->east = temp; //cave to lake shore
    current = head->south;
    current->north = head; //cavern to cave
    current = head->north;
    current->south = head; //pass to cave
    temp = sections[4];
    current->east = temp; //pass to shaft
    current = temp;
    current->west = head->north; //shaft to pass
    current->south = head->east; //shaft to lake
    temp = sections[5];
    current->east = temp; //shaft to alcove
    current = temp;
    temp = sections[4];
    current->west = temp; //alcove to shaft
    temp = sections[6];
    current->south = temp; //alcove to passage
    current = temp;
    temp = sections[7];
    last = temp;
    current->west = temp; // passage to surface
    temp = sections[5];
    current->north = temp; //passage to alcove
    temp = sections[7];
    current = temp;
    temp = sections[6];
    current->east = temp; //surface to passage
    current = head->east;
    current->west = head; //lake to cave
    temp = sections[4];
    current->north = temp; //lake to shaft
}

void location::display()
{
    room*read = new room;
    read = head;
}

void location::currentLocation()
{
    char cardinal;
    room*read = new room;
    read = head;
    while(read != NULL)
    {
        cout << "You are in " << read->roomName;
        if(read->visited == false)
            cout << read->roomDesc;
        else
            cout << "This place feels familiar." << endl;

        visit(read->roomNum); // visit the room
        if(isExit(read->roomNum) == false)
        {
            cout << endl << "Enter the direction you want to move (N,E,S,W)." << endl;
            cin >> cardinal;
            cin.get();

            if((cardinal == 'N') || (cardinal == 'n'))
            {
                if(read->north != NULL)
                {
                    read = read->north;
                    cout << endl;
                }
                else
                    cout << endl << "There is no room to the north." << endl;
            }
            else if((cardinal == 'E') || (cardinal == 'e'))
            {
                if(read->east != NULL)
                {
                    read = read->east;
                    cout << endl;
                }
                else
                    cout << endl << "There is no room to the east." << endl;
            }
            else if((cardinal == 'S') || (cardinal == 's'))
            {
                if(read->south != NULL)
                {
                    read = read->south;
                    cout << endl;
                }
                else
                    cout << endl << "There is no room to the south." << endl;
            }
            else if((cardinal == 'W') || (cardinal == 'w'))
            {
                if(read->west != NULL)
                {
                    read = read->west;
                    cout << endl;
                }
                else
                    cout << endl << "There is no room to the west." << endl;
            }
            else
            {
                cout << "That is not a valid direction." << endl;
            }
        }
        else
            read = NULL;
    }
}

bool location::hasNeighbor()
{

}

void location::getNeighbor()
{

}

void location::setNeighbor()
{

}

bool location::visit(int roomNum)
{
    //cout << sections[roomNum]->roomName << " has been visited" << endl;
    sections[roomNum]->visited = true;
}

bool location::isVisited(int roomNum)
{

}

bool location::isExit(int roomNum)
{
    if(roomNum == 7)
        return true;
    else
        return false;
}

void location::getName(int roomNum)
{
    cout << sections[roomNum]->roomName << endl;
}

void location::getDescription(int roomNum)
{
    cout << sections[roomNum]->roomDesc << endl;
}

void location::test0()
{
    cout << "This "
        "is "
        "a test" << endl;
}


