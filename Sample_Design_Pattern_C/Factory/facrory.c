#define LEATHER_TYPE 0x01
#define RUBBER_TYPE  0x02

typedef struct _Shoe
{
    int type;
    void (*print_shoe)(struct _Shoe*);
}Shoe;

void print_leather_shoe(struct _Shoe* pShoe)
{
    assert(NULL != pShoe);
    printf("This is a leather show!\n");
}

void print_rubber_shoe(struct _Shoe* pShoe)
{
    assert(NULL != pShoe);
    printf("This is a rubber shoe!\n");
}

Shoe* manufacture_new_shoe(int type)
{
    assert(LEATHER_TYPE == type || RUBBER_TYPE == type);

    Shoe* pShoe = (Shoe*)malloc(sizeof(Shoe));
    assert(NULL != pShoe);

    memset(pShoe, 0, sizeof(Shoe));
    if (LEATHER_TYPE == type) {
        pShoe->type == LEATHER_TYPE;
        pShoe->print_shoe = print_leather_shoe;
    }
    else
    {
        pShoe->type == RUBBER_TYPE;
        pShoe->print_shoe = print_rubber_shoe;
    }
    return pSHoe;
}
