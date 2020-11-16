#include <cassert>
#include <iostream>

#include <fcntl.h>
#include <xf86drm.h>
#include <xf86drmMode.h>

#include "connector.hpp"
#include "device.hpp"

Device::Device(const char *path) {
    this->file_descriptor = open(path, O_RDONLY);
    assert(this->file_descriptor >= 0);
    // this assertion should probably not be here, the program will abort
    // if it fails...
    // but realistically, the user does not interface with dream, it determines
    // what devices to create itself

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

        Connector(connector); // eventually add this to a vector

        drmModeFreeConnector(connector);
    }

    drmModeFreeResources(resources);
}
