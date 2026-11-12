#include<stdio.h>

void printPacks()
{
    printf("\n--- Mobile Recharge ---\n");
    printf("1. Rs. 100\n");
    printf("2. Rs. 200\n");
    printf("3. Rs. 500\n");
    printf("4. Rs. 1000\n");
}

int getPackNumber()
{
    int pack;
    printf("Enter pack number (1 to 4): ");
    scanf("%d", &pack);

    while (pack < 1 || pack > 4)
    {
        printf("Invalid! Enter pack number (1 to 4): ");
        scanf("%d", &pack);
    }

    return pack;
}

long long getMobileNumber()
{
    long long mobile;

    printf("Enter mobile number (11 digits): ");
    scanf("%lld", &mobile);

    return mobile;
}

int getAmount(int pack)
{
    int amount;

    switch (pack)
    {
        case 1:
            amount = 100;
            break;
        case 2:
            amount = 200;
            break;
        case 3:
            amount = 500;
            break;
        case 4:
            amount = 1000;
            break;
        default:
            amount = 0;
    }

    return amount;
}

float addTax(int amount)
{
    return amount + amount * 0.15;
}

float getBonus(int amount)
{
    if (amount >= 500)
        return amount * 0.10;
    else
        return 0;
}

void printSlip(long long mobile, int amount, float tax, float balance)
{
    printf("\n------ Recharge Slip ------\n");
    printf("Mobile Number : 0%lld\n", mobile);
    printf("Amount        : Rs. %d\n", amount);
    printf("Tax (15%%)     : Rs. %.2f\n", tax);
    printf("Total Balance : Rs. %.2f\n", balance);
    printf("---------------------------\n");
}

int main()
{
    int i, pack, amount;
    long long mobile;
    float newAmount, tax, bonus, balance;
    float totalSpent = 0;

    for (i = 1; i <= 3; i++)
    {
        printf("\n Recharge %d of 3 \n", i);

        printPacks();
        pack = getPackNumber();
        mobile = getMobileNumber();

        amount = getAmount(pack);
        newAmount = addTax(amount);
        tax = newAmount - amount;
        bonus = getBonus(amount);
        balance = amount + bonus;

        printSlip(mobile, amount, tax, balance);

        totalSpent = totalSpent + newAmount;
    }

    printf("\nTotal money spent: Rs. %.2f\n", totalSpent);

}