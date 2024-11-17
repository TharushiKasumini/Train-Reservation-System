#include <stdio.h>

// Define the train size
#define SIZE 100

// Define the index of the train details
int index = 0;

// Define arrays for store differnet information
// variable names are :- Train number, train name, driver name, destination, ticket price, reserved ticket count, apartment details
int trainNum[SIZE];
char trainName[SIZE][30];
char driver[SIZE][30];
char destination[SIZE][30];
double ticketPrice[SIZE];
int reserved[SIZE];
int apartments[SIZE][10];

// Function prototypes
void getDetails();
double expectedIncome(int trainNumber);
int availableSeats(int trainNumber);
void acceptPrice(int trainNumber);
void reserveTickets();
void setApartments(int trainNumber);
void viewDetails(int trainNumber);
void setReserved(int trainNumber);

int main(){

    int option = 10;

    while(option!=0){

        printf("\n");
        printf("Enter your option\n");
        printf("=================\n");
        printf("1. Enter train details\n");
        printf("2. Enter apartment capacities\n");
        printf("3. Set amount of reserved tickets\n");
        printf("4. Get expected income\n");
        printf("5. Get available seats\n");
        printf("6. Check reservation\n");
        printf("7. Set new ticket price\n");
        printf("8. View train details\n");
        printf("0. Exit\n");
        printf("=================\n");

        scanf("%d", &option);

        // Switch case variables
        int numApart;
        int numIncome;
        int numAvailable;
        int numTicket;
        int numDetails;
        int numReserved;

        switch (option)
        {
        case 1:
            getDetails();
            break;
            
        case 2:
            // int numApart;
            printf("Enter Train Number : ");
            scanf("%d", &numApart);
            setApartments(numApart);
            break;

        case 3:
            // int numApart;
            printf("Enter Train Number : ");
            scanf("%d", &numReserved);
            setReserved(numReserved);
            break;

        case 4:
            // int numIncome;
            printf("Enter Train Number : ");
            scanf("%d", &numIncome);
            double resultIncome = expectedIncome(numIncome);

            // Error handling and printing
            if(resultIncome==-1){
                printf("Invalid train number\n");
            }
            else{
                printf("Expected Income = %.2f\n", resultIncome);
            }
            break;

        case 5:
            // int numAvailable;
            printf("Enter Train Number : ");
            scanf("%d", &numAvailable);
            int availableresult = availableSeats(numAvailable);

            // Error handling and printing
            if(availableresult==-1){
                printf("Invalid train number\n");
            }
            else{
                printf("Available Seats = %d\n", availableresult);
            }
            break;

        case 6:
            reserveTickets();
            break;
            
        case 7:
            // int numTicket;
            printf("Enter Train Number : ");
            scanf("%d", &numTicket);
            acceptPrice(numTicket);
            break;

        case 8:
            // int numDetails;
            printf("Enter Train Number : ");
            scanf("%d", &numDetails);
            viewDetails(numDetails);
            break;

        case 0:
            break;          
        
        default:
            break;
        }
    }
    
    return 0;
}

// Function 1: Get user inputs
void getDetails(){

    // Prompt for details and input them in arrays
    // Train number
    printf("Enter train number: ");
    scanf("%d", &trainNum[index]);

    // Train name
    printf("Enter train name: ");
    scanf("%s", trainName[index]);

    // Driver name
    printf("Enter driver name: ");
    scanf("%s", driver[index]);

    // Destination
    printf("Enter destination: ");
    scanf("%s", destination[index]);

    // ticket price
    printf("Enter ticket price: ");
    scanf("%lf", &ticketPrice[index]);

    // Increase the index
    index++;
}

// Function 2
// Display income as expected
// This function requires train number as input
double expectedIncome(int trainNumber){

    // Variable for get location in array
    int location=-1;

    // Find the index of train number
    for(int j=0; j<SIZE; j++){
        if(trainNum[j]==trainNumber){
            location=j;
        }
    }

    // Int sum of capacity
    int capacity = 0;

    // Scan for 10 appartments
    for(int i=0; i<10; i++){
        // Calculate the capacity
        capacity += apartments[location][i];
    }

    // Calculate the expected income
    double income = capacity*ticketPrice[location];

    // retrun the expected income
    return income;
}


