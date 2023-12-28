#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initial File :D
struct products 
{
    int quantity; // Quantity
    char name[20]; // Product name
    float price; // Product price per piece
};


struct products prod[30]; // Array elements
int count = 0;
FILE *f; // File pointer
int writeFile()// Write file function
{
    int i;
    f = fopen("inventory.txt", "w"); 
    if (f == NULL)
        return -1;			
    fprintf(f, "%d\n", count);
    for (i = 0; i < count; ++i)
    {
        fprintf(f, "\n");
        fputs(prod[i].name, f);
        fprintf(f, "\n");
        fprintf(f, "%d\n", prod[i].quantity);
        fprintf(f, "%f\n", prod[i].price);
    }
    fclose(f);
    return 0;
}

int readFile() // Read file function
{
    int n = 0;
    int i;
    f = fopen("inventory.txt", "r");
    if (f == NULL)
        return -1;
    fscanf(f, "%d\n", &n);
    for (i = 0; i < n; ++i)
    {
        fgets(prod[i].name, 20, f);
        prod[i].name[strlen(prod[i].name)-1] = 0; // Remove new lines
        fscanf(f, "%d", &prod[i].quantity);
        fscanf(f, "%f", &prod[i].price);
    }
    fclose(f);
    return n;
}

void displayProd ()
{
    int i;
    count = readFile();
    if (count < 0) {
        printf ("Cannot open file.\n");

        printf("\t\t ----INVENTORY---- \n"); // Display current Inventory
        printf("-------------------------------------------\n");
        printf("|  QUANTITY |   PRODUCT NAME   |    PRICE   |\n");
        printf("-------------------------------------------\n");

        for (i=0;i<count;i++)
        {
        printf("    %d       %-10s       %-3.2f\n", prod[i].quantity, prod[i].name, prod[i].price);
        }
    }
}

int main() 
{   
    int choice;
    count = readFile(); 
	if(count < 0) // There is no file located.
		printf("Cannot locate file\n");
do {
	printf("\n"); // Display Menu
	printf("\t\t\t  ================================\n");
	printf("\t\t\t     SARI-SARI STORE INVENTORY\n");
	printf("\t\t\t  ================================");

    printf("\n\n Menu: ");
    printf("\n [1] Set the Date");
    printf("\n [2] Update Inventory");
    printf("\n [3] Update Point of Sale");
    printf("\n [4] View Inventory");
    printf("\n [5] View Point of Sale");
    printf("\n [6] Exit the Program");
    printf("\n Choice: ");
    scanf("%d", &choice);
    // Switch ko nalang ang choice :D
}
while (choice != 6);
printf("Thank you for using this program ! :D");
}
