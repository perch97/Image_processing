#include <iostream>
#include "ImageProcessing.h"

int main(){
    float imgHist[NO_OF_GRAYLEVELS];
    int imgWidth; int imgHeight; int imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];
    const char imgName[] = "lena512.bmp";

    const char newImgName[] = "lena_eqz.bmp";

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
    myImage->equalizeHistogram(imgInBuffer,imgOutBuffer,imgHeight,imgWidth);        
    myImage->writeImage();

    std::cout<<"Success!"<<std::endl;
    std::cout<<"Image Height : "<<imgHeight<<std::endl;
    std::cout<<"Image Width : "<<imgWidth<<std::endl;
    return 0;
}


