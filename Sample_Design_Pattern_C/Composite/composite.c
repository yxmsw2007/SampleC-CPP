typedef struct _Object
{
    struct _Object** ppObject;
    int number;
    void (*operate)(struct _Object* pObject);
}Object;

void operate_of_parent(struct _Object* pObject)
{
    int index;
    assert(NULL != pObject);
    assert(NULL != pObject->ppObject && 0 != pObject->number);
    for (index = 0; index < pObject->number; index++) {
        pObject->ppObject[index]->operate(pObject->ppObject[index]);
    }
}

void operate_of_child(struct _Object* pObject)
{
    assert(NULL != pObject);
    printf("child node!\n");
}

void process(struct Object* pObject)
{
    assert(NULL != pObject);
    pObject->operate(pObject);
}
