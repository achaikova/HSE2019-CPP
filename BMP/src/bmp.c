#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>
#include <string.h>

void load_bmp(char *file_name, BMP_t *BMP) {
    FILE *f = fopen(file_name, "rb");

    fread(&BMP->bmp, 1, 14, f);
    fread(&BMP->inf, 1, 40, f);

    int width = BMP->inf.biWidth;
    int height = BMP->inf.biHeight;

    BMP->image = malloc(height * sizeof(BYTE * ));
    BMP->image[0] = malloc(3 * height * width * sizeof(BYTE));

    for (int i = 0; i < height; i++) {
        BMP->image[i] = BMP->image[0] + 3 * width * i;
    }

    int RowSize = (BMP->inf.biWidth * (LONG)
    sizeof(BYTE) * 24 + 31) / 32 * 4;
    int padding = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(BMP->image[i] + 3 * j, 3, sizeof(BYTE), f);
        }
        fread(&padding, 1, RowSize - width * 3, f);
    }

    fclose(f);
}

void rotate_bmp(BMP_t *BMP, BMP_t *new_BMP) {
    new_BMP->inf = BMP->inf;
    new_BMP->bmp = BMP->bmp;

    int width = BMP->inf.biWidth;
    int height = BMP->inf.biHeight;

    new_BMP->inf.biWidth = height;
    new_BMP->inf.biHeight = width;

    new_BMP->image = malloc(width * sizeof(BYTE * ));
    new_BMP->image[0] = malloc(3 * height * width * sizeof(BYTE));

    for (int i = 0; i < width; i++) {
        new_BMP->image[i] = new_BMP->image[0] + 3 * height * i;
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            memcpy(new_BMP->image[i] + 3 * j, BMP->image[j] + 3 * (width - i - 1), 3 * sizeof(BYTE));
        }
    }
}

void crop_bmp(BMP_t *BMP, BMP_t *crop_BMP, int x, int y, int w, int h) {

    crop_BMP->inf = BMP->inf;
    crop_BMP->bmp = BMP->bmp;

    crop_BMP->inf.biWidth = w;
    crop_BMP->inf.biHeight = h;
    crop_BMP->inf.biSizeImage = w * h;

    crop_BMP->image = malloc(h * sizeof(BYTE * ));
    crop_BMP->image[0] = malloc(3 * h * w * sizeof(BYTE));

    for (int i = y; i < h + y; i++) {
        crop_BMP->image[i] = crop_BMP->image[0] + 3 * w * i;
    }


    for (int i = y; i < y + h + 1; i++) {
        for (int j = x; j < x + w + 1; j++) {
            memcpy(crop_BMP->image[i - y] + 3 * (j - x), BMP->image[i] + 3 * j, 3 * sizeof(BYTE));
        }
    }
}


void save_bmp(char *file_name, BMP_t *BMP) {

    FILE *f = fopen(file_name, "wb");

    fwrite(&BMP->bmp, 14, 1, f);
    fwrite(&BMP->inf, 40, 1, f);

    int width = BMP->inf.biWidth;
    int height = BMP->inf.biHeight;

    int RowSize = (BMP->inf.biWidth * (LONG)
    sizeof(BYTE) * 24 + 31) / 32 * 4;
    int padding = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(BMP->image[i] + 3 * j, 3, sizeof(BYTE), f);
        }
        fwrite(&padding, 1, RowSize - width * 3, f);
    }

    fclose(f);
}

void destroy_bmp(BMP_t *BMP) {
    free(BMP->image[0]);
    free(BMP->image);
}