#include <iostream>
#include <vector>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

class Booking {
public:
    string memberName;
    int slot;

    Booking(string memberName, int slot) : memberName(memberName), slot(slot) {}
};

class FitnessClass {
private:
    string className;
    int totalSlots;
    vector<Booking> bookings;

public:
    FitnessClass(std::string className, int totalSlots) : className(className), totalSlots(totalSlots) {}

    bool isSlotAvailable() {
        return bookings.size() < totalSlots;
    }

    bool bookSlot(std::string memberName) {
        if (!isSlotAvailable()) {
            cout << "No available slots for " << className << ".\n";
            return false;
        }

        for (const auto& booking : bookings) {
            if (booking.memberName == memberName) {
                cout << "You have already booked a slot for " << className << ".\n";
                return false;
            }
        }

        bookings.push_back(Booking(memberName, bookings.size() + 1));
        cout << "Booking successful for " << memberName << " in " << className << ".\n";
        return true;
    }

    bool cancelBooking(std::string memberName) {
        for (auto it = bookings.begin(); it != bookings.end(); ++it) {
            if (it->memberName == memberName) {
                bookings.erase(it);
                cout << "Booking canceled for " << memberName << " in " << className << ".\n";
                return true;
            }
        }
        cout << "No booking found for " << memberName << " in " << className << ".\n";
        return false;
    }

    void printBookings() {
        for (const auto& booking : bookings) {
            cout << "Member: " << booking.memberName << ", Slot: " << booking.slot << std::endl;
        }
    }
};

int main() {
    int userChoice;
    cout << "Enter the number of slots for gym: ";
    cin >> userChoice;
    FitnessClass gym("Gym", userChoice);  // Created a fitness class according to users choice slots
    int choice;
    string memberName;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do {
        cout << "Menu:\n";
        cout << "1. Book a slot\n";
        cout << "2. Cancel booking\n";
        cout << "3. View bookings\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

        switch (choice) {
        case 1:
            cout << "Enter your name: ";
            getline(cin, memberName);
            gym.bookSlot(memberName);
            break;
        case 2:
            cout << "Enter your name to cancel booking: ";
            getline(cin, memberName);
            gym.cancelBooking(memberName);
            break;
        case 3:
            gym.printBookings();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