// Function 3
// Function to return available
int availableSeats(int trainNumber){

    // Variable for get location in array
    int location = -1;

    // Find the index of train number
    for(int j=0; j<SIZE; j++){
        if(trainNum[j]==trainNumber){
            location=j;
        }
    }

    if(location==-1){
        return -1;
    }

    else{
        // Get the total seats
        int total= 0;

        // Scan for 10 appartments
        for(int i=0; i<10; i++){
            total += apartments[location][i];
        }

        // Available seats
        int available = total - reserved[location];
        
        // return number of seats
        return available;
    }
}


// Function 4
void reserveTickets(){

    // Get this according to train number
    printf("Enter train number: ");
    int train;
    scanf("%d", &train);

    // Variable for get location in array
    int location = -1;

    // Find the index of train number
    for(int j=0; j<SIZE; j++){
        if(trainNum[j]==train){
            location=j;
        }
    }

    // Error if train is not found
    if(location==-1){
        printf("Invalid train number\n");
    }

    else{
        
        // Get the number of tickets to be reserved
        int numberOfTickets;
        printf("Enter number of tickets: ");
        scanf("%d", &numberOfTickets);

        // Conditioning for available seats
        int seats = availableSeats(train);

        if(seats < numberOfTickets){
            printf("Sorry, There are no seats available for required number of tickets!\n");
        }

        else{
            printf("Required number of tickets are avaialbe.\n");
        }
    }
}


// Function 5
void acceptPrice(int trainNumber){

    // get the location
    // Variable for get location in array
    int location = -1;

    // Find the index of train number
    for(int j=0; j<SIZE; j++){
        if(trainNum[j]==trainNumber){
            location=j;
        }
    }

    // Error handling
    if(location==-1){
        printf("Invalid train number\n");
    }

    else{
        // Prompt for new price
        double newPrice;
        printf("Enter new ticket price: ");
        scanf("%lf", &newPrice);

        // Set new price in array
        ticketPrice[location] = newPrice;

        // Show new expected income
        double newIncome = expectedIncome(trainNumber);

        // Printing result
        printf("New ticket price is %.2f\n", newPrice);
        printf("New expected income = %.2f\n", newIncome);
    }
}


// extra function
// This function set capacities for each apartments
void setApartments(int trainNumber){

    // Variable for get location in array
    int location = -1;

    // Find the index of train number
    for(int j=0; j<SIZE; j++){
        if(trainNum[j]==trainNumber){
            location=j;
        }
    }

    if(location==-1){
        printf("Invalid train number!\n");
    }

    else{
        // Scan for 10 appartments
        for(int i=0; i<10; i++){
            int input;
            printf("Enter capacity for appartment %d: ", (i+1));
            scanf("%d", &input);

            // Set capacities
            apartments[location][i] = input;
        }
    }
}


// Extra function for view train details
void viewDetails(int trainNumber){

    // Variable for get location in array
    int location = -1;

    // Find the index of train number
    for(int j=0; j<SIZE; j++){
        if(trainNum[j]==trainNumber){
            location=j;
        }
    }

    // error checking
    if(location==-1){
        printf("Invalid train number\n");
    }

    else{
        printf("Train Name - %s\n", trainName[location]);
        printf("Destination - %s\n", destination[location]);
        printf("Driver - %s\n", driver[location]);
        printf("Price for a passenger - %.2f\n", ticketPrice[location]);
        printf("Reserved tickets  - %d\n", reserved[location]);
    }
}

// Function for set reserved tickets
void setReserved(int trainNumber){

    // Variable for get location in array
    int location = -1;

    // Find the index of train number
    for(int j=0; j<SIZE; j++){
        if(trainNum[j]==trainNumber){
            location=j;
        }
    }

    // error checking
    if(location==-1){
        printf("Invalid train number\n");
    }

    else{
        int ticketCount;
        printf("Enter number of reserved tickets: ");
        scanf("%d", &ticketCount);
        reserved[location] = ticketCount;
        printf("Reserved number of ticktes for train %s is %d.\n", trainName[location], ticketCount);
        
    }

}
