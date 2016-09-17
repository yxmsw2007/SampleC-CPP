typedef struct _Play
{
    void* pData;
    void (*start_play)(struct _Play* pPlay);
}Play;
