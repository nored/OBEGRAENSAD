// by /u/frumperino
// goodwires.org

#ifndef __FREKVENSPANEL_H
#define __FREKVENSPANEL_H

#include <Arduino.h>
#include <Adafruit_GFX.h>

class FrekvensPanel : public Adafruit_GFX
{
private:
    unsigned short _numPanels : 4;
    unsigned short _numPages : 4;
    unsigned short _activePage : 4;
    unsigned short _bitDepth : 4;
    unsigned short _pLatch;
    unsigned short _pClock;
    unsigned short _pData;
    unsigned short *buf;
    unsigned short _pageMask;
    unsigned short _addressMask;
    unsigned short _numWords;
    unsigned short _pageStride;
    unsigned short _numPixels;
    unsigned short _width;
    unsigned short _height;
    int lut[16][16] = {
        {23, 22, 21, 20, 19, 18, 17, 16, 7, 6, 5, 4, 3, 2, 1, 0},
        {24, 25, 26, 27, 28, 29, 30, 31, 8, 9, 10, 11, 12, 13, 14, 15},
        {39, 38, 37, 36, 35, 34, 33, 32, 55, 54, 53, 52, 51, 50, 49, 48},
        {40, 41, 42, 43, 44, 45, 46, 47, 56, 57, 58, 59, 60, 61, 62, 63},
        {87, 86, 85, 84, 83, 82, 81, 80, 71, 70, 69, 68, 67, 66, 65, 64},
        {88, 89, 90, 91, 92, 93, 94, 95, 72, 73, 74, 75, 76, 77, 78, 79},
        {103, 102, 101, 100, 99, 98, 97, 96, 119, 118, 117, 116, 115, 114, 113, 112},
        {104, 105, 106, 107, 108, 109, 110, 111, 120, 121, 122, 123, 124, 125, 126, 127},
        {151, 150, 149, 148, 147, 146, 145, 144, 135, 134, 133, 132, 131, 130, 129, 128},
        {152, 153, 154, 155, 156, 157, 158, 159, 136, 137, 138, 139, 140, 141, 142, 143},
        {167, 166, 165, 164, 163, 162, 161, 160, 183, 182, 181, 180, 179, 178, 177, 176},
        {168, 169, 170, 171, 172, 173, 174, 175, 184, 185, 186, 187, 188, 189, 190, 191},
        {215, 214, 213, 212, 211, 210, 209, 208, 199, 198, 197, 196, 195, 194, 193, 192},
        {216, 217, 218, 219, 220, 221, 222, 223, 200, 201, 202, 203, 204, 205, 206, 207},
        {231, 230, 229, 228, 227, 226, 225, 224, 247, 246, 245, 244, 243, 242, 241, 240},
        {232, 233, 234, 235, 236, 237, 238, 239, 248, 249, 250, 251, 252, 253, 254, 255}};

public:
    FrekvensPanel(int p_latch, int p_clock, int p_data, int bitDepth, int numPanels);
    FrekvensPanel(int p_latch, int p_clock, int p_data);

    void init(int p_latch, int p_clock, int p_data, int bitDepth, int numPanels);
    void clear();
    void scan();
    void writeDeepPixel(unsigned short x, unsigned short y, unsigned short value);

    boolean getPixel(int16_t x, int16_t y);

    unsigned short width();
    unsigned short height();

    void drawPixel(int16_t x, int16_t y, uint16_t color) override;
    void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) override;
    void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) override;
    void fillScreen(uint16_t color) override;

private:
};

#endif //__FREKVENSPANEL_H
