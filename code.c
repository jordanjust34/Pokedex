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
    printf("Index Starts at 1.\n\n");
    printf("(1) Add Pokemon.\n");
    printf("(2) Search Pokedex.\n");
    printf("(3) Edit Pokedex Entry.\n\n");
    printf("(0) Exit Pokedex.\n\n");
}

// Insert new file entry at the end of file
void addPokemon(FILE *fp){
    Pokemon newPokemon;

    printf("Pokemon Name: ");
    scanf("%s", newPokemon.name);

    printf("%s's Type: ", newPokemon.name);
    scanf("%s", newPokemon.type);

    fseek(fp, 0, SEEK_END);
    fwrite(&newPokemon, sizeof(Pokemon), 1, fp);

    fclose(fp);
}

// Find and Read data from a Pokemon
void readPokemon(FILE *fp, int index){
    Pokemon readPokemon;

    fseek(fp, index * sizeof(Pokemon), SEEK_SET);
    fread(&readPokemon, sizeof(Pokemon), 1, fp);

    printf("Index Number: %d\n", index + 1);
    printf("Pokemon: %s\n", readPokemon.name);
    printf("Type: %s\n\n", readPokemon.type);

    fclose(fp);
}

// Edit existing Pokemon data
void editPokemon(FILE *fp, int index){
    Pokemon editPokemon;

    fseek(fp, index * sizeof(Pokemon), SEEK_SET);
    fread(&editPokemon, sizeof(Pokemon), 1, fp);

    printf("Index Number: %d\n", index + 1);
    printf("Pokemon: %s\n", editPokemon.name);
    printf("Type: %s\n\n", editPokemon.type);

    printf("Change %s's Name: ", editPokemon.name);
    scanf("%s", editPokemon.name);

    printf("Change %s's Type: ", editPokemon.name);
    scanf("%s", editPokemon.type);

    fseek(fp, index * sizeof(Pokemon), SEEK_SET);
    fwrite(&editPokemon, sizeof(Pokemon), 1, fp);
    
    fclose(fp);
}

int main(int argc, char *argv[]){

    // Opens in "rb+" if a file is their, will open/create with "wb+" if no file is their
    FILE* fp;
    if(fp != NULL){
        fp = fopen(argv[1], "rb+");
    }else{
        fp = fopen(argv[1], "wb+");
    }

    fclose(fp);

    int user, index;

    while(1){
        printMenu();
        scanf("%d", &user);

        system("cls");

        switch(user){
            case 1:
                fopen(argv[1], "ab");
                addPokemon(fp);
                break;
            case 2:
                fopen(argv[1], "rb+");
                printf("Enter Pokemon Index: ");
                scanf("%d", &index);
                index -= 1;
                system("cls");
                readPokemon(fp, index);
                break;
            case 3:
                fopen(argv[1], "rb+");
                printf("Enter Pokemon Index: ");
                scanf("%d", &index);
                index -= 1;
                system("cls");
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