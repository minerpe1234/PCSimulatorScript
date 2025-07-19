#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void convertToJson(FILE *input, FILE *output)
{
    int num = 0;
    int canChange = 0;
    fseek(input, 0, SEEK_END);
    long size = ftell(input);
    fseek(input, 0, SEEK_SET);
    uint8_t nextLine = '\n';
    for (int i = 0; i < size; i++)
    {
        int byte;
        byte = fgetc(input);

        byte ^= 193;

        if (num == 1)
        {
            if (canChange)
            {
                switch (byte)
                {
                    case 'b': byte = '"'; break;
                    case 'z': byte = ':'; break;
                    case 'l': byte = ','; break;
                    case '`': byte = ' '; break;
                    case 'J': byte = '\n'; break;
                    case 'p': byte = '0'; break;
                    case 'q': byte = '1'; break;
                    case 'r': byte = '2'; break;
                    case 's': byte = '3'; break;
                    case 't': byte = '4'; break;
                    case 'u': byte = '5'; break;
                    case 'v': byte = '6'; break;
                    case 'w': byte = '7'; break;
                    case 'x': byte = '8'; break;
                    case 'y': byte = '9'; break;
                    case 'm': byte = '-'; break;
                    case 'n': byte = '.'; break;
                    case 'h': byte = '('; break;
                    case 'i': byte = ')'; break;
                    case 'o': byte = '/'; break;
                }
                canChange = 0;
            }

            fwrite(&byte, 1, 1, output);
            num = 0;
        }
        else
        {
            if (byte == 0x03)
                canChange = 1;
            num = 1;
        }
    }
}
void exportToPC(FILE *input, FILE *output)
{
    int num = 1;
    int changeByte = 0;
    fseek(input, 0, SEEK_END);
    long size = ftell(input);
    fseek(input, 0, SEEK_SET);
    uint8_t changeMarker = 0x03 ^ 193;
    uint8_t noChangeMarker = 0x02 ^ 193;
    int byte;
    for (int i = 0; i < size * 2; i++)
    {
        byte = fgetc(input);
        if (byte == '\r')continue;
        if (num == 0)
        {
            switch (byte)
            {
                case '"': byte = 'b'; break;
                case ':': byte = 'z'; break;
                case ',': byte = 'l'; break;
                case ' ': byte = '`'; break;
                case '\n': byte = 'J'; break;
                case '0': byte = 'p'; break;
                case '1': byte = 'q'; break;
                case '2': byte = 'r'; break;
                case '3': byte = 's'; break;
                case '4': byte = 't'; break;
                case '5': byte = 'u'; break;
                case '6': byte = 'v'; break;
                case '7': byte = 'w'; break;
                case '8': byte = 'x'; break;
                case '9': byte = 'y'; break;
                case '-': byte = 'm'; break;
                case '.': byte = 'n'; break;
                case '(': byte = 'h'; break;
                case ')': byte = 'i'; break;
                case '/': byte = 'o'; break;
            }

            byte ^= 193;
            fputc(byte, output);
            num = 1;
        }
        else
        {
            ungetc(byte, input);
            switch (byte)
            {
                case '"': case ':': case ',': case ' ':
                case '0': case '1': case '2': case '3':
                case '4': case '5': case '6': case '7':
                case '8': case '9': case '-': case '.':
                case '\n': case '(': case ')': case '/':
                    fputc(changeMarker, output);
                    break;

                default:
                    fputc(noChangeMarker, output);
                    break;
            }
            num = 0;
        }
    }
}
