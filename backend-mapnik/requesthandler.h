/*
 * Part of TIREX - a map tile rendering tool-chain for OpenStreetMap.
 * 
 * Originally written by Jochen Topf & Frederik Ramm; public domain.
 *
 * TIREX component: renderd (tile rendering daemon).
 */

/**
 * RequestHandler
 *
 * Superclass for classes that handle network requests.
 */

#ifndef requesthandler_included
#define requesthandler_included

#include <string>
#include <vector>

#include "networkrequest.h"
#include "networkresponse.h"
#include "debuggable.h"
#include "statusreceiver.h"

class RequestHandler : public Debuggable
{
    private:

    StatusReceiver *mpStatusReceiver;

    protected:

    void updateStatus(const char *fmt, ...) const;

    public:

    RequestHandler();
    void setStatusReceiver(StatusReceiver *sr) { mpStatusReceiver = sr; }
    virtual const std::string getRequestType() const = 0;
    virtual const NetworkResponse *handleRequest(const NetworkRequest *request) = 0;
};

#endif