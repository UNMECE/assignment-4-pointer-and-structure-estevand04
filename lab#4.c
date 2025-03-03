#include <stdio.h>
#include "item.h"
#include <stdlib.h>
#include <string.h>

void add_item(item *item_list, int i, double price, char *sku, char *category, char *name){
item_list[i].price=(price);
item_list[i].sku=strdup(sku);
item_list[i].category=strdup(category);
item_list[i].name=strdup(name);
}

void free_items(item *item_list, int size){
int i;
for(i=0; i<size; i++){
        if(item_list[i].sku){
                free(item_list[i].sku);
        }
        if(item_list[i].category){
                free(item_list[i].category);
        }
        if(item_list[i].name){
                free(item_list[i].name);
        }
}
free(item_list);
}

double average_price(item *item_list, int size){
        double total_price=0;
        int i;
        for(i=0; i<size; i++){
                total_price+=item_list[i].price;
        }
return total_price/size;

}

void print_items(item *item_list, int size){
        int i;
        for(i=0; i<size; i++){
                printf("#############\n");
                printf("item name: %s\n", item_list[i].name);
                printf("item sku: %s\n", item_list[i].sku);
                printf("item category: %s\n", item_list[i].category);
                printf("item price: %f\n", item_list[i].price);
                printf("#############\n");
        }
}





int main(int argc, char *argv[]){
        item *item_list=malloc(5*sizeof(item));

        add_item(item_list, 0, 4.0, "10011", "breakfast", "frosted-flakes");
        add_item(item_list, 1, 12.0, "20011", "lunch", "bacon-cheeseburger");
        add_item(item_list, 2, 8.0, "30011", "dessert", "chocolate-ice-cream");
        add_item(item_list, 3, 25.0, "40011", "clothing-brand", "GAP");
        add_item(item_list, 4, 75.0, "50011", "shoe-brand", "New-Balance");

        print_items(item_list, 5);

        double avg_price=average_price(item_list, 5);
        printf("Average price: %.3f\n", avg_price);
        free_items(item_list, 5);

        if(argc>1){
                char *search_sku=argv[1];
                int found=0;
                int i;
                for(i=0; i<5; i++){
                        if(strcmp(item_list[i].sku, search_sku)==0){
                                printf("item found:\n");
                                printf("#############\n");
                                printf("item name: %s\n", item_list[i].name);
                                printf("item sku: %s\n", item_list[i].sku);
                                printf("item category: %s\n", item_list[i].category);
                                printf("item price: %f\n", item_list[i].price);
                                printf("#############\n");
                                found = 1;
                                break;
                        }
                if(!found){
                        printf("item not found!\n");
                }
                        return 0;
                }
        }
}
