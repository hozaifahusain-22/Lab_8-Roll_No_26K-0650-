#include <stdio.h>

void printRoutes()
{
    printf("===== BUS TICKET BOOKING =====\n");
    printf("1. Karachi to Hyderabad - Rs. 800\n");
    printf("2. Karachi to Sukkur    - Rs. 2200\n");
    printf("3. Karachi to Multan    - Rs. 3500\n");
}

void getRoute(int *route)
{
    printf("Enter route number (1-3): ");
    scanf("%d", route);
    while (*route < 1 || *route > 3)
    {
        printf("Invalid! Enter route number (1-3): ");
        scanf("%d", route);
    }
}

void getSeats(int *seats)
{
    printf("Enter number of seats (1-6): ");
    scanf("%d", seats);
    while (*seats < 1 || *seats > 6)
    {
        printf("Invalid! Enter number of seats (1-6): ");
        scanf("%d", seats);
    }
}

int getSeatFare(int route)
{
    if (route == 1)
    {
        return 800;
    }
    else if (route == 2)
    {
        return 2200;
    }
    else
    {
        return 3500;
    }
}

int getTotalFare(int seatFare, int seats)
{
    return seatFare * seats;
}

float addSeatTypeCharge(int total, char type)
{
    if (type == 'B')
    {
        return total + total * 0.30;
    }
    else
    {
        return total;
    }
}

void printTicket(int route, int seats, char type, float finalFare)
{
    printf("\n------ TICKET ------\n");
    if (route == 1)
    {
        printf("Route: Karachi to Hyderabad\n");
    }
    else if (route == 2)
    {
        printf("Route: Karachi to Sukkur\n");
    }
    else
    {
        printf("Route: Karachi to Multan\n");
    }

    printf("Seats: %d\n", seats);

    if (type == 'B')
    {
        printf("Seat Type: Business\n");
    }
    else
    {
        printf("Seat Type: Economy\n");
    }

    printf("Fare: Rs. %.2f\n", finalFare);
}

int main()
{
    int route, seats, seatFare, total, i;
    char type;
    float finalFare;
    float earnings = 0;

    for (i = 1; i <= 2; i++)
    {
        printf("\n*** Passenger %d ***\n", i);

        printRoutes();
        getRoute(&route);
        getSeats(&seats);

        printf("Seat type - Economy (E) or Business (B): ");
        scanf(" %c", &type);

        seatFare = getSeatFare(route);
        total = getTotalFare(seatFare, seats);
        finalFare = addSeatTypeCharge(total, type);

        printTicket(route, seats, type, finalFare);

        earnings = earnings + finalFare;
    }

    printf("Total earnings of the bus company: Rs. %.2f\n", earnings);

}