#include <stdio.h>

void printRules()
{
    printf("===== TAXI FARE CALCULATOR =====\n");
    printf("Base fare: Rs. 150\n");
    printf("Rs. 60 per km for the first 10 km\n");
    printf("Rs. 45 per km after 10 km\n");
    printf("Waiting: first 5 minutes free, then Rs. 10 per minute\n");
    printf("Night charge (10 PM to 6 AM): +25%%\n\n");
}

float getDistance()
{
    float distance;
    printf("Enter distance in km (1 to 200): ");
    scanf("%f", &distance);
    while (distance <= 0 || distance > 200)
    {
        printf("Invalid! Enter distance again: ");
        scanf("%f", &distance);
    }
    return distance;
}

int getWaitingTime()
{
    int wait;
    printf("Enter waiting time in minutes (0 to 120): ");
    scanf("%d", &wait);
    while (wait < 0 || wait > 120)
    {
        printf("Invalid! Enter waiting time again: ");
        scanf("%d", &wait);
    }
    return wait;
}

float distanceCharge(float distance)
{
    if (distance <= 10)
    {
        return distance * 60;
    }
    else
    {
        return 10 * 60 + (distance - 10) * 45;
    }
}

float waitingCharge(int wait)
{
    if (wait <= 5)
    {
        return 0;
    }
    else
    {
        return (wait - 5) * 10;
    }
}

float addNightCharge(float fare)
{
    int hour;
    printf("Enter hour of the trip (0 to 23): ");
    scanf("%d", &hour);
    while (hour < 0 || hour > 23)
    {
        printf("Invalid! Enter hour again: ");
        scanf("%d", &hour);
    }

    if (hour >= 22 || hour < 6)
    {
        fare = fare + fare * 0.25;
    }

    return fare;
}

void printReceipt(float distance, int wait, float fare)
{
    printf("\n----- TRIP RECEIPT -----\n");
    printf("Distance     : %.2f km\n", distance);
    printf("Waiting time : %d minutes\n", wait);
    printf("Final fare   : Rs. %.2f\n", fare);
}

int main()
{
    float distance, fare;
    int wait;
    float total = 0;
    float highest = 0;
    int i;

    printRules();

    for (i = 1; i <= 3; i++)
    {
        printf("--- Trip %d ---\n", i);

        distance = getDistance();
        wait = getWaitingTime();

        fare = 150 + distanceCharge(distance) + waitingCharge(wait);
        fare = addNightCharge(fare);

        printReceipt(distance, wait, fare);

        total = total + fare;
        if (fare > highest)
        {
            highest = fare;
        }
    }

    printf("Total earnings of the day: Rs. %.2f\n", total);
    printf("Highest fare of the day  : Rs. %.2f\n", highest);

}