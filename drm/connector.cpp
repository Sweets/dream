#include "connector.hpp"

Connector::Connector(drmModeConnector *connector) {
    if (!connector->count_modes)
        return;

    this->id = connector->connector_id;
    for (unsigned int index = 0; index < connector->count_modes; index++) {
        // modes
        this->modes.push_back(connector->modes[index]);
    }

    // get a CRTC for this connector
    // create framebuffer
}
