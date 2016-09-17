typedef struct _Apple
{
    void (*print_apple)();
}Apple;

typedef struct _Grape
{
    void (*print_grape)();
}Grape;

void print_white_apple()
{
    printf("white apple!\n");
}

void print_red_apple()
{
    printf("red apple!\n");
}

void print_white_grape()
{
    printf("white grape!\n");
}

void print_red_grape()
{
    printf("red grape!\n");
}

typedef struct _FruitShop
{
    Apple* (*sell_apple)();
    Grape* (*sell_grape)();
}FruitShop;

Apple* sell_white_apple()
{
    Apple* pApple = (Apple*)malloc(sizeof(Apple));
    assert(NULL != pApple);
    pApple->print_apple = print_white_apple;
    return pApple;
}

Grape* sell_white_grape()
{
    Grape* pGrape = (Grape*)malloc(sizeof(Grape));
    assert(NULL != pGrape);
    pGrape->print_grape = print_white_grape;
    return pGrape;
}

Apple* sell_red_apple()
{
    Apple* pApple = (Apple*)malloc(sizeof(Apple));
    assert(NULL != pApple);
    pApple->print_apple = print_red_apple;
    return pApple;
}

Grape* sell_red_grape()
{
    Grape* pGrape = (Grape*)malloc(sizeof(Grape));
    assert(NULL != pGrape);
    pGrape->print_grape = print_red_grape;
    return pGrape;
}

FruitShop* create_fruit_shop(int color)
{
    FruitShop* pFruitShop = (FruitShop*)malloc(sizeof(FruitShop));
    assert(NULL != pFruitShop);
    if (WHITE == color) {
        pFruitShop->sell_apple = sell_white_apple;
        pFruitShop->sell_grape = sell_white_grapde;
    }
    else
    {
        pFruitShop->sell_apple = sell_red_apple;
        pFruitShop->sell_grape = sell_red_grape;
    }
    return pFruitShop;
}
