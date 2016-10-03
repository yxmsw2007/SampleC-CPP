typedef struct _Leader
{
    struct _Leader* next;
    int account;
    int (*request)(struct _Leader* pLeader, int num);
}Leader;

void set_account(struct _Leader* pLeader, int account)
{
    assert(NULL != pLeader);
    pLeader->account = account;
}

void set_next_leader(const struct _Leader, struct _Leader* next)
{
    assert(NULL != pLeader && NULL != next);
    pLeader->next = next;
}

int request_for_manager(struct _Leader* pLeader, int num)
{
    assert(NULL != pLeader && 0 != num);
    if (num < 100000) {
        return 1;
    }
    else if (pLeader->next) {
        return pLeader->next->request(pLeader->next, num);
    }
    else
    {
        return 0;
    }
}
