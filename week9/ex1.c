//
//  main.c
//  ex1
//
//  Created by admin on 18/10/2018.
//  Copyright © 2018 admin. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#define no_page_frames 10


struct page_t{
    int number;
    unsigned int counter;
} typedef page_t;

int page_is_present(page_t *page_list, int referenced_page){
    for (int i = 0; i < no_page_frames; i++){
        if (page_list[i].number == referenced_page)
            return 1;
    }
    return 0;
}

int choose_victim(page_t *page_list){
    
    int min_age = page_list[0].counter;
    int victim = 0;
    for (int i = 1; i < no_page_frames; i ++){
        if (page_list[i].counter < min_age){
            min_age = page_list[i].counter;
            victim = i;
        }
    }
    return victim;
}


int insert_page(page_t *page_list, int referenced_a, int list_length, int free_slot){
    
    page_t new_page;
    new_page.number = referenced_a;
    new_page.counter = 1 << 31;
    if (free_slot < no_page_frames){
        page_list[free_slot] = new_page;
        free_slot++;
        
    }
    else {
        int victim = choose_victim(page_list);
        page_list[victim] = new_page;
    }
    return free_slot;
}

void update_references(page_t *page_list, int referenced_page){
    for (int i = 0; i < no_page_frames; i++){
        if (page_list[i].number == referenced_page){
            page_list[i].counter >>= 1;
            page_list[i].counter += 1<<31;
        }
        else
            page_list[i].counter >>= 1;
    }
}



int main(){
    
    page_t* page_list = malloc(no_page_frames*sizeof(page_t));
    int free_spot = 0;
    FILE* input_file;
    
    input_file = fopen("Lab 09 input.txt", "r");
    if (input_file == NULL){
        exit(EXIT_FAILURE);
    }

    int size = 0;
    int t = 0;
    while ((fscanf(input_file, "%d",&t)!=EOF)) size++;
    
    int *input_sequence = (int*) malloc(size*sizeof(int));
    
    rewind(input_file);
    
    for (int i = 0; i < size; i ++)
        fscanf(input_file, "%d", &input_sequence[i]);
    fclose(input_file);
    
    int hit = 0, miss = 0;
    
    for (int i = 0; i < size; i++){
        if (!page_is_present(page_list, input_sequence[i])){
            free_spot = insert_page(page_list, input_sequence[i], size, free_spot);
            miss ++;
        }
        else
            hit ++;
        update_references(page_list, input_sequence[i]);
    }
    
    double ratio = 1.0 * hit/miss;
    printf("%f", ratio);
    return 0;
    
}
