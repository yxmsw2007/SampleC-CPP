struct _Data;

typedef void (*process)(struct _Data* pData);

typedef struct _Data
{
    int value;
    process pProcess;
}Data;
