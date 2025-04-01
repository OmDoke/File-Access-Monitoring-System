#include "email_alert.h"
#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

void sendEmailAlert(const std::string& filePath) {
    std::cout << "[ALERT] Unauthorized access detected: " << filePath << std::endl;

    try {
        io_service io;
        ip::tcp::resolver resolver(io);
        ip::tcp::resolver::query query("smtp.gmail.com", "587");
        ip::tcp::resolver::iterator endpoint = resolver.resolve(query);
        ip::tcp::socket socket(io);
        connect(socket, endpoint);

        std::string email_message =
            "From: your-email@gmail.com\r\n"
            "To: recipient-email@gmail.com\r\n"
            "Subject: Unauthorized File Access Alert\r\n"
            "\r\n"
            "ALERT: Unauthorized access detected at: " + filePath + "\r\n";

        socket.send(buffer("EHLO smtp.gmail.com\r\n"));
        socket.send(buffer("AUTH LOGIN\r\n"));
        socket.send(buffer("your_base64_encoded_email\r\n"));   
        socket.send(buffer("your_base64_encoded_password\r\n"));
        socket.send(buffer("MAIL FROM:<your-email@gmail.com>\r\n"));
        socket.send(buffer("RCPT TO:<recipient-email@gmail.com>\r\n"));
        socket.send(buffer("DATA\r\n"));
        socket.send(buffer(email_message + "\r\n.\r\n"));
        socket.send(buffer("QUIT\r\n"));

        std::cout << "[✔] Email Alert Sent Successfully!" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Email alert failed: " << e.what() << std::endl;
    }
}
