typedef struct _AssemblePersonalComputer
{
    void (*assemble_cpu)();
    void (*assemble_memory)();
    void (*assemble_harddisk)();
}AssemblePersonalComputer;

void assemble_intel_cpu()
{
    printf("intel cpu!\n");
}

void assemble_samsung_memory()
{
    printf("samsung memory!\n");
}

void assemble_hitachi_harddisk()
{
    printf("hitachi harddisk!\n");
}

void assemble_amd_cpu()
{
    printf("amd cpu!\n");
}

void assemble_kingston_memory()
{
    printf("kingston memory!\n");
}

void assemble_western_digital_harddisk()
{
    printf("western digital harddisk!\n");
}
