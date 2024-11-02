/*
    As we've been spending a couple weeks on file I/O, I'd like you to implement a system for
saving, reading, and editing data. You'll need to create some kind of structure to store
some kind of information. Players from a sports team, Pokémon, foods, or some other
thing that would be stored in a structure. Your program should be menu based, where
running the program presents the user with a list of options. A user should be able to:

    1. Insert a new file entry at the end of the file
    2. Read an entry from the file at an index
    3. Edit an existing entry at an index
    4. Exit the Program

The name of the file should be supplied as a command line argument and passed to
relevant fopen calls. Your program should use binary files and methods for file I/O, not
text methods. This program will not use CodeBox, so you have some more creative
flexibility than most assignments.

To submit, I'd like you to have a folder in your home directory called fileio-hw . Inside of
that directory should be your completed code file, called main.c , a compiled binary called
out (can be compiled as gcc main.c -o out ), and a sample data file called data.bin .
These names are only required once you're done with the assignment, so feel free to use
other file names and just a.out while you're working on it. In D2L, submit screenshots of
your code working.
*/

// 'rb+' will allow us to read and write to files
// Write the files in binary

#include <stdio.h>
// For the "system("cls");"
#include <stdlib.h>

// Structure for pokemon
    // Including their index number
    // Pokemon Name
    // Pokemon Type
struct Pokemon{
    int num;
    char name[20];
    char type[10];
};

// Prints the main menu for all actions available 
void mainMenu(){
    printf("\t\t\t---POKEDEX---\n\n");
    printf("(1) List all Pokemon.\n");
    printf("(2) Add a Pokemon.\n");
    printf("(3) Find Pokemon.\n\n");
    printf("(x) Exit Program.\n");
}

void listPokedex(FILE* fp){
    system("cls");

    char string[100];

    fgets(string, 100, fp);
    printf("%s", string);
}

void addPokemon(FILE* fp){
    struct Pokemon newPokemon;
    system("cls");

    printf("Name of Pokemon: ");
    scanf("%s", newPokemon.name);

    printf("%s's Type: ", newPokemon.name);
    scanf("%s", newPokemon.type);
}


int main(){
    char user = 'a';
    FILE* fp = fopen("pokemon.bin", "rb+");

    if(fp == NULL){
        printf("File Error.");
        exit(1);
    }

    while(user != 'x'){
        system("cls");
        mainMenu();

        scanf("%c", &user);

        switch(user){
            case '1':
                listPokedex(fp);
                break;
            case '2':
                addPokemon(fp);
                break;
            case '3':
                break;
            case 'x':
                break;
            default:
                printf("Please pick one of the options from the list: 1 2 3 x\n");
        }

    }
    fclose(fp);

    printf("Closing...");
    return 0;
}