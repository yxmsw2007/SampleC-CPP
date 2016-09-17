typedef struct _Tofu
{
    int type;
    void (*eat)(struct _Visitor* pVisitor, struct _Tofu* pTofu);
}Tofu;

typedef struct _Visitor
{
    int region;
    void (*process)(struct _Tofu* pTofu, struct _Visitor* pVisitor);
}Visitor;

void eat(struct _Visitor* pVisitor, struct _Tofu* pTofu)
{
    assert(NULL != pVisitor && NULL != pTofu);
    pVisitor->process(pTofu, pVisitor);
}

void process(struct _Tofu* pTofu, struct _Visitor* pVisitor)
{
    assert(NULL != pTofu && NULL != pVisitor);
    if (pTofu->type == SPICY_FOOD && pVisitor->region == WEST ||
            pTofu->type == STRONG_SMELL_FOOD && pVisitor->region == EAST) {
        printf("I like this food!\n");
        return;
    }
    printg("I hate this food!\n");
}
