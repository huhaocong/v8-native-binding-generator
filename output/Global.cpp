#include "Global.h"

bool httpGetJson(const char* url, NanCallback*  onProgress, NanCallback*  onDone) {
}

bool httpGet(const char* url, NanCallback*  onProgress, NanCallback*  onDone) {
}

bool httpPost(const char* url, const char* data, NanCallback*  onProgress, NanCallback*  onDone) {
}

bool httpRequest(const char* url, const char* method, const char* header, const char* data, NanCallback*  onProgress, NanCallback*  onDone) {
}

int32_t setTimeout(int32_t duration, NanCallback*  onTimeout) {
}


int32_t globalGetNetworkTimeout()
{
}
void globalSetNetworkTimeout(int32_t networkTimeout)
{
}

