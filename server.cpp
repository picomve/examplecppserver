#include "httplib.h"
#include <iostream>

int main() {
    // httplib::Server sınıfından bir sunucu nesnesi oluştur
    httplib::Server svr;

    // Kök ("/") yoluna gelen GET isteklerini yakala
    svr.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        std::cout << "Sunucuya '/' isteği geldi." << std::endl;
        // İstemciye gönderilecek yanıtı ayarla
        res.set_content("Merhaba, 'deneme' Sunucusu!", "text/plain");
    });

    // "/durdur" yoluna gelen GET isteklerini yakala
    svr.Get("/durdur", [&](const httplib::Request& req, httplib::Response& res) {
        std::cout << "Sunucu durduruluyor..." << std::endl;
        res.set_content("Sunucu durduruluyor.", "text/plain");
        // Sunucuyu durdurma çağrısı
        svr.stop();
    });

    // Sunucuyu 8080 portunda dinlemeye başla
    std::cout << "Sunucu http://localhost:8080/ adresinde çalışıyor. Durdurmak için http://localhost:8080/durdur adresine gidin." << std::endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}
