
void shellcode()
{
    __asm__(
        "xor %eax, %eax\n\t"
        "pushl %eax\n\t"
        "push $0x68732f2f\n\t"
        "push $0x6e69622f\n\t"
        "movl %esp, %ebx\n\t"
        "pushl %eax\n\t"
        "pushl %ebx\n\t"
        "movl %esp, %ecx\n\t"
        "cltd\n\t"
        "movb $0xb, %al\n\t"
        "int $0x80\n\t"
            );
}


int main(int argc, char **argv)
{
    shellcode();
    return 0;
}
