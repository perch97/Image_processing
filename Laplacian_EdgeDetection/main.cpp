#include <iostream>
#include "ImageProcessing.h"

int main(){

    // Mask lpMask;
    // signed char* tmp;
    // int i;

    float imgHist[NO_OF_GRAYLEVELS];
    int imgWidth; int imgHeight; int imgBitDepth;
    unsigned char imgHeader[BMP_HEADER_SIZE];
    unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
    unsigned char imgInBuffer[_512by512_IMG_SIZE];
    unsigned char imgOutBuffer[_512by512_IMG_SIZE];
    const char imgName[] = "lighthouse.bmp";
    const char newImgName[] = "lighthouse_laplace_pos.bmp";

    ImageProcessing *myImage = new ImageProcessing(imgName,
                                 newImgName,
                                 &imgHeight,
                                 &imgWidth,
                                 &imgBitDepth,
                                 &imgHeader[0],
                                 &imgColorTable[0],
                                 &imgInBuffer[0],
                                 &imgOutBuffer[0]);

    // lpMask.Rows=5;
    // lpMask.Cols=5;
    // lpMask.Data=(unsigned char*)malloc(25);

    // tmp = (signed char*)lpMask.Data;
    // for(i=0;i<25;i++)
    // {
    //     *tmp=-1;
    //     ++tmp;
    // }

    // tmp = (signed char*)lpMask.Data+13;
    // *tmp=24;


    myImage->readImage();

    myImage->setMask(3,3,LAPLACE_POS);
    myImage->Convolve2D(imgHeight,imgWidth,&myImage->myMask,imgInBuffer,imgOutBuffer);
    myImage->writeImage();

    std::cout<<"Success!"<<std::endl;
    std::cout<<"Image Height : "<<imgHeight<<std::endl;
    std::cout<<"Image Width : "<<imgWidth<<std::endl;
    return 0;
}


