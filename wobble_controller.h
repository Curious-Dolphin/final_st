#ifndef WOBBLE_CONTROLLER_H
#define WOBBLE_CONTROLLER_H

#include "common/common.h"
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

class Wobble_Controller
{
public:
    Wobble_Controller();
    void init(char* serial_name);
    int communicate(double w_gap);

private:
    std::string ZeroPadNumber(int num, int width);

    int         m_uart {-1};
    char        m_rx_buffer[10];
};

#endif // WOBBLE_CONTROLLER_H
