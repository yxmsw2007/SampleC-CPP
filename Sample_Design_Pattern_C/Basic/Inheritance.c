typedef struct _parent
{
    int data_parent;
}Parent;

typedef struct _Child
{
    struct _parent parent;
    int data_child;
}Child;
