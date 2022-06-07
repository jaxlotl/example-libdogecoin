#include <stdbool.h>
#include <stdint.h>

// from ecc.c
extern void dogecoin_ecc_start();
extern void dogecoin_ecc_stop();

// from address.c
extern int generatePrivPubKeypair(char* wif_privkey, char* p2pkh_pubkey, bool is_testnet);
extern int generateHDMasterPubKeypair(char* wif_privkey_master, char* p2pkh_pubkey_master, bool is_testnet);
extern int generateDerivedHDPubkey(const char* wif_privkey_master, char* p2pkh_pubkey);
extern int verifyPrivPubKeypair(char* wif_privkey, char* p2pkh_pubkey, bool is_testnet);
extern int verifyHDMasterPubKeypair(char* wif_privkey_master, char* p2pkh_pubkey_master, bool is_testnet);
extern int verifyP2pkhAddress(char* p2pkh_pubkey, uint8_t len);

// from transaction.c
extern int start_transaction();
extern int save_raw_transaction(int txindex, const char* hexadecimal_transaction);
extern int add_utxo(int txindex, char* hex_utxo_txid, int vout);
extern int add_output(int txindex, char* destinationaddress, long double amount);
extern char* finalize_transaction(int txindex, char* destinationaddress, long double subtractedfee, long double out_dogeamount_for_verification, char* changeaddress);
extern char* get_raw_transaction(int txindex);
extern void clear_transaction(int txindex);
extern int sign_raw_transaction(int inputindex, char* incomingrawtx, char* scripthex, int sighashtype, long double amount, char* privkey);
extern int sign_transaction(int txindex, long double amounts[], char* script_pubkey, char* privkey);
extern int store_raw_transaction(char* incomingrawtx);
