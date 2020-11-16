#include "connector.hpp"

Connector::Connector(drmModeConnector *conn) {
    if (!conn->count_modes)
        return; // No modes available

    if (conn->connection != DRM_MODE_CONNECTED) {
        std::cout << "Unused connector found" << std::endl;
    } else {
        std::cout << "Used connector found" << std::endl;
    }

    this->id = conn->connector_id;
    for (unsigned int index = 0; index < conn->count_modes; index++) {
        // modes
        this->modes.push_back(conn->modes[index]);
    }

    // get a CRTC for this connector
    // create framebuffer
}
