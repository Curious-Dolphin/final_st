#include "wobble_controller.h"

// ----------------------------------------------------------------------------------------------------------
Wobble_Controller::Wobble_Controller()
{
    m_uart = -1;
}

// ----------------------------------------------------------------------------------------------------------
void Wobble_Controller::init(char* serial_name)
{
    // Open serial
    std::cout << "Opening " << serial_name << std::endl;
    m_uart = open(serial_name, O_RDWR | O_NDELAY);
    if (m_uart < 0) {printf("Error %i from open: %s\n", errno, strerror(errno));}

    // Configure serial
    std::cout << "Configuring attributes for ttyACM0" << std::endl;
    struct termios options;
    tcgetattr(m_uart, &options);
    options.c_cflag = B115200 |     // Baud rate 115200.
                      CS8 |         // Character size mask 8bit.
                      CLOCAL |      // Ignore modem control lines.
                      CREAD;        // Enable receiver.

    // Flush serial
    tcflush(m_uart, TCIFLUSH);

    // Set configuration
    tcsetattr(m_uart, TCSANOW, &options);
    char hello_msg[] = "Hello";
    int rx_length = 0;

    // Synchronise
    std::cout << "--- SYNCH ---" << std::endl;
    while (strncmp(m_rx_buffer,hello_msg,5) != 0)
    {
        write(m_uart, hello_msg, 5);
        rx_length = read(m_uart, m_rx_buffer, 5);
        std::cout << "I say '" << m_rx_buffer << "', you say '" << hello_msg << "' - " << strncmp(m_rx_buffer,hello_msg,5) << std::endl;
        usleep(100*1000);
    }
    std::cout << "---- /// TTY READY /// ----" << std::endl;
}

// ----------------------------------------------------------------------------------------------------------
int Wobble_Controller::communicate(double w_gap)
{
    // Determine set point according to wobble parametre model
    double q_set = 0.1;
    double m_set = 2.0;
    double a_set = m_set * w_gap + q_set;
    if (a_set < 0.5) {a_set = 0.5;}

    // Determine analog value
    // % = m_par * a_set + q_par
    // 100%  <- 2.9 mm
    double q_ana = 0; // [V] @ AO = 0
    double m_ana = 100.0/2.9;
    int a_wob = cvRound(m_ana * a_set + q_ana);

    if (a_wob > 100)
        a_wob = 100;

    // Protocol message
    std::string ss = 'b' + ZeroPadNumber(a_wob,3) + 'e';

    // Write
    write(m_uart, ss.c_str(), 5);

    //std::cout << "EGM --- Wobble control A_wob = " << ss << std::endl;
    return a_wob;

}

// ----------------------------------------------------------------------------------------------------------
std::string Wobble_Controller::ZeroPadNumber(int num, int width)
{
    std::ostringstream ss;
    ss << std::setw( width ) << std::setfill( '0' ) << num;
    return ss.str();
}
