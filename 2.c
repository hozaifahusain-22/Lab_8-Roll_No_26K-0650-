#include <stdio.h>

void print_info(void)
{
    printf("===== City Hospital =====\n");
    printf("1. General Ward : Rs. 1500/day\n");
    printf("2. Semi-Private : Rs. 3500/day\n");
    printf("3. Private      : Rs. 6000/day\n");
}

int get_room_type(void)
{
    int type;
    printf("Enter room type (1, 2 or 3): ");
    scanf("%d", &type);
    return type;
}

int get_days(void)
{
    int days;
    printf("Enter days stayed (1 to 30): ");
    scanf("%d", &days);
    return days;
}

float room_charges(int type, int days)
{
    if (type == 1)
    {
        return 1500 * days;
    }

    else if (type == 2)
    {
        return 3500 * days;
    }

    else
    {
        return 6000 * days;
    }
}

float medicine_charge(float medicine)
{
    return medicine * 1.05;
}

float final_amount(float total, int days)
{
    if (days >= 7)
    {
        return total * 0.92;
    }
    else
    {
        return total;
    }
}

void print_bill(int type, int days, float room, float medicine, float final)
{
    printf("\n===== FINAL BILL =====\n");
    if (type == 1)
    {
        printf("Room Name: General Ward\n");
    }

    else if (type == 2)
    {
        printf("Room Name: Semi-Private\n");
    }
    else
    {
        printf("Room Name: Private\n");
    }
    printf("Days Stayed      : %d\n", days);
    printf("Room Charges     : Rs. %.2f\n", room);
    printf("Medicine Charges : Rs. %.2f\n", medicine);
    printf("Final Amount     : Rs. %.2f\n", final);
}

int main()
{
    int type, days;
    float medicine, room, final;
    char senior;

    print_info();
    type = get_room_type();
    days = get_days();

    room = room_charges(type, days);

    printf("Enter medicine bill: ");
    scanf("%f", &medicine);
    medicine = medicine_charge(medicine);

    final = final_amount(room + medicine, days);

    printf("Is the patient a senior citizen? (y/n): ");
    scanf(" %c", &senior);
    if (senior == 'y')
    {
        final = final - 1000;
    }
    if (final < 0)
    {
       final = 0;
    }

    print_bill(type, days, room, medicine, final);

}