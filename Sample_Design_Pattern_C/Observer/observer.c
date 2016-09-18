#define     MAX_BINDING_NUMBER  10

typedef struct _Object
{
    observer* pObserverList[MAX_BINDING_NUMBER];
    int number;
    void (*notify)(struct _Object* pObject);
    void (*add_observer)(observer* pObserver);
    void (*del_observer)(observer* pObserver);
}Object;

typedef struct _Observer
{
    Object* pObject;
    void (*update)(struct _Observer* pObserver);
}Observer;

void bind_observer_to_object(Observer* pObserver, Object* pObject)
{
    assert(NULL != pObserver && NULL != pObject);
    pObserver->pObject = pObject;
    pObject->add_observer(pObserver);
}

void unbind_observer_from_object(Observer* pObserver, Object* pObject)
{
    assert(NULL != pObserver && NULL != pObject);
    pObject->del_observer(observer* pObserver);
    memset(pObserver, 0, sizeof(Observer));
}

void notify(struct _Object* pObject)
{
    Observer* pObserver;
    int index;
    assert(NULL != pObject);
    for (index = 0; index < pObject->number; index++) {
        pObserver = pObject->pObserverList[index];
        pObserver->update(pObserver);
    }
}
