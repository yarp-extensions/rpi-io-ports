//
// Created by jonb on 20.1.2019.
//

#pragma once

#include <appbase/application.hpp>
#include <boost/exception/diagnostic_information.hpp>

namespace bpo = boost::program_options;
using bpo::options_description;
using bpo::variables_map;

class RaspberryPiPorts : public appbase::plugin<RaspberryPiPorts> {
public:
    RaspberryPiPorts();
    virtual ~RaspberryPiPorts();
    APPBASE_PLUGIN_REQUIRES();
    virtual void set_program_options(options_description& cli, options_description& cfg) override;
    void plugin_initialize(const variables_map& options);
    void plugin_startup();
    void plugin_shutdown();
private:
    int example;
};


