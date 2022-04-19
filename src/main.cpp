#include "pipeline.h"
#include "cgi_callback.cpp"

int main() {
    bool isRunning = true;
    bool* isRunningPtr = &isRunning;

    PrintCallBack callback;
    Pipeline pipeline(isRunningPtr, &callback);


    JSONCgiGetCallback cgiGetCallback(&pipeline);
    CVPOSTCallback postCallback(&pipeline);
    JSONCGIHandler* fastCGIHandler = new JSONCGIHandler(&cgiGetCallback,
                                                        &postCallback,
                                                        "/tmp/sensorsocket");

    pipeline.run();

    return 0;
}