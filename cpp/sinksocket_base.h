#ifndef SINKSOCKET_BASE_IMPL_BASE_H
#define SINKSOCKET_BASE_IMPL_BASE_H

#include <boost/thread.hpp>
#include <ossie/Component.h>
#include <ossie/ThreadedComponent.h>

#include <bulkio/bulkio.h>
#include "struct_props.h"

class sinksocket_base : public Component, protected ThreadedComponent
{
    public:
        sinksocket_base(const char *uuid, const char *label);
        ~sinksocket_base();

        void start() throw (CF::Resource::StartError, CORBA::SystemException);

        void stop() throw (CF::Resource::StopError, CORBA::SystemException);

        void releaseObject() throw (CF::LifeCycle::ReleaseError, CORBA::SystemException);

        void loadProperties();

    protected:
        // Member variables exposed as properties
        double total_bytes;
        float bytes_per_sec;
        std::vector<Connection_struct> Connections;
        std::vector<ConnectionStat_struct> ConnectionStats;

        // Ports
        bulkio::InOctetPort *dataOctet_in;
        bulkio::InCharPort *dataChar_in;
        bulkio::InShortPort *dataShort_in;
        bulkio::InUShortPort *dataUshort_in;
        bulkio::InLongPort *dataLong_in;
        bulkio::InULongPort *dataUlong_in;
        bulkio::InFloatPort *dataFloat_in;
        bulkio::InDoublePort *dataDouble_in;

    private:
};
#endif // SINKSOCKET_BASE_IMPL_BASE_H
