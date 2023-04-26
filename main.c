#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100];
    char buffer[1000];
    char insert[1000];
    int pos;
    printf("Enter the name of the file to open: ");
    scanf("%s", filename);
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Could not open file %s", filename);
        return 1;
    }
    printf("Enter the text to insert: ");
    scanf("%s", insert);
    printf("Enter the position to insert the text (starting from 0): ");
    scanf("%d", &pos);
    fseek(fp, pos, SEEK_SET);
    fgets(buffer, sizeof(buffer), fp);
    fseek(fp, pos, SEEK_SET);
    fprintf(fp, "%s%s", insert, buffer);
    fclose(fp);
    return 0;
}
