// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "txdb.h"
#include "main.h"
#include "uint256.h"


static const int nCheckpointSpan = 5000;

namespace Checkpoints
{
	typedef std::map<int, uint256> MapCheckpoints;

	//
	// What makes a good checkpoint block?
	// + Is surrounded by blocks with reasonable timestamps
	//   (no blocks before with a timestamp after, none after with
	//    timestamp before)
	// + Contains no strange transactions
	//
	static MapCheckpoints mapCheckpoints =
		boost::assign::map_list_of
		(0, uint256("0x0000ebc8051bff80f7946f4420efb219e66f66b89fdc1df0ed8a30b428bf0033"))
		(1045, uint256("0x098c3515912a25c16deab0390c43091505879078b7334f098222dd3bfa31b6ad"))
		(1954, uint256("0x1b9fc5db67f518272473649364583f560e5fd4ea7372d564c4ab2231a06fd2c4"))
		(2547, uint256("0xa154a82676f609dcd17e22c7ca4079916c4e4e2f4f64105318a4fad294484cc7"))
		(2978, uint256("0x14d413fcfa6396a3a538709ff66ac9a05329223c7a46d7f78b4f1834dd402f93"))
		(5489, uint256("0x674e9e168db0e3bc285ddab44e8199c8eb67a96525c94fc31ba4447d6cefd008"))
		(11458, uint256("0x7f8d98aa499e411f3e1be53ad75d8149b8d09656eb7df1e7540822cbf211754e"))
		(19745, uint256("0xabb199272fdecbf56a3af3bff7891d03cb34d51c1d404bce9b34a4d425834bff"))
		(28547, uint256("0x86ed3ab436ddc29d2735304633e2c6e76b20ed36a55d866bc06d390569df078e"))
		(36900, uint256("0x1be79a0933ef2c5424eda67ac927c78f540d38e73defa06b55d789338f89bcd9"))
		(49875, uint256("0xb4e775992616abd8534c5887d35851ee789ba26ce881bd7df2aae2801a605760"))
		(54208, uint256("0xdccf9542d6928cfdf67547d024696b68818dcd64cb2cb3ac325a98ce15a45406"))
		(67321, uint256("0xd5ed85a8727484b2b905890306f92996482935853be14740165432cf8db532ec"))
		(82123, uint256("0xdd4cd1b4a6279a67aaf6a9ccaae610215f02fd384c98b551eb16103b37bf83b6"))
		(127845, uint256("0x449d67f1a1a573636bcf0c3e25ae6923aac4a1bc2424576cf1b2db34500d147f"))
		(172698, uint256("0xde770660f42f02b7d7245bbb07a7bd5bd0c2c2881556c92aa6ac3bcd848003e0"))
		(212367, uint256("0x3d277d2f11cf6b2a984e81b0a60f40eae268e4e0628960c9471f4e12423bb220"))
		(259784, uint256("0xe422c202cd88430d776f01b926a928ae998c0357647e1627e501d0b224a48ebc"))
		(332453, uint256("0x97c57d3f26d2ab73e1faf0624aef639f6dec75dc56dfddeb17216ad86532b7e5"))
		(384201, uint256("0x2f716bb3aa37b23e0b483ed0fe265b81f332eaa5bf2b853446c786b1b2fea881"))
		(398729, uint256("0xb112dcd53c63545532b7b1b3d129e74242c53f7762cc0d32f9fc7b8a4d325ab9"))
		(414968, uint256("0xebc7ecb479cc0fede3a8d09d7928165b63b3781efec64e6c8f554a912f06776a"))
		(459277, uint256("0x063aada361f8dabb0db4cfc266e2a3489b1942dbf8562258bc55204a7abc4a8f"))
		(414968, uint256("0xebc7ecb479cc0fede3a8d09d7928165b63b3781efec64e6c8f554a912f06776a"))
		(491495, uint256("0x22ecb92a25ce0cfa2b6ddf663aca8280e8556cb9eb71565cdb00695806378782"))		
		(491498, uint256("0xd5b2660e6171842a58dadd9ce5806dc0129893fef2af409a706c841a8c85b81b"))
		(491499, uint256("0x17fded770a8145717c194dd438c7ebf26fae647551304e0c86e1cf6701ab2445"))
		(499648, uint256("0x56221484284abe3eaa8e8a3e91468eb0b53f0cbdd949701e3931e4106ceb95e5"))
		(499649, uint256("0x5370520ecce54ef67861cdaf361cd355898d85ad9dc5dd5f8126fce2a1dc9f29"))
		(499650, uint256("0x103353d0ceb497e9a407e25e6f2a478e0cb2c00d1ffdac07a72fa0a1882a9912"))
		(499651, uint256("0xd3e2cc18e9e5c4d110396c379d911371f71e513bd9a47a5908a5305fcc14c6a1"))
		(499807, uint256("0x869ccce8cb502e240024ac7016b143cf99118b0e6c703e637da7ed58e183256a"))
		(500000, uint256("0xb51988566028c9d4e826139edc6be504b61ba64e65452fb16a5e015f61d8325c"))
		(500109, uint256("0xdda9326eecf6560495196b8b5420ef1f93fe4fd042bc7a9f5782ad2ebccb5048"))
		(500166, uint256("0x26e818af30802725c41435153a453578b4ab0137b92f02c62e9b88728c7421fd"))
		(500431, uint256("0xabf2c19bc844be95870ced11b59beba8dba26f1992525df0aa6b13be6e9f4558"))
		(500697, uint256("0x61a86560bb87b99dd1097b487f62b18ca1cb4495e0b940407fd3272695fb69a7"))
		(500903, uint256("0x50da425d4e40afcb7a887839ea313bdb3a7c2eab98194a4bc9f213f88690d1c6"))
		(501078, uint256("0x2f9a0fc52425cbff960f75cbe39a2b08227a1377f1c94702876bd40179ce9709"))
		(501227, uint256("0xb5b68c3b7b132d57ea6be1b9925996de8ce422befd8dca91fbce402fe754c36a"))
		(503186, uint256("0xdc85593ed1ae00431b593ae29220d99d8195e038910db2cc71668bb064899dec"))
		(504319, uint256("0xcec4eff369667098174fbec5674393dd374e65402177f5f0e8dc049888420335"))
		(602514, uint256("0xd68f94e855de846e6f24b9daba21d5929f094fcc10d685d82e5876ca851a48e7"))
		(678322, uint256("0x63e2c62e454fdc310cfe15c22738e0430c5e70be44b343050012117647883288"))
		(724159, uint256("0x1454cf528ddaf71c4e9be520a1446394ccaf65e10e9a8eee89180f5f81a7cd92"))
		(789201, uint256("0xeb2ace12a28a8f189ead8287cdef7ff84defc1c7e7645c3513c7bd06c1fc99d2"))
		(837456, uint256("0x5f53729f1c377fc97deadb333c4873808eca7b835ad1ae2b125ee8b27e2e79a2"))
		(899784, uint256("0x215573c990eaa201ba6a0b6cd4903bc5c7ed4494df1fa785b9e26f17d74a76e2"))
		(951703, uint256("0xf8ba97b5421bfafc9438cfc1d7bf9a8ddc77f4260506dcb41524596d36018df3"))
		(1010230, uint256("0xfd03654996b027f5181c6377d52ba404a99046282b622a6faabdeb7644b8363a"))
		(1014449, uint256("0x3160f9e96f9d9ad48ea61ffcc3a1d80012e933c904325188d5704413b03f1cdd"))
		(1014500, uint256("0x6c6f4a93106fac9744b4b196b447b4b8cd5c4d563f3772b4f8c27fa58eb51af5"))
		(1014600, uint256("0x1a702c62f5d91022c1acf98a79008624c113b1de8b17894301f513c18e96d3d2"))
		(1014700, uint256("0x11b81a1e2cc05146e681f9b618711d38554c68fb0b73d8ecf78816cfce547f8c"))
		(1014800, uint256("0x2abd0319fb0052557feaab853e69cf7d17b002eeaedb5585952f3693d67688b6"))
		(1014850, uint256("0xe98edea8140da25f07ffc0bc6727c6d42a4d04590aa8d3a6a9de54e873857d01"))
		(1014900, uint256("0xcb353f74521bfc525faf1ffd2ab6841a3abc50c3e9e07339b6283f49e1d4a160"))
		(1014930, uint256("0x054332f385e47b8d5d323fc5e1f58258cb3e0ec66d98f83022852fa6446ee246"))

		;

	// TestNet has no checkpoints
	static MapCheckpoints mapCheckpointsTestnet;

	bool CheckHardened(int nHeight, const uint256& hash)
	{
		MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

		MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
		if (i == checkpoints.end()) return true;
		return hash == i->second;
	}

	int GetTotalBlocksEstimate()
	{
		MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

		if (checkpoints.empty())
			return 0;
		return checkpoints.rbegin()->first;
	}

	CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
	{
		MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

		BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
		{
			const uint256& hash = i.second;
			std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
			if (t != mapBlockIndex.end())
				return t->second;
		}
		return NULL;
	}

	// Automatically select a suitable sync-checkpoint 
	const CBlockIndex* AutoSelectSyncCheckpoint()
	{
		const CBlockIndex *pindex = pindexBest;
		// Search backward for a block within max span and maturity window
		while (pindex->pprev && pindex->nHeight + nCheckpointSpan > pindexBest->nHeight)
			pindex = pindex->pprev;
		return pindex;
	}

	// Check against synchronized checkpoint
	bool CheckSync(int nHeight)
	{
		const CBlockIndex* pindexSync = AutoSelectSyncCheckpoint();
		if (nHeight <= pindexSync->nHeight) {
			return false;
		}
		return true;
	}
}
