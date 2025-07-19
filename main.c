#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "PcToJson.h"

int main()
{
    int currentMode;
    printf("Welcome to PC Simulator Script!\nChoose what do you want:\n");
    printf("1) Convert .pc to .json\n");
    printf("2) Convert .json to .pc\n");
    printf("Your input: ");
    scanf("%d", &currentMode);
    if (currentMode != 1 && currentMode != 2)
    {
        printf("Error: enter 1 or 2!");
        return 2;
    }
    char *filename = readline("Your file name: ");
    if (!filename || filename[0] == '\0') {
        printf("Error: empty filename!\n");
        return 3;
    }
    if (currentMode == 1)
    {
        printf("Opening file...\n");
        FILE *fp = fopen(filename, "rb");
        if (!fp)
        {
            perror("Failed");
            return 1;
        }
        printf("Succes!\n");
        printf("Creating file...\n");
        FILE *out = fopen("output.json", "wb");
        if (!out)
        {
            perror("output.json");
            return 1;
        }
        printf("Succes!\n");
        printf("Converting...\n");
        convertToJson(fp, out);
        printf("Succes!\n");
        fclose(fp);
        fclose(out);
    }
    else if (currentMode == 2)
    {
        printf("Opening file...\n");
        FILE *fp = fopen(filename, "rb");
        if (!fp)
        {
            perror("Failed");
            return 1;
        }
        printf("Succes!\n");
        printf("Creating file...\n");
        FILE *out = fopen("output.pc", "wb");
        if (!out)
        {
            perror("output.pc");
            return 1;
        }
        printf("Succes!\n");
        printf("Converting...\n");
        exportToPC(fp, out);
        printf("Succes!\n");
        fclose(fp);
        fclose(out);
    }
    free(filename);
}
