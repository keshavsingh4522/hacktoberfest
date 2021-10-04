#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int own_pow(int a, int b) {

    int tmp = a;

    for (int i = 0; i < b-1; i++) {
        tmp = tmp * a;
    }

    return tmp;

}

void print(const unsigned char ip_arr[], const int mask)
{
    // setup
    unsigned char mask_arr[4] = {0, 0, 0, 0};
    int tmp_mask = mask;

    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 8; k++) {
            if (tmp_mask != 0) {
                mask_arr[i] |= 1 << (7-k);
                tmp_mask--;
            }
        }
    }

    // ------------

    printf("binary: "BYTE_TO_BINARY_PATTERN"."BYTE_TO_BINARY_PATTERN"."BYTE_TO_BINARY_PATTERN"."BYTE_TO_BINARY_PATTERN"\n", 
            BYTE_TO_BINARY(ip_arr[0]),
            BYTE_TO_BINARY(ip_arr[1]),
            BYTE_TO_BINARY(ip_arr[2]),
            BYTE_TO_BINARY(ip_arr[3])
    );

    // -------------

    tmp_mask = mask;

    printf("network mask (binary): ");

    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 8; k++) {
            if (tmp_mask != 0) {
                printf("1");
                tmp_mask--;
            } else {
                printf("0");
            }
        }
        if (i != 3)
            printf(".");
    }
    printf("\n");

    // -------------

    printf("network mask (decimal): ");
    printf("%d.%d.%d.%d", mask_arr[0], mask_arr[1], mask_arr[2], mask_arr[3]);
    printf("\n");

    // -------------

    printf("number of free bits: %d\n", 32 - mask);

    // -------------

    printf("network-ID: ");
    printf("%d.%d.%d.%d", ip_arr[0] & mask_arr[0], ip_arr[1] & mask_arr[1], ip_arr[2] & mask_arr[2], ip_arr[3] & mask_arr[3]);
    printf("\n");

    // -------------

    printf("Broadcast-Adress: ");
    
    unsigned char tmpip[4] = {ip_arr[0], ip_arr[1], ip_arr[2], ip_arr[3]};

    for (int i = 0; i < 4; i++) {

        for (int k = 0; k < 8; k++) {

            if ((mask_arr[i] >> (7-k)) % 2 == 0) {
                tmpip[i] |= 1 << (7-k);
            }
        }
    }

    printf("%d.%d.%d.%d", tmpip[0], tmpip[1], tmpip[2], tmpip[3]);

    printf("\n");

    // ------------

    printf("smallest IP-Adress: ");

    printf("%d.%d.%d.%d", ip_arr[0] & mask_arr[0], ip_arr[1] & mask_arr[1], ip_arr[2] & mask_arr[2], (ip_arr[3] & mask_arr[3]) + 1);

    printf("\n");

    // ------------

    printf("biggest IP-Adresse: ");
    printf("%d.%d.%d.%d", tmpip[0], tmpip[1], tmpip[2], tmpip[3]-1);
    printf("\n");

    // ------------
    
    printf("number of possible addresses: ");

    int possible_addresses = own_pow(2, 32-mask) - 2;
    printf("2 ^ %d - 2 = %d", 32 - mask, possible_addresses);

    printf("\n");
}

void main()
{
    unsigned char ip_arr[] = {1, 2, 3, 127};
    int mask = 28;

    print(ip_arr, mask);
    printf("\n");
}