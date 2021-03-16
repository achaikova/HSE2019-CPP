# BMP processing
- An application that rotates rectangular BMP file 90 degrees clockwise and saves the result to a separate file.
## Console Application
- The application starts with the following command:
```
./BMP rotate ‹in-bmp› ‹out-bmp›
```
- `in-bmp` - name of the input file with the image
- `out-bmp` - output file name of the image
## Main Functions
- `load_bmp` - image loading
- `rotate` - rotate image
- `save_bmp` - image saving