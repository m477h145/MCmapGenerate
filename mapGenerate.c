#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int teleporter(int center[2], int radius, int step, int timer, char user[16], char screen[16], int verbose);

int main() {

    int center[2]= {0,0};
    int radius= 2500;
    int step= 100;
    int timer= 10;
    char screen[16]= "minecraft";
    char user[16]= "";
    int verbose= 1;

    for (int i = 0; i < 50; i++) //Program loop
    {

        printf("\nWhat do you want to do?\n");
        printf("(1) Change Map Center (Current: X: %d, Z:%d)\n", center[0], center[1]);
        printf("(2) Change generating Radius (Current: %d blocks)\n", radius);
        printf("(3) Change teleporting step (Current: %d blocks)\n", step);
        printf("(4) Change wait time between TPs (Current: %d seconds)\n", timer);
        printf("(5) Change MC console screen session (Current: %s)\n", screen);
        printf("(6) Enter Username (Current: %s)\n", user);
        printf("(7) Print current Coords\n");
        printf("(8) Run Script\n");
        printf("(9) Quit\n");

        
        //Calculating time needed for the script to finish (used to be broken but I found the fix while doin elementary level math) 
        double time_h= (double) pow(((2*radius)/step)+1, 2)*timer / 3600;
        double time_m= 60*modf(time_h, &time_h);
        double time_s= 60*modf(time_m, &time_m);

        printf("Time needed for the script: %.lfh %.lfm %.lfs\n", time_h, time_m, time_s);
        
        /*
        //I tried fancy math functions but failed so we're back to elementary math class
        int time= pow(((2*radius)/step)+1, 2)*timer;
        int time_h= time/3600;
        int time_m= time/60-time_h*60;
        int time_s= time-time_m*60-time_h*3600;
        
        printf("Time needed for the script: %dh %dm %ds\n", time_h, time_m, time_s);
        */

        int choice;
        printf("Select: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            //Change Center
            printf("\nPlease enter Coords of the Center.\n");
            printf("X: ");
            scanf("%d", &center[0]);
            printf("Z: ");
            scanf("%d", &center[1]);
            break;

        case 2:
            //Change Radius
            printf("\nPlease enter the Radius (preferably an even number).\n");
            printf("Radius: ");
            scanf("%d", &radius);
            if (radius % step != 0)
            {
                printf("\n+---------------------------------------------------------+\n");
                printf("| Please enter a Radius that is a multiple of the TP step |\n");
                printf("+---------------------------------------------------------+\n\n");
            }
            break;

        case 3:
            //Change TP step
            printf("\nPlease enter the Teleporting step (recommended: 100).\n");
            printf("Step: ");
            scanf("%d", &step);
            if (radius % step != 0)
            {
                printf("\n+---------------------------------------------------------+\n");
                printf("| Please enter a Radius that is a multiple of the TP step |\n");
                printf("+---------------------------------------------------------+\n\n");
            }
            break;

        case 4:
            //Change wait time
            printf("\nPlease enter wait time in seconds between each step (recommended: 10).\n");
            printf("Seconds: ");
            scanf("%d", &timer);
            break;
        
        case 5:
            //Change screen
            printf("Please enter the name of the screen session used by the MC console.\n");
            printf("Screen session: ");
            while ((getchar()) != '\n'); //Flush stdin
            fgets(screen, sizeof(screen), stdin);
            screen[strcspn(screen, "\n")] = 0; //Stripping \n from string
            break; 

        case 6:
            //Change Username
            printf("Please enter the name of the Player that you want to teleport.\n");
            printf("Username: ");
            while ((getchar()) != '\n'); //Flush stdin
            fgets(user, sizeof(user), stdin);
            user[strcspn(user, "\n")] = 0; //Stripping \n from string
            break;

        case 7:
            //Print progress
            printf("Output progress to system console?\n");
            char print;
            printf("Y/N: ");
            scanf("%c", &print);
            if (print == 89 || 121)
            {
                verbose= 0;
                printf("\nProgress printing enabled\n");
            }
            if (print == 78 || 110)
            {
                verbose= 1;
                printf("\nProgress printing disabled\n");
            }
            break;  

        case 8:
            //Run script
            teleporter(center, radius, step, timer, user, screen, verbose);
            break;   

        default:
            printf("\n+------------------+\n");
            printf("| Quittung program |\n");
            printf("+------------------+\n");
            return 0;
        }
    }
return 0;
}

int teleporter(int center[2], int radius, int step, int timer, char user[16], char screen[16], int verbose) {

    printf("\nPregenerating Map...\n");
    char buf[64];
    int x = center[0]-radius;
    while (x <= center[0]+radius)
    {
        int z = center[1]-radius;
        while (z <= center[1]+radius)
        {   
            if (verbose == 0)
            {
                printf("Teleporting Player to X:%d Y:150 Z:%d\n", x, z);
            }
            
            snprintf(buf, sizeof(buf), "./teleport.sh %d %d %s %s", x, z, user, screen); //Assemble shell command
            system(buf); //Print command to shell
            sleep(timer); //Wait for map to generate
            
            z += step;
        }
    x += step;
    }
    printf("\nPregenerating Done\n");
return 0;
}

/*

//Pregenerates 10k x 10k Hardcoded
int teleporter_old() {
    int x= -5000;
    int y= -5000;
    int size= 5000;
    printf("\nPregenerating Map...\n");

    char buf[32];
    int x= -size;
    while (x <= size)
    {
        int z= -size;
        while (z <= size)
        {
            printf("Teleporting Player to X:%d Y:150 Z:%d\n", x, z); 
            snprintf(buf, sizeof(buf), "./teleport.sh %d %d %s %s", x, z, "matthias0608", "minecraft");
            system(buf);
            sleep(10);
            z += 100;
        }
    x += 100;
    }
    
    printf("\nPregenerating Done\n");

    return 0;
}

*/