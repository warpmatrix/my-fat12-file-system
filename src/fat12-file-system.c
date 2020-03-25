#include <stdio.h>
#include <string.h>

#include "command.h"
#include "utils.h"

int init(unsigned char *ramFDD144);

int main() {
    unsigned char ramFDD144[SIZE];
    int res = init(ramFDD144);
    if (res == -1) {
        printf("Cannot find the disk\n");
        return 0;
    } else if (res != SIZE) {
        printf("File size doesn't match\n");
        return 0;
    }

    unsigned short clus = 0;
    char cmd[256];
    printf("cmd: ");
    while (scanf("%s", cmd) != EOF) {
        if (!strcmp(cmd, "dir")) {
            int res = listEnts(clus, ramFDD144);
        }
        else if (!strcmp(cmd, "cd"))
            changeDir(&clus, ramFDD144);
        printf("cmd: ");
    }

    return 0;
}

int init(unsigned char *ramFDD144) {
    int cnt = Read_ramFDD(ramFDD144, FILENAME);
    if (cnt != SIZE) return cnt;

    printf("Successfully Loaded!\n");
    printf("\n");

    printf("MBR info:\n");
    unsigned char block[BLOCKSIZE];
    Read_ramFDD_Block(ramFDD144, 0, block);
    Fat12Header mbr;
    parseMbr(block, &mbr);
    printMbrInfo(mbr);
    printf("\n");
    return 0;
}
