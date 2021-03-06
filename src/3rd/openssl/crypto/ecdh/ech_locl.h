
#ifndef HEADER_ECH_LOCL_H
# define HEADER_ECH_LOCL_H

# include <openssl/ecdh.h>

#ifdef  __cplusplus
extern "C" {
#endif

struct ecdh_method {
    const char *name;
    int (*compute_key) (void *key, size_t outlen, const EC_POINT *pub_key,
                        EC_KEY *ecdh, void *(*KDF) (const void *in,
                                                    size_t inlen, void *out,
                                                    size_t *outlen));
# if 0
    int (*init) (EC_KEY *eckey);
    int (*finish) (EC_KEY *eckey);
# endif
    int flags;
    char *app_data;
};

/*
 * If this flag is set the ECDH method is FIPS compliant and can be used in
 * FIPS mode. This is set in the validated module method. If an application
 * sets this flag in its own methods it is its responsibility to ensure the
 * result is compliant.
 */

# define ECDH_FLAG_FIPS_METHOD   0x1

typedef struct ecdh_data_st {
    /* EC_KEY_METH_DATA part */
    int (*init) (EC_KEY *);
    /* method specific part */
    ENGINE *engine;
    int flags;
    const ECDH_METHOD *meth;
    CRYPTO_EX_DATA ex_data;
} ECDH_DATA;

ECDH_DATA *ecdh_check(EC_KEY *);

#ifdef  __cplusplus
}
#endif

#endif                          /* HEADER_ECH_LOCL_H */
