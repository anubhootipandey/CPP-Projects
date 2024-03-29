#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

struct Room {
    int roomNumber;
    bool isOccupied;
    string guestName;
};

// Function to load rooms from file
vector<Room> loadRooms() {
    vector<Room> rooms;
    ifstream inputFile("rooms.txt");
    int roomNumber;
    while (inputFile >> roomNumber) {
        Room room;
        room.roomNumber = roomNumber;
        inputFile >> room.isOccupied;
        if (room.isOccupied) {
            inputFile.ignore(); // Ignore whitespace
            getline(inputFile, room.guestName);
        }
        rooms.push_back(room);
    }
    inputFile.close();
    return rooms;
}

// Function to display available rooms
void displayAvailableRooms(const vector<Room>& rooms) {
    cout << "Available Rooms:\n";
    for (const auto& room : rooms) {
        if (!room.isOccupied) {
            cout << "Room " << room.roomNumber << "\n";
        }
    }
}

// Function to book a room
void bookRoom(vector<Room>& rooms) {
    int roomNumber;
    cout << "Enter room number to book: ";
    cin >> roomNumber;

    for (auto& room : rooms) {
        if (room.roomNumber == roomNumber) {
            if (!room.isOccupied) {
                cout << "Enter guest name: ";
                cin.ignore(); // Ignore newline character
                getline(cin, room.guestName);
                room.isOccupied = true;
                cout << "Room booked successfully!\n";
            } else {
                cout << "Room is already occupied.\n";
            }
            return;
        }
    }

    cout << "Invalid room number.\n";
}

// Function to display occupied rooms
void displayOccupiedRooms(const vector<Room>& rooms) {
    cout << "Occupied Rooms:\n";
    for (const auto& room : rooms) {
        if (room.isOccupied) {
            cout << "Room " << room.roomNumber << " - Guest: " << room.guestName << "\n";
        }
    }
}

// Function to save rooms to file
void saveRooms(const vector<Room>& rooms) {
    ofstream outputFile("rooms.txt");
    for (const auto& room : rooms) {
        outputFile << room.roomNumber << " " << room.isOccupied;
        if (room.isOccupied) {
            outputFile << " " << room.guestName;
        }
        outputFile << "\n";
    }
    outputFile.close();
}

int main() {
    vector<Room> rooms = loadRooms();
    int choice;

    do {
        cout << "\n1. Display Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Display Occupied Rooms\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAvailableRooms(rooms);
                break;
            case 2:
                bookRoom(rooms);
                break;
            case 3:
                displayOccupiedRooms(rooms);
                break;
            case 4:
                saveRooms(rooms); // Save room data before exiting
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
