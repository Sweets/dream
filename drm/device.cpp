#include <iostream>

#include <xf86drm.h>

#include "device.hpp"

Device::Device(std::string path) {
    this->file_descriptor = open(path, O_RDONLY);
    assert(this->file_descriptor >= 0);

    // test if DRM device supports dumb buffers

    drmModeRes *resources;
    drmModeConnector *connector;

    resources = drmModeGetResources(this->file_descriptor);
    assert(resources);

    for (unsigned int index = 0; index < resources->count_connectors; index++) {
        connector = drmModeGetConnector(this->file_descriptor,
            resources->connectors[index]);

        if (!connector)
            continue;

        // prepare it?
        std::cout << "Connector found" << std::endl;

        drmModeFreeConnector(connector);
    }

    drmModeFreeResources(resources);
}
