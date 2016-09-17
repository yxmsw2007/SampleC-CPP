typedef struct _DATA
{
    void* pData;
}DATA;

void* get_data()
{
    static DATA* pData = NULL;

    if (NULL != pData) {
        return pData;
    }
    pData = (DATA*)malloc(sizeof(DATA));
    assert(NULL != pData);
    return (void*)pData;
}
    
