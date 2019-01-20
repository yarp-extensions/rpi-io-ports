//
// Created by jonb on 20.1.2019.
//
#include <appbase/application.hpp>
#include "inc/RaspberryPiPorts.h"
#include <iostream>


int main( int argc, char** argv ) {
    try {
        appbase::app().register_plugin<RaspberryPiPorts>();
        if( !appbase::app().initialize_plugins( argc, argv ) )
            return -1;
        appbase::app().startup();
        appbase::app().exec();
    } catch ( const boost::exception& e ) {
        std::cerr << boost::diagnostic_information(e) << "\n";
    } catch ( const std::exception& e ) {
        std::cerr << e.what() << "\n";
    } catch ( ... ) {
        std::cerr << "unknown exception\n";
    }
    std::cout << "exited cleanly\n";
    return 0;
}
