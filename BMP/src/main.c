#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]) {
    (void) argc;
    if (!strcmp(argv[1], "rotate")) {
        BMP_t BMP;
        load_bmp(argv[2], &BMP);
        BMP_t new_BMP;
        rotate_bmp(&BMP, &new_BMP);
        save_bmp(argv[3], &new_BMP);
        destroy_bmp(&BMP);
        destroy_bmp(&new_BMP);
    }
}