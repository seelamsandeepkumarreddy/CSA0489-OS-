#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 1000 
#define MAX_FILES 100   


typedef struct {
    int index_block;  
    int num_blocks;   
} File;

void allocate_blocks(File files[], int file_index, int num_blocks) {
    files[file_index].num_blocks = num_blocks;
}

void read_block(File files[], int file_index, int block_num) {
    int index_block = files[file_index].index_block;
    printf("Reading block %d of file %d\n", block_num, file_index);
}


void write_block(File files[], int file_index, int block_num) {
    int index_block = files[file_index].index_block;
    printf("Writing to block %d of file %d\n", block_num, file_index);
}

int main() {
    File files[MAX_FILES];
    int num_files;

    printf("Enter the number of files in the file system: ");
    scanf("%d", &num_files);

    if (num_files > MAX_FILES) {
        printf("Maximum number of files exceeded.\n");
        return 1;
    }

    // Initialize files
    for (int i = 0; i < num_files; i++) {
        files[i].index_block = i;  // Each file's index block points to itself
        files[i].num_blocks = 0;
    }

    int option;
    do {
        printf("\nFile System Menu:\n");
        printf("1. Allocate blocks to a file\n");
        printf("2. Read from a block\n");
        printf("3. Write to a block\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                {
                    int file_index, num_blocks;
                    printf("Enter file index and number of blocks to allocate: ");
                    scanf("%d %d", &file_index, &num_blocks);
                    if (file_index < 0 || file_index >= num_files) {
                        printf("Invalid file index.\n");
                        break;
                    }
                    allocate_blocks(files, file_index, num_blocks);
                    printf("Blocks allocated successfully.\n");
                }
                break;
            case 2:
                {
                    int file_index, block_num;
                    printf("Enter file index and block number to read: ");
                    scanf("%d %d", &file_index, &block_num);
                    if (file_index < 0 || file_index >= num_files || block_num < 0 || block_num >= files[file_index].num_blocks) {
                        printf("Invalid file index or block number.\n");
                        break;
                    }
                    read_block(files, file_index, block_num);
                }
                break;
            case 3:
                {
                    int file_index, block_num;
                    printf("Enter file index and block number to write: ");
                    scanf("%d %d", &file_index, &block_num);
                    if (file_index < 0 || file_index >= num_files || block_num < 0 || block_num >= files[file_index].num_blocks) {
                        printf("Invalid file index or block number.\n");
                        break;
                    }
                    write_block(files, file_index, block_num);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}
