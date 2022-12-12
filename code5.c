#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
struct events{
    char event[200], date[15];
};

struct notes{
    char heading[50], date[15], note[600];
};

struct tasks{
    char task[100], date[15];
};

int main();
void calendar();
void notes();
void events();
void tasks();

void calendar(){
    system("cls"); 
    printf("\nCalendar\n");
}

//Notes function
void notes(){
    system("cls"); 
    printf("\n");
    printf("1. Add a note\n2. Edit a note\n3. View your notes\n4. Delete a note\n5. Exit\n");
    int choice_note;
    int no_of_notes;
    int n;
    while(2>0){
        printf("Enter your choice: ");
        scanf("%d",&choice_note);
        if (choice_note > 5 || choice_note <1){
            printf("Enter valid choice");
            continue;
        }
        else if (choice_note == 1){
            printf("Add a note\n");
            printf("How many notes do you want to enter: ");
            scanf("%d",&no_of_notes);
            struct notes no;
            FILE *ptr;
            if ((ptr = fopen("notes.dat","ab")) == NULL){
                printf("Error opening file!!");
                exit(1);
            }
            for (n = 0; n < no_of_notes; n++){
                printf("Note %d\n",(n+1));
                printf("Enter he heading of the note: ");
                // gets(no.heading);
                fgets(no.heading, 100, stdin);
                printf("Enter the date: ");
                // gets(no.date);
                fgets(no.heading, 100, stdin);
                printf("Enter the content of the notes: ");
                // gets(no.note);
                fgets(no.heading, 100, stdin);
                fwrite(&no, sizeof(struct notes), 1, ptr);
            }
            fclose(ptr);
        }
        else if (choice_note == 2){
            printf("Edit your notes\n");
            printf("\t\tPRINTING YOUR NOTES\t\t\n");
            struct notes no;
            FILE *ptr;
            if ((ptr = fopen("notes.dat","rb")) == NULL){
                printf("Error opening File");
                exit(1);
            }
            for (n = 0; n < no_of_notes; n++){
                fread(&no, sizeof(struct notes), 1, ptr);
                printf("Note %d\n",(n+1));
                printf("Note Heading: %s\nDate: %s\nContent: %s\n", no.heading, no.date, no.note);
            }
            fclose(ptr);
            int note_number;
            while(2>0){
                int ch_note;
                printf("What do you want to edit: \n1. Note Heading\n2. Date\n3. Content \n");
                scanf("%d",&ch_note);
                if (ch_note > 4 || ch_note < 0){
                    printf("enter valid choice");
                }
                else if (ch_note == 1){
                    printf("Enter the note number whose heading you want to change: ");
                    scanf("%d",&note_number);
                    struct notes no;
                    FILE *ptr;
                    if ((ptr = fopen("notes.dat","ab")) == NULL){
                        printf("Error opening File");
                        exit(1);
                    }
                    for (int p = 0; p < no_of_notes; p++){
                        fread(&no,  sizeof(struct notes), 1,ptr);
                        if ((p+1) == note_number){
                            printf("Current Note Heading: %s\n", no.heading);
                            printf("Enter the new heading: ");
                            // scanf("%s",&no.heading);
                            gets(no.heading);
                            gets(no.heading); 
                            fwrite(&no, sizeof(struct notes), 1, ptr);
                        }
                        else{
                            fwrite(&no, sizeof(struct notes), 1, ptr);
                        }
                    }
                    fclose(ptr);
                    break;
                }
                else if(ch_note == 2){

                }
                else{

                }
                printf("\n");
            }
            

        }
        else if (choice_note == 3){
            printf("View your notes\n");
            struct notes no;
            FILE *ptr;
            if ((ptr = fopen("notes.dat","rb")) == NULL){
                printf("Error opening File");
                exit(1);
            }
            for (n = 0; n < no_of_notes; n++){
                fread(&no, sizeof(struct notes), 1, ptr);
                printf("Note %d\n",(n+1));
                printf("Note Heading: %s\nDate: %s\nContent: %s\n", no.heading, no.date, no.note);
            }
            fclose(ptr);
        }
        else if (choice_note == 4){
            printf("Del a note\n");
        }
        else{
            main();
            break;
        }
        printf("\n");
    }
}

//Evennts function
void events(){
    system("cls"); 
    printf("\n");
    printf("1. Add a event\n2. Edit a event\n3. View your events\n4. Delete a event\n5. Exit\n");
    int choice_event;
    while(2>0){
        printf("Enter your choice: ");
        scanf("%d",&choice_event);
        if (choice_event > 5 || choice_event <1){
            printf("Enter valid choice");
            continue;
        }
        else if (choice_event == 1){
            printf("Edit an event\n");
        }
        else if (choice_event == 2){
            printf("Edit your events\n");
        }
        else if (choice_event == 3){
            printf("View your events\n");
        }
        else if (choice_event == 4){
            printf("Del a event\n");
        }
        else{
            main();
            break;
        }
    }
}

//Tasks function
void tasks(){
    system("cls"); 
    printf("\n");
    printf("1. Add a task\n2. Edit a task\n3. View your tasks\n4. Delete a task\n5. Exit\n");
    int choice_tasks;
    while(2>0){
        printf("Enter your choice: ");
        scanf("%d",&choice_tasks);
        if (choice_tasks > 5 || choice_tasks <1){
            printf("Enter valid choice");
            continue;
        }
        else if (choice_tasks == 1){
            printf("Edit a task\n");
        }
        else if (choice_tasks == 2){
            printf("Edit your tasks\n");
        }
        else if (choice_tasks == 3){
            printf("View your tasks\n");
        }
        else if (choice_tasks == 4){
            printf("Del a task\n");
        }
        else{
            main();
            break;
        }
    }
}

//Main menu
int main(){
    system("cls"); 
    choice1:
        int choice;
        fflush(stdin);
        printf("\n\tMENU\n");
        printf("1. Calendar\n2. Notes\n3. Events\n4. Tasks\n5. Exit\n");
        printf("Enter your choice: ");
        // choice=getchar();
        // fflush();
        scanf("%d",&choice);
        if (choice<=5 && choice >= 0){
            if (choice == 0){
                printf("\nEnter valid choice");
                printf("\nExiting..");
                goto choice1;
            }
            else if (choice == 1){
                calendar();
            }
            else if (choice == 2){
                notes();
            }
            else if (choice == 3){
                events();
            }
            else if (choice == 4){
                tasks();
            }
            else{
                printf("Exiting...");
            }
        }
        else{
            printf("\nEnter a valid choice\n");
            goto choice1;
                }
    return 0;
    }