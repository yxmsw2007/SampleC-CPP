typedef struct _Post
{
    void (*do)(struct _Post* pPost);
}Post;

typedef struct _Command
{
    void* pData;
    void (*exe)(struct _Command* pCommand);
}Command;

void post_ext(struct _Command* pCommand)
{
    assert(NULL != pCommand);
    (Post*)(pCommand->pData)->do((Post*)(pCommand->pData));
    return;
}

typedef struct _Boss
{
    Command* pCommand;
    void (*call)(struct _Boss* pBoss);
}Boss;

void boss_call(struct _Boss* pBoss)
{
    assert(NULL != pBoss);
    pBoss->pCommand->exe(pBoss->pCommand);
    return;
}
