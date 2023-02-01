#include <iostream>
#include <assert.h>
#include "TelCoColorCoder.h"

std::string TelCoColorCoder::ColorPair::ToString() {
    std::string colorPairStr = MajorColorNames[majorColor];
    colorPairStr += " ";
    colorPairStr += MinorColorNames[minorColor];
    return colorPairStr;
}

TelCoColorCoder::ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor =
        (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    MinorColor minorColor =
        (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return ColorPair(majorColor, minorColor);
}

int TelCoColorCoder::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * numberOfMinorColors + minor + 1;
}