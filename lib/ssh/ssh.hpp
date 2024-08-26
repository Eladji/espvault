#include <stdio.h>
#include <string.h>
#include "sodium.h"
#include "mbedtls/aes.h"
#include "mbedtls/md.h"
#pragma once
class SSH
{
    private:
        unsigned char PrivateKey[crypto_box_SECRETKEYBYTES];
        unsigned char PublicKey[crypto_box_PUBLICKEYBYTES];
        const char *Comment;
        const char *Passphrase;
        unsigned char encrypted_private_key[crypto_sign_SECRETKEYBYTES + 16];  // Extra space for padding
        unsigned char key[32];  // AES-256 key size
        unsigned char iv[16];   // AES block size
        mbedtls_aes_context aes;
    public:
        SSH();
        SSH(const char *Comment= "None", const char *Passphrase = "Default");
        void setComment(const char *Comment);// Sets the comment
        void setPassphrase(const char *Passphrase);// Sets the passphrase
        void setPublicKey(const unsigned char *PublicKey);// Sets the public key
        void setPrivateKey(const unsigned char *PrivateKey);// Sets the private key
        const char *getComment();// Returns the comment
        const char *getPassphrase();// Returns the passphrase
        const unsigned char *getPublicKey();// Returns the public key
        const unsigned char *getPrivateKey(); // Returns the private key
        void generateKeyPair(const char *Comment, const char *Passphrase); // Generates a new keypair
        char encryptPkey(const char *Passphrase); // Encrypts the private key with a passphrase
        //bool checkPkey(const char *Passphrase); // Checks if the passphrase is correct or corruption
        char decryptPkey(const char *Passphrase); // Decrypts the private key with a passphrase
};