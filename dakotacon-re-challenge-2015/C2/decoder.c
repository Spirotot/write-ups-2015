#include <stdio.h>
#include <inttypes.h>
#include <string.h>

uint16_t rotate_left(uint16_t num, uint16_t bits)
{
  return ((num << bits) | (num >> (16 -bits)));
} 

uint16_t rotate_right(uint16_t num, uint16_t bits)
{
  return ((num >> bits) | (num << (16 -bits)));
}

int main(void)
{
    char buf[] = "\x96\xd6\x86\xc6" \
                "\xab\x7b\x73\x99" \
                "\xc0\xcc\xd0\xad" \
                "\xca\xd0\x84\xbe" \
                "\x67\x69\x65\x67" \
                "\xba\x39\xa3\xaf" \
                "\xd8\x5b\x17\xdd" \
                "\xae\xc8\xae\x4c" \
                "\x06\x74\xd6\x16" \
                "\x4b\x63\x73\x19" \
                "\xbd\xb5\x00\x00";

    int r = 12;
    int i = 0;
    uint16_t tmp = 0;
    for (r = 12; r > 0; r--)
    {
        memcpy(&tmp, &buf[i], 2);
        printf("%x", tmp);

        tmp = rotate_right(tmp, r);

        memcpy(&buf[i], &tmp, 2);

        i += 2;

        memcpy(&tmp, &buf[i], 2);

        printf("%x\n", tmp);

        tmp = rotate_right(tmp, r);

        memcpy(&buf[i], &tmp, 2);


        i += 2;
    }

    printf("%s\n", buf);

    return 0;
}

