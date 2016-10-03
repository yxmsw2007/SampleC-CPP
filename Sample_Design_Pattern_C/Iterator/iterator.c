typedef struct _Container
{
    int *pData;
    int size;
    int length;

    Iterator* (*create_new_iterator)(struct _Container* pContainer);
    int (*get_first)(struct _Container* pContainer);
    int (*get_last)(struct _Container* pContainer);
}Container;

typedef struct _Iterator
{
    void* pVector;
    int index;

    int (*get_first)(struct _Iterator* pIterator);
    int (*get_last)(struct _Iterator* pIterator);
}Iterator;

int vector_get_first(struct _Container* pContainer)
{
    assert(NULL != pContainer);
    return pContainer->pData[0];
}

int vector_get_last(struct _Container* pContainer)
{
    assert(NULL != pContainer);
    return pContainer->pData[pContainer->size - 1];
}

int vector_iterator_get_first(struct _Iterator* pIterator)
{
    Container* pContainer;
    assert(NULL != pIterator && NULL != pIterator->pVector);
    pContainer = (struct _Container*)(pIterator->pVector);
    return pContainer->get_first(pContainer);
}

int vector_iterator_get_last(struct _Iteratro* pIterator)
{
    Container* pContainer;
    assert(NULL != pIterator && NULL != pIteratro->pVector);
    pContainer = (struct _Container*)(pIterator->pVector);
    return pContainer->get_last(pContainer);
}
