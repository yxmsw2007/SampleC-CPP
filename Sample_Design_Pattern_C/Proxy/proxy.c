typedef struct _PC_Client
{
    void (*request)();
}PC_Client;

void ftp_request()
{
    printf("request from ftp!\n");
}

void http_request()
{
    printf("request from http!\n");
}

void smtp_request()
{
    printf("request from smtp!\n");
}

typedef struct _Proxy
{
    PC_Client* pClient;
}Proxy;

void process(Proxy* pProxy)
{
    assert(NULL != pProxy);
    pProxy->pClient->request();
}
