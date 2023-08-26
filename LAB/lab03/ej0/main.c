#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {

    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

char *parse_filepath(int argc, char *argv[]) {
    char *result;
    if (argc < 2) {
        exit(EXIT_FAILURE);
    }
    result = argv[1];
    return result;
}


unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size)
{
    unsigned int l = 0u;

    FILE *file = fopen(path, "r");

    if (file == NULL)
    {
        printf("Error leyendo archivo");
    }
    
    
    while (!(feof(file)) && l <= max_size)
    {
        if (fscanf(file, "%u '%c'\n", &indexes[l], &letters[l]) != EOF)
        {
            l ++;
        }
        
    }

    fclose(file);
    
    return l;
}


int main(int agrc, char *agrv[]) {

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];

    unsigned int length = 0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    /* -- completar -- */

    char *filepath = parse_filepath(agrc, agrv);
    length = data_from_file(filepath, indexes, letters, MAX_SIZE);

    
    // free(filepath);

    for (unsigned int i = 0; i < length; i++)
    {
        sorted[indexes[i]] = letters[i];
    }
    
    dump(sorted, length);


    

    return EXIT_SUCCESS;
}

