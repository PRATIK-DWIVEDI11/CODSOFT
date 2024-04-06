#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Movie {
public:
    string title;
    string director;
    int duration; 

    Movie(string title, string director, int duration)
        : title(title), director(director), duration(duration) {}
};

class Seat {
public:
    int row;
    char seatNumber;
    bool available;

    Seat(int row, char seatNumber) : row(row), seatNumber(seatNumber), available(true) {}

    void book() {
        available = false;
    }

    void cancelBooking() {
        available = true;
    }
};

class Theater {
public:
    int capacity;
    vector<vector<Seat>> seats;

    Theater(int rows, int seatsPerRow) : capacity(rows * seatsPerRow) {
        for (int i = 0; i < rows; ++i) {
            vector<Seat> rowSeats;
            for (char seatNumber = 'A'; seatNumber < 'A' + seatsPerRow; ++seatNumber) {
                rowSeats.push_back(Seat(i + 1, seatNumber));
            }
            seats.push_back(rowSeats);
        }
    }

    bool isSeatAvailable(int row, char seatNumber) {
        return seats[row - 1][seatNumber - 'A'].available;
    }

    void bookSeat(int row, char seatNumber) {
        seats[row - 1][seatNumber - 'A'].book();
    }

    void cancelBooking(int row, char seatNumber) {
        seats[row - 1][seatNumber - 'A'].cancelBooking();
    }
};

class Booking {
public:
    Movie movie;
    int numTickets;
    int totalCost;

    Booking(Movie movie, int numTickets) : movie(movie), numTickets(numTickets) {
        totalCost = numTickets * 10; 
    }
};

int main() {
    
    Movie movie1("MS Dhoni: The Untold Story", "Neeraj Pandey", 148);
    Movie movie2("3 Idiots", "Rajkumar Hirani", 142);

    
    Theater theater(5, 10); 
    
    Booking booking(movie1, 3);

    cout << "Welcome to the Movie Ticket Booking System\n";
    cout << "Available Movies:\n";
    cout << "1. " << movie1.title << " (" << movie1.director << ")\n";
    cout << "2. " << movie2.title << " (" << movie2.director << ")\n";

    int selectedMovie;
    cout << "Select a movie (1-2): ";
    cin >> selectedMovie;

    int selectedRow;
    char selectedSeat;
    cout << "Enter desired row (1-5): ";
    cin >> selectedRow;
    cout << "Enter desired seat (A-J): ";
    cin >> selectedSeat;

    if (theater.isSeatAvailable(selectedRow, selectedSeat)) {
        theater.bookSeat(selectedRow, selectedSeat);
        cout << "Booking successful!\n";
        cout << "Total cost: $" << booking.totalCost << endl;
    } else {
        cout << "Sorry, the seat is already booked. Please select another seat.\n";
    }

    return 0;
}
