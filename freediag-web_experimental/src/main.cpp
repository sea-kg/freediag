#include <string.h>
#include <iostream>
#include <algorithm>
#include <wsjcpp_core.h>
#include <wsjcpp_light_web_http_handler_rewrite_folder.h>

int main(int argc, const char* argv[]) {
    int nDefaultWebPort = 5991;
    if (argc == 1) {
        // ok
    } else if (argc == 2) {
        nDefaultWebPort = atoi(argv[1]);
    } else {
        std::cout 
            << std::endl 
            << "  Usage: " << argv[0] << " <port>" << std::endl
            << " where port must be 1..65535 (default: " << nDefaultWebPort << ")"
            << std::endl 
        ;
    }

    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_NAME);
    std::string appVersion = std::string(WSJCPP_VERSION);
    if (!WsjcppCore::dirExists(".logs")) {
        WsjcppCore::makeDir(".logs");
    }
    WsjcppLog::setPrefixLogFile("freediag-web");
    WsjcppLog::setLogDirectory(".logs");


    std::cout << "Open url in your browser: http://localhost:" << nDefaultWebPort << "/" << std::endl;
    WsjcppLightWebServer httpServer;
    httpServer.setPort(nDefaultWebPort);
    httpServer.setMaxWorkers(1);
    httpServer.addHandler(new WsjcppLightWebHttpHandlerRewriteFolder("/", "./web"));
    httpServer.startSync();
    return 0;
}

