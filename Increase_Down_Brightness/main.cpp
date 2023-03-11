#include <iostream>
#include "ImageProcessing.h"

int main(){
    int imgWidth; int imgHeight; int imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];
    // const char imgName[] = "lena512.bmp";
    // const char newImgName[] = "lena_512_1.bmp";
    // const char newImgName[] = "lena_512_2.bmp";
    // const char newImgName[] = "lena_512_3.bmp";
    // const char newImgName[] = "lena_darkened50.bmp";
    // const char newImgName[] = "lena_darkened150.bmp";
    const char newImgName[] = "lena_darkened200.bmp";

    ImageProcessing *myImage = new ImageProcessing(imgName,
                                 newImgName,
                                 &imgHeight,
                                 &imgWidth,
                                 &imgBitDepth,
                                 &imgHeader[0],
                                 &imgColorTable[0],
                                 &imgInBuffer[0],
                                 &imgOutBuffer[0]);
    myImage->readImage();
    // myImage->brightnessUp(imgInBuffer,imgOutBuffer,_512by512_IMG_SIZE,50);
    // myImage->brightnessUp(imgInBuffer,imgOutBuffer,_512by512_IMG_SIZE,150);
    // myImage->brightnessUp(imgInBuffer,imgOutBuffer,_512by512_IMG_SIZE,200);
    // myImage->brightnessDown(imgInBuffer,imgOutBuffer,_512by512_IMG_SIZE,50);
    //  myImage->brightnessDown(imgInBuffer,imgOutBuffer,_512by512_IMG_SIZE,150);
     myImage->brightnessDown(imgInBuffer,imgOutBuffer,_512by512_IMG_SIZE,200);

    myImage->writeImage();

    std::cout<<"Success!"<<std::endl;
    std::cout<<"Image Height : "<<imgHeight<<std::endl;
    std::cout<<"Image Width : "<<imgWidth<<std::endl;
    return 0;
}


