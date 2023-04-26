#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_SEARCH_LENGTH 100
#define MAX_REPLACE_LENGTH 100

int main() {
    FILE *fp;
    char filename[MAX_FILENAME_LENGTH];
    char buffer[MAX_LINE_LENGTH];
    char search[MAX_SEARCH_LENGTH];
    char replace[MAX_REPLACE_LENGTH];
    int choice, line_num = 0;
    printf("Text Editor\n");
    printf("-----------\n");
    printf("1. Open file\n");
    printf("2. Edit file\n");
    printf("3. Save file\n");
    printf("4. Replace text\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the name of the file to open: ");
            scanf("%s", filename);
            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("Could not open file %s\n", filename);
                return 1;
            }
            while (fgets(buffer, MAX_LINE_LENGTH, fp)) {
                printf("%s", buffer);
            }
            fclose(fp);
            break;
        case 2:
            printf("Enter the name of the file to edit: ");
            scanf("%s", filename);
            fp = fopen(filename, "r+");
            if (fp == NULL) {
                printf("Could not open file %s\n", filename);
                return 1;
            }
            printf("Enter the new text: (press Ctrl+D to save)\n");
            while (fgets(buffer, MAX_LINE_LENGTH, stdin)) {
                fprintf(fp, "%s", buffer);
            }
            fclose(fp);
            break;
        case 3:
            printf("Enter the name of the file to save: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Could not create file %s\n", filename);
                return 1;
            }
            printf("Enter the text to save: (press Ctrl+D to save)\n");
            while (fgets(buffer, MAX_LINE_LENGTH, stdin)) {
                fprintf(fp, "%s", buffer);
            }
            fclose(fp);
            break;
        case 4:
            printf("Enter the name of the file to edit: ");
            scanf("%s", filename);
            fp = fopen(filename, "r+");
            if (fp == NULL) {
                printf("Could not open file %s\n", filename);
                return 1;
            }
            printf("Enter the word to replace: ");
            scanf("%s", search);
            printf("Enter the word to replace it with: ");
            scanf("%s", replace);
            while (fgets(buffer, MAX_LINE_LENGTH, fp)) {
                line_num++;
                if (strstr(buffer, search)) {
                    char *new_buffer = malloc(strlen(buffer) + 1);
                    char *orig_buffer = buffer;
                    char *temp;
                    while ((temp = strstr(orig_buffer, search))) {
                        strncpy(new_buffer, orig_buffer, temp - orig_buffer);
                        new_buffer[temp - orig_buffer] = '\0';
                        strcat(new_buffer, replace);
                        orig_buffer = temp + strlen(search);
                        strcat(new_buffer, orig_buffer);
                        strcpy(buffer, new_buffer);
                    }
                    fseek(fp, -(long)(strlen(buffer)), SEEK_CUR);
                    fprintf(fp, "%s", buffer);
                    fseek(fp, 0L,SEEK_CUR);
free(new_buffer);
}
}
fclose(fp);
printf("Replacement complete. %d lines modified.\n", line_num);
break;
case 5:
printf("Exiting...\n");
return 0;
default:
printf("Invalid choice\n");
return 1;
}
return 0;
}