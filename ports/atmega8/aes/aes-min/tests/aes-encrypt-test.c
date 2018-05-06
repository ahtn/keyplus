
#include "aes.h"
#include "aes-print-block.h"

#include <string.h>
#include <stdbool.h>


static const uint8_t key_0[AES128_KEY_SIZE] =
{
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static const uint8_t plain_0[AES128_KEY_SIZE] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static const uint8_t encrypt_0_ref[AES128_KEY_SCHEDULE_SIZE] =
{
    0x0e, 0xdd, 0x33, 0xd3, 0xc6, 0x21, 0xe5, 0x46, 0x45, 0x5b, 0xd8, 0xba, 0x14, 0x18, 0xbe, 0xc8
};

static bool encrypt_test(const uint8_t p_key[AES128_KEY_SIZE],
                              const uint8_t p_plain[AES_BLOCK_SIZE],
                              const uint8_t p_encrypted[AES_BLOCK_SIZE],
                              const char * p_id, bool use_otfks)
{
    uint8_t key_schedule[AES128_KEY_SCHEDULE_SIZE];
    uint8_t block[AES_BLOCK_SIZE];
    uint8_t otfks_decrypt_start_key[AES128_KEY_SIZE];
    uint8_t key_work[AES128_KEY_SIZE];

    if (use_otfks)
    {
        memcpy(otfks_decrypt_start_key, p_key, AES128_KEY_SIZE);
        aes128_otfks_decrypt_start_key(otfks_decrypt_start_key);
    }
    else
    {
        aes128_key_schedule(key_schedule, p_key);
    }

    memcpy(block, p_plain, AES_BLOCK_SIZE);
    if (use_otfks)
    {
        memcpy(key_work, p_key, AES128_KEY_SIZE);
        aes128_otfks_encrypt(block, key_work);
    }
    else
    {
        aes128_encrypt(block, key_schedule);
    }

    printf("Encrypt %s output:\n", p_id);
    print_block_hex(block, AES_BLOCK_SIZE);

    if (memcmp(block, p_encrypted, AES_BLOCK_SIZE) != 0)
        return 0;

    if (use_otfks)
    {
        memcpy(key_work, otfks_decrypt_start_key, AES128_KEY_SIZE);
        aes128_otfks_decrypt(block, key_work);
    }
    else
    {
        aes128_decrypt(block, key_schedule);
    }

    printf("Decrypt %s output:\n", p_id);
    print_block_hex(block, AES_BLOCK_SIZE);
    printf("\n");

    return (memcmp(block, p_plain, AES_BLOCK_SIZE) == 0);
}

int main(int argc, char **argv)
{
    bool    is_okay;

    (void)argc;
    (void)argv;

    is_okay = encrypt_test(key_0, plain_0, encrypt_0_ref, "0", false);
    if (!is_okay)
        return 1;
    is_okay = encrypt_test(key_0, plain_0, encrypt_0_ref, "0 OTFKS", true);
    if (!is_okay)
        return 1;
    return 0;
}
