#include "ssh.hpp"

SSH::SSH()
{
    if (sodium_init() == -1) {
        printf("Failed to initialize libsodium\n");
        return;
    }
    // Generate a new keypair
    crypto_box_keypair(PublicKey, PrivateKey);
    Comment = "None";
    Passphrase = "Default";
}

SSH::SSH(const char *Comment, const char *Passphrase)
{
    // Generate a new keypair
    this->Comment = Comment;
    this->Passphrase = Passphrase;
    this->generateKeyPair(this->Comment, this->Passphrase);
}
void SSH::generateKeyPair(const char *Comment, const char *Passphrase)
{
    // Generate a new keypair
    crypto_box_keypair(PublicKey, PrivateKey);

}
