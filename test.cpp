#include <iostream>

#include "drm/device.cpp"

int main() {
    /* drm shit */
    new Device("/dev/dri/card0");

    return 0;
}
