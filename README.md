Bus Information Display (Businfo function):

Displays a table of available buses with details such as travel name, bus number, route, departure time, ticket price, and bus type.
The table is presented in a structured format using hardcoded data.
Bus Seating Layout Display (printBus function):

Displays the current seating arrangement of the bus with 32 seats arranged in an 8x4 grid (8 rows and 4 columns).
Seats are marked with seat numbers unless they are already booked, in which case they are marked with "X".
Seat Booking System using Linked List (creationSeatNum function):

Manages seat bookings by prompting the user to enter seat numbers for booking.
Uses a linked list to store each booked seat number as a node.
Checks if the seat number is valid (1 to 32) and if the seat is already booked.
If a seat is already booked, it prompts the user to book a different seat.
Marks seats as booked by updating the seats array with "X" for each booked seat.
Ticket Display (display function):

After booking, displays ticket details including:
Number of seats booked
List of booked seat numbers
Travel name, bus number, route, departure time, bus type, ticket price, and total cost.
Includes a non-refundable ticket notice.
User Login System (login function):

Implements a simple login system that verifies user credentials.
Hardcoded credentials (uid1 and pass1) are used for login verification.
If the entered credentials match, the user is logged in; otherwise, it allows the user to retry or exit.
Checks string length for password comparison as a security measure.
Header Display (printHeader function):

Displays a formatted header for the "Bus Reservation System" application.
Main Function (main):

Acts as the entry point for the application.
Shows a menu with options to "Login" or "Exit."
After successful login, the user can:
View available bus information.
Choose a bus for booking by entering its number.
Display the seating layout.
Specify the number of seats to book.
Initiate seat booking through the creationSeatNum function.
View the ticket after booking using the display function.
If the user chooses "Exit," the program terminates.
Additional Details:
Structures and Data Definitions:

struct busInfo: Defines information about each bus, such as travel name, bus number, route, time, ticket price, and bus type.
struct login: Holds the login credentials for the user.
struct node: Used for creating a linked list to manage booked seat numbers.
Hardcoded Bus Data:

An array of busInfo structures initializes information about four buses, each with unique properties.
Seat Status Tracking (seats array):

The seats 2D array maintains the booking status of each seat, where "X" denotes a booked seat and an empty value denotes an available seat.
Overall, the program provides a basic simulation of a bus reservation system with features for viewing bus details, logging in, selecting and booking seats, and displaying ticket details.
