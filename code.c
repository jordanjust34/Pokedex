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
typedef struct{ 
    int index;
    char name[50];
    char type[50];
}Pokemon;

// Print Menu
void printMenu(){
    printf("=======POKEDEX=======\n\n");
    printf("(1) Add Pokemon.\n");
    printf("(2) Search Pokedex.\n");
    printf("(3) Edit Pokedex Entry.\n\n");
    printf("(0) Exit Pokedex.\n\n");
}

// Insert new file entry at the end of file
void addPokemon(FILE *fp){
    Pokemon newPokemon;

    newPokemon.index = 

    printf("Pokemon Name: ");
    scanf("%s", newPokemon.name);

    printf("%s's Type: ", newPokemon.name);
    scanf("%s", newPokemon.type);

    fseek(fp, 0, SEEK_END);
    fwrite(&newPokemon, sizeof(Pokemon), 1, fp);
}

// Find and Read data from a Pokemon
void readPokemon(FILE *fp, int index){
    Pokemon readPokemon;

    printf("Enter Pokemon Index Number: ");
    scanf("%d", &index);
    system("cls");

    fseek(fp, index * sizeof(Pokemon), SEEK_SET);

    fread(&readPokemon, sizeof(Pokemon), 1, fp);

    printf("Index Number: %d\n", index);
    printf("Pokemon: %s\n", readPokemon.name);
    printf("Type: %s\n\n", readPokemon.type);
}

// Edit existing Pokemon data
void editPokemon(FILE *fp, int index){
    Pokemon editPokemon;

    printf("Enter Pokemon Index Number: ");
    scanf("%d", &index);
    system("cls");

    fseek(fp, index * sizeof(Pokemon), SEEK_SET);

    fread(&readPokemon, sizeof(Pokemon), 1, fp);

    printf("Index Number: %d\n", index);
    printf("Pokemon: %s\n", editPokemon.name);
    printf("Type: %s\n\n", editPokemon.type);


    printf("Change %s's Name: ");
    scanf("%s", editPokemon.name);

    printf("Change %s's Type: ");
    scanf("%s", editPokemon.type);

    fseek(fp, index * sizeof(Pokemon), SEEK_SET);
    fwrite(&editPokemon, sizeof(Pokemon), 1, fp);
    
}

int main(int argc, char *argv[]){

    // Opens in "rb+" if a file is their, will open/create with "wb+" if no file is their
    FILE* fp;
    if(fp != NULL){
        fp = fopen(argv[1], "rb+");
    }else{
        fp = fopen(argv[1], "wb+");
    }

    int user, index;

    while(1){
        printMenu();
        scanf("%d", &user);

        system("cls");

        switch(user){
            case 1:
                addPokemon(fp);
                break;
            case 2:
                readPokemon(fp, index);
                break;
            case 3:
                editPokemon(fp, index);
                break;
            case 0:
                fclose(fp);
                return 1;
            default:
                printf("Please select options 1 - 4.\n");
        }
    }

    return 0;
}