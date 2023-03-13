#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_

static const int    _512by512_IMG_SIZE = 262144; //512*512
static const int BMP_COLOR_TABLE_SIZE  = 1024;
static const int BMP_HEADER_SIZE       = 54;
static const int MAX_COLOR             = 255;
static const int MIN_COLOR             = 0;
static const int WHITE                 = MAX_COLOR;
static const int BLACK                 = MIN_COLOR;
static const int NO_OF_GRAYLEVELS      = 255;


class ImageProcessing{
public:
    ImageProcessing(const char* _inImgName,
                                 const char* _outImgName,
                                 int* _height,
                                 int* _width,
                                 int* _bitDepth,
                                 unsigned char* _header,
                                 unsigned char* _colorTable,
                                 unsigned char* _inBuf,
                                 unsigned char* _outBuf);
    void readImage();
    void writeImage();
    void copyImgData(unsigned char* _srcBuf, unsigned char *_destBuf, int bufSize);
    void brightnessUp(             unsigned char* _inputImgData, 
                                   unsigned char* _outImgData, 
                                   int imgSize,
                                   int brightness);
    void binarizeImage(unsigned char* _inImgData, 
                                    unsigned char* _outImgData,
                                    int imgSize,
                                    int threshold);
    void brightnessDown(unsigned char* _inputImgData, 
                                   unsigned char* _outImgData, 
                                   int imgSize,
                                   int darkness);    
    void computeHistogram(unsigned char* _imgData, int imgRows,int imgCols,float hist[]);  
    void computeHistogram2(unsigned char* _imgData, int imgRows,int imgCols,float hist[], const char* histFile);            
    void equalizeHistogram(unsigned char* _inputImgData, unsigned char* _outputImgData, int imgRows, int imgCols);        
    void getImageNegative(unsigned char* _inImgData, unsigned char* _outImg, int imgWidth,int imgHeight);
    virtual ~ImageProcessing();

private:
    const char* inImgName;
    const char* outImgName;
    int* height;
    int* width;
    int* bitDepth;
    unsigned char* header;
    unsigned char* colorTable;
    unsigned char* inBuf;
    unsigned char* outBuf;
};
#endif  

