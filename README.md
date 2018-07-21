
#  Harvest development tree

Harvest is a PoS-based cryptocurrency.

HC is dependent upon libsecp256k1 by sipa, the sources for which can be found here:
https://github.com/bitcoin/secp256k1

Total POW: 10,000 Blocks
POW Reward: 100 HC per Block
POS Reward: 1 HC (HiPOS)
Block Spacing: 60 Seconds
Diff Retarget: 24 Blocks
Maturity: 188 Blocks
Stake Minimum Age: 8 Hours

40 MegaByte Maximum Block Size (40X Bitcoin Core)

Port: 12116
RPC Port: 12117

Magic Bytes: 0x1f 0x22 0x05 0x31

HC includes an Address Index feature, based on the address index API (searchrawtransactions RPC command) implemented in Bitcoin Core but modified implementation to work with the HC codebase (PoS coins maintain a txindex by default for instance).

Initialize the Address Index By Running with -reindexaddr Command Line Argument.  It may take 10-15 minutes to build the initial index.


