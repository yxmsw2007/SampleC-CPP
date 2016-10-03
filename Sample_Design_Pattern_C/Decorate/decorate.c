typedef struct _Object
{
    struct _Object* prev;
    void (*decorate)(struct _Object* pObject);
}Object;

void decorate(struct _Object* pObject)
{
    assert(NULL != pObject->prev);
    if (NULL != pObject) {
        pObject->prev->decorate(pObject->prev);
    }
    printf("normal decorate!\n");
}
