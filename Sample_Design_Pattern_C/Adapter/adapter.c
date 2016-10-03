typedef struct _Adaptee
{
    void (*real_process)(struct _Adaptee* pAdaptee);
}Adaptee;

typedef struct _Adapter
{
    void* pAdaptee;
    void (*transform_process)(struct _Adapter* pAdapter);
}Adapter;
