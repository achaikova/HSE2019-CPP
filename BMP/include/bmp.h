#ifndef BMP_BMP_H
#define BMP_BMP_H

typedef int LONG;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned char BYTE;

typedef struct tagBITMAPFILEHEADER {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER;

typedef struct rgb {
    BYTE red;
    BYTE green;
    BYTE blue;
} image;

typedef struct BMP{
    BITMAPFILEHEADER bmp;
    BITMAPINFOHEADER inf;
    BYTE **image;
} BMP_t;

void load_bmp(char *file_name, BMP_t *BMP);
void rotate_bmp(BMP_t *BMP, BMP_t *new_BMP);
void crop_bmp(BMP_t *BMP, BMP_t *crop_BMP, int x, int y, int w, int h);
void save_bmp(char *file_name, BMP_t *BMP);
void destroy_bmp(BMP_t *BMP);

#endif //BMP_BMP_H
