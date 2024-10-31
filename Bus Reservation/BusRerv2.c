// strcpy(login1.uid1, "dev1710");
// strcpy(login1.pass1, "dev@1710");

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ROWS 8
#define COLS 4

char seats[ROWS][COLS];

struct busInfo
{
    char travelName[25];
    int BusNO;
    char BusRoute[20];
    char BusTime[5];
    int tickte;
    char busType[20];
} busInfo1[4];

struct busInfo busInfo1[4] = {
    {"ShivShakti", 1710, "Sngr TO srt", "11:00", 500, "AC Luxury"},
    {"Patel", 1854, "Sngr TO Abd", "10:30", 129, "Express"},
    {"Falcon", 5869, "Sngr TO lmd", "09:30", 29, "Local"},
    {"Patel", 7485, "Sngr TO smnt", "12:00", 800, "Ac Volvo"},
};

struct login
{
    char uid1[15];
    char pass1[10];
    char uid[15];
    char pass[10];
} login1;

struct node
{
    int seat;
    struct node *next;
} *head;

void Businfo()
{
    printf("\n\n");
    printf("--------------------------------------------------------------------------------------------------------------------------\n");
    printf("|  Travelers              |  BusNo   |      BusRoute       |  BusTime   |   Ticket   |      BusType      | ");
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    printf("| 1-> ShivShakti          |  1710    |      Sngr TO srt    |  11:00     |  500       |      AC Luxury    | ");
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    printf("| 2-> Patel               |  1854    |      Sngr TO Abd    |  10:30     |  129       |     Express       | ");
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    printf("| 3-> Falcon              |  5869    |      Sngr TO lmd    |  09:30     |  29        |     Local         | ");
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
    printf("| 4-> Patel               |  7485    |      Sngr TO smnt   |  12:00     |  800       |     Ac Volvo      | ");
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
}

void printBus(char seat[ROWS][COLS])
{
    int seatNum = 1;
    printf("\nBus Seating : \n\n");
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (seat[i][j] == 'X')
            {
                printf(" X  ");
            }
            else
            {
                printf("%02d  ", seatNum);
            }
            seatNum++;
        }
        printf("  ");

        for (int j = 2; j < 4; ++j)
        {
            if (seat[i][j] == 'X')
            {
                printf(" X  ");
            }
            else
            {
                printf("%02d  ", seatNum);
            }
            seatNum++;
        }
        printf("\n");
    }
}

// LINKED LIST FOR SEAT BOOKING
void creationSeatNum(int n)
{
    char sec_seat;
    int i, seatNum;
    struct node *temp, *newnode;

    head = (struct node *)malloc(sizeof(struct node));

    if (seatNum == NULL)
    {
        printf("\n\nLinked List Is Empty");
    }
    else
    {
        printf("\nEnter Seat Num for Passenger  1 : ");
        scanf("%d", &seatNum);
        head->seat = seatNum;
        head->next = NULL;
        temp = head;
        if (seatNum < 1 || seatNum > 32)
        {
            printf("\n\nError ! Enter Valid Seat Number");
        }
        else
        {
            int row = (seatNum - 1) / COLS;
            int cols = (seatNum - 1) % COLS;

            if (seats[row][cols] == 'X')
            {
                printf("\n\nThis Seat Is Alredy Booked");
            }
            else
            {
                seats[row][cols] = 'X';
                printf("\n\n%d Seat Booked", seatNum);
            }
        }
        for (int i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("\nUnable To Allecate");
            }
            else
            {
            again:
                printf("\n\nEnter  Seat Num for Passenger  %d : ", i);
                scanf("%d", &seatNum);
                newnode->seat = seatNum;
                newnode->next = NULL;
                temp->next = newnode;
                temp = temp->next;
                if (seatNum < 1 || seatNum > 32)
                {
                    printf("\n\nError ! Enter Valid Seat Number");
                }
                else
                {
                    int row = (seatNum - 1) / COLS;
                    int cols = (seatNum - 1) % COLS;

                    if (seats[row][cols] == 'X')
                    {
                        printf("\n\nThis Seat Is Alredy Booked");
                        printf("\nDo Want To Book Another Seat ? ( y / n)");
                        scanf("%s", &sec_seat);
                        if (sec_seat = 'y')
                            goto again;
                    }
                    else
                    {
                        seats[row][cols] = 'X';
                        printf("\n\n%d Seat Booked", seatNum);
                    }
                }
            }
        }
    }
    printBus(seats);
}

