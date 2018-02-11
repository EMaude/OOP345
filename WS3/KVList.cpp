#include "KVList.h"

template<typename K, typename V, int N>
KVList<K, V, N>::KVList()
{
	keys = { NULL };
	values = { NULL };
	lSize = 0;
}

template<typename K, typename V, int N>
size_t KVList<K, V, N>::size() const
{
	return lSize;
}

template<typename K, typename V, int N>
const K& KVList<K, V, N>::key(int i) const
{
	return keys[i];
}

template<typename K, typename V, int N>
const V & KVList<K, V, N>::value(int i) const
{
	return values[i];
}

template<typename K, typename V, int N>
KVList<K, V, N>& KVList<K, V, N>::add(const K &, const V &)
{
	if (lSize < N)
	{
		keys[lSize + 1] = K;
		values[lSize + 1] = V;
	}
	return *this;
}

template<typename K, typename V, int N>
int KVList<K, V, N>::find(const K &k) const
{
	
}

template<typename K, typename V, int N>
KVList<K, V, N>& KVList<K, V, N>::replace(int i, const K &k, const V &v)
{

}
