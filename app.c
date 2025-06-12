#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "stl_usecase.h"

void print_menu() {
    printf("\n=== C++ STL Demo Menu ===\n");
    printf("1. Vector Demo\n");
    printf("2. Map Demo\n");
    printf("3. Algorithm Demo\n");
    printf("4. Container Utilities Demo\n");
    printf("5. Run C Functions\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    int a = 10, b = 5;
    
    do {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                run_vector_demo();
                break;
                
            case 2:
                run_map_demo();
                break;
                
            case 3:
                run_algorithm_demo();
                break;
                
            case 4:
                run_container_utils_demo();
                break;
                
            case 5:
                printf("\n=== C Functions ===\n");
                printf("%d + %d = %d\n", a, b, add(a, b));
                printf("%d - %d = %d\n", a, b, subtract(a, b));
                break;
                
            case 0:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        if (choice != 0) {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n');  // Clear input buffer
            getchar();  // Wait for Enter
        }
        
    } while (choice != 0);
    
    return 0;
}
