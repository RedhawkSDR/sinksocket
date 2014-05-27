/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This file is part of REDHAWK Basic Components sinksocket.
 *
 * REDHAWK Basic Components sinksocket is free software: you can redistribute it and/or modify it under the terms of
 * the GNU Lesser General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * REDHAWK Basic Components sinksocket is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with this
 * program.  If not, see http://www.gnu.org/licenses/.
 */
#include "sinksocket_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

sinksocket_base::sinksocket_base(const char *uuid, const char *label) :
    Resource_impl(uuid, label),
    ThreadedComponent()
{
    loadProperties();

    dataOctet_in = new bulkio::InOctetPort("dataOctet_in");
    addPort("dataOctet_in", dataOctet_in);
    dataChar_in = new bulkio::InCharPort("dataChar_in");
    addPort("dataChar_in", dataChar_in);
    dataShort_in = new bulkio::InShortPort("dataShort_in");
    addPort("dataShort_in", dataShort_in);
    dataUshort_in = new bulkio::InUShortPort("dataUshort_in");
    addPort("dataUshort_in", dataUshort_in);
    dataLong_in = new bulkio::InLongPort("dataLong_in");
    addPort("dataLong_in", dataLong_in);
    dataUlong_in = new bulkio::InULongPort("dataUlong_in");
    addPort("dataUlong_in", dataUlong_in);
    dataFloat_in = new bulkio::InFloatPort("dataFloat_in");
    addPort("dataFloat_in", dataFloat_in);
    dataDouble_in = new bulkio::InDoublePort("dataDouble_in");
    addPort("dataDouble_in", dataDouble_in);
}

sinksocket_base::~sinksocket_base()
{
    delete dataOctet_in;
    dataOctet_in = 0;
    delete dataChar_in;
    dataChar_in = 0;
    delete dataShort_in;
    dataShort_in = 0;
    delete dataUshort_in;
    dataUshort_in = 0;
    delete dataLong_in;
    dataLong_in = 0;
    delete dataUlong_in;
    dataUlong_in = 0;
    delete dataFloat_in;
    dataFloat_in = 0;
    delete dataDouble_in;
    dataDouble_in = 0;
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void sinksocket_base::start() throw (CORBA::SystemException, CF::Resource::StartError)
{
    Resource_impl::start();
    ThreadedComponent::startThread();
}

void sinksocket_base::stop() throw (CORBA::SystemException, CF::Resource::StopError)
{
    Resource_impl::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void sinksocket_base::releaseObject() throw (CORBA::SystemException, CF::LifeCycle::ReleaseError)
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Resource_impl::releaseObject();
}

void sinksocket_base::loadProperties()
{
    addProperty(connection_type,
                "server",
                "connection_type",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(ip_address,
                "ip_address",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(port,
                "port",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(status,
                "status",
                "",
                "readonly",
                "",
                "external",
                "configure");

    addProperty(total_bytes,
                "total_bytes",
                "",
                "readonly",
                "",
                "external",
                "configure");

    addProperty(bytes_per_sec,
                "bytes_per_sec",
                "",
                "readonly",
                "",
                "external",
                "configure");

    addProperty(byte_swap,
                0,
                "byte_swap",
                "",
                "readwrite",
                "",
                "external",
                "configure");

}


