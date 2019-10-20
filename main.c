#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"

int main(int argc, char *argv[]) {
    if(argc != 2)
	return 0;
    char* input_file  = argv[1];
    char* dictionary_file = argv[2];
    node* hashtable[HASH_SIZE];
    bool loaded_dict = load_dictionary(dictionary_file, hashtable);
    if(!loaded_dict)
	printf("%s", "Issue loading dictionary");
    
    FILE *fp = fopen(input_file, "r");
    if(fp==NULL){
        perror("fopen");
	exit(1);
    }
    int num_misspelled;
    char *misspelled[MAX_MISSPELLED];
    num_misspelled = check_words(fp, hashtable, misspelled);
    printf("Num misspelled: %d", num_misspelled);


    hashmap_t cursor = NULL;
    for(int i = 0; i<HASH_SIZE; i++){
        cursor = hashtable[i];
	hashmap_t tmp;
	while(cursor != NULL){
	    tmp = cursor;
	    cursor = cursor -> next;
	    free(tmp);
	    tmp = NULL;
	}
    
    }
    return 0;
}
