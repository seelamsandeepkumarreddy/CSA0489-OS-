#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    
    char *file_path = "example.txt";
    
    
    mode_t file_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; 
    
    if (creat(file_path, file_permissions) == -1) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    

    struct stat file_stat;
    if (stat(file_path, &file_stat) == -1) {
        perror("Error getting file information");
        exit(EXIT_FAILURE);
    }
    
    printf("File: %s\n", file_path);
    printf("Owner: %d\n", file_stat.st_uid); 
    printf("Group: %d\n", file_stat.st_gid); 
    printf("Permissions: %o\n", file_stat.st_mode & 0777); 
    
    return 0;
}