void display(int trvnum)
{
    int i = 0;
    struct node *temp;
    temp = head;

    printf("\n\n");
    printf("---------------> TICKET <-------------------");
    printf("\n\nBooked Traveles : %d\n", trvnum);
    printf("\n\nBooked Seat Number  : ");

    while (temp != NULL)
    {
        printf(" %d ", temp->seat);
        temp = temp->next;
        i++;
    }
    trvnum--;
    printf("\nBooked Travels Name : %s\n", busInfo1[trvnum].travelName);
    printf("Bus No              : %d\n", busInfo1[trvnum].BusNO);
    printf("Bus Route           : %s\n", busInfo1[trvnum].BusRoute);
    printf("Bus Time            : %s\n", busInfo1[trvnum].BusTime);
    printf("Bus Type            : %s\n", busInfo1[trvnum].busType);
    printf("Bus Ticket          : %d\n", busInfo1[trvnum].tickte);
    printf("Total Ticket        : %d\n", i * busInfo1[trvnum].tickte);

    printf("\n\nNon Refundable Ticket ! T&C Apply \nHappy Journey :)");
    printf("\n--------------------------------------------");
}

void login(struct login login1)
{
    char choz;
    strcpy(login1.uid1, "dev1710");
    strcpy(login1.pass1, "dev@1710");

    do
    {
        printf("Id = ");
        scanf("%s", login1.uid);
        printf("Pass = ");
        scanf("%s", login1.pass);

        int tempID = strcmp(login1.uid1, login1.uid);
        int tempPass = strcmp(login1.pass1, login1.pass);

        // For Check String Lenth For Correct Password
        int temppass1 = strlen(login1.pass);
        int temppass2 = strlen(login1.pass1);

        if (tempID == 0 & temppass1 == temppass2)
        {
            printf("\n\nSuccesfully ! Login ");
        }
        else
        {
            printf("\nError ! Wrong Id Passworld\n");
            printf("\nDo Want To Login Again ? ( y / n)\n\n");
            scanf("%s", &choz);
            printf("\n\n\n");
            if (choz == 'n' || choz == 'Y')
                exit(0);
        }
    } while (choz == 'Y' || choz == 'y');
}

void printHeader()
{
    printf("\n\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
    printf("                                                            BUS RESERVATION SYSTEM\n\n\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
}

int main()
{
    printHeader();

    int n, choz2, choz3; // choz2 == LOGIN and EXITE  , choz3 = Other BOOKING Function

    // printf("\nEnter Number Of Seat : ");
    // scanf("%d",&n);
    printf("\n1 : Login\n2 : Exit\n\n");
    scanf("%d", &choz2);
    printf("\n\n\n");

    switch (choz2)
    {
        // defining variable for folllowing fuctions
        char seat[ROWS][COLS] = {0};
        int seatNum, n, trvnum;
        char againBook, pass_name, pass_age;
    case 1:
        login(login1);
        Businfo();
        printf("\nSelect Your Travels Number : ");
        scanf("%d", &trvnum);
        printBus(seat);
        printf("\n\nEnter Number Of Seats : ");
        scanf("%d", &n);
        creationSeatNum(n);
        display(trvnum);
    case 2:
        exit(0);
        break;

    default:
        printf("\n\nError ! Enter Valid Choice");
        break;
    }
    return 0;
}
