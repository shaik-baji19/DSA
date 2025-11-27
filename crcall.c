#include <stdio.h>
#include <string.h>
unsigned int crc12(const char *data)
{
    unsigned int poly = 0x180F;
    unsigned int crc = 0x0005;
    for (int i = 0; i < strlen(data); i++)
    {
        unsigned char byte = data[i];
        for (int j = 0; j < 8; j++)
        {
            int bit = ((byte >> (7 - j)) & 1) ^ ((crc >> 11) & 1);
            crc <<= 1;
            if (bit)
                crc ^= poly;
            crc &= 0x0FFF;
        }
    }
    return crc;
}
int main()
{
    char data[100];
    printf("Enter a string:");
    scanf("%s", data);
    printf("CRC12 = %03X\n", crc12(data));
}



CRC16

#include <stdio.h>
#include <string.h>
unsigned int crc16(const char *data)
{
    unsigned int poly = 0x8005;
    unsigned int crc = 0x0000;
    for (int i = 0; i < strlen(data); i++)
    {
        unsigned char byte = data[i];
        for (int j = 0; j < 8; j++)
        {
            int bit = ((byte >> (7 - j)) & 1) ^ ((crc >> 15) & 1);
            crc <<= 1;
            if (bit)
                crc ^= poly;
            crc &= 0x0FFF;
        }
    }
    return crc;
}
int main()
{
    char data[100];
    printf("Enter a string:");
    scanf("%s", data);
    printf("CRC16 = %04X\n", crc16(data));
}



CRC_CCIP

#include <stdio.h>
#include <string.h>
unsigned int crc_ccip(const char *data)
{
    unsigned int poly = 0x1021;
    unsigned int crc = 0xFFFF;
    for (int i = 0; i < strlen(data); i++)
    {
        unsigned char byte = data[i];
        for (int j = 0; j < 8; j++)
        {
            int bit = ((byte >> (7 - j)) & 1) ^ ((crc >> 15) & 1);
            crc <<= 1;
            if (bit)
                crc ^= poly;
            crc &= 0xFFFF;
        }
    }
    return crc;
}
int main()
{
    char data[100];
    printf("Enter a string:");
    scanf("%s", data);
    printf("CRC-CCIP = %04X\n", crc_ccip(data));
}

