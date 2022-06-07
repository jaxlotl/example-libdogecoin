# Implementing Libdogecoin
This repository contains an example of how to use libdogecoin in practice. In order to use the library, it must first be installed from the source code by executing the following command from the libdogecoin project directory:
```
TODO
```

Once the library is installed, any functions from libdogecoin that will be used in your project must be redeclared in a header file with the `extern` keyword, which should be included in any sources files that will call these functions. In the example files provided, all user-facing functions are declared within the file for reference, and are structured like so:
```c
#include <stdbool.h>
#include <stdint.h>

// from ecc.c
extern void dogecoin_ecc_start();
extern void dogecoin_ecc_stop();

// from address.c
extern int generatePrivPubKeypair(char* wif_privkey, char* p2pkh_pubkey, bool is_testnet);
extern int generateHDMasterPubKeypair(char* wif_privkey_master, char* p2pkh_pubkey_master, bool is_testnet);

// ...
```
_Note: if using any address functions which contain_ `bool` _as a parameter type, you will need to include the header_ `<stdbool.h>` _. If using_ `verifyP2pkhAddress()` _you will need to include the_ `<stdint.h>` _header which is responsible for the definition of the_ `uint8_t` _type._

To compile your project and link it with the libdogecoin static library, you can run the following commands, where the `-L` flag signifies the path to any extra required libraries (libsecp256k1.a and libsecp256k1_precomputed.a). In addition, the `-l` flags denote all libraries that are required for compilation. The required libraries are the following:
- dogecoin
- secp256k1
- secp256k1_precomputed
- m
- event

Altogether, the command to link and compile your project-- in its basic form-- will look similar to this:
```
gcc file.c -I./path/to/headers -L./path/to/libs -ldogecoin -lsecp256k1 -lsecp256k1_precomputed -lm -levent
```
A similar command can be found in the Makefile, which exports an executable called `test` that can be run with `./test `.
