typedef struct _FoodStreet
{
    void (*eat)();
}FoodStreet;

typedef struct _ShopStreet
{
    void (*buy)();
}ShopStreet;

void buy()
{
    printf("buy here!\n");
}

typedef struct _BookStreet
{
    void (*read)();
}BookStreet;

void read()
{
    printf("read here!\n");
}

typedef struct _Plaza
{
    FoodStreet* pFoodStreet;
    ShopStreet* pShopStreet;
    BookStreet* pBookStreet;

    void (*play)(struct _Plaza* pPlaza);
}Plaza;

void play(struct _Plaza* pPlaza)
{
    assert(NULL != pPlaza);
    pPlaza->pFoodStreet->eat();
    pPlaza->pShopStreet->buy();
    pPlaza->pBookStreet->read();
}
