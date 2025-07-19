#include <stdio.h>
#include <stdlib.h>
#include "PcToJson.h"

int main()
{
    int currentMode;
    char filename[256];
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
    printf("Your file name: ");
    scanf("%s", filename);
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
