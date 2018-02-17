#ifndef KVLIST_H
#define KVLIST_H

/*! Key Values list template */

template <typename K, typename V, int N>
class KVList
{
private:
	K keys[N];
	V values[N];
	int lSize;
public:
	/*!Default Constructor*/
	KVList()
	{
		lSize = 0;
	}
	/*! Returns Number of Entitys in the key value list*/
	size_t size() const
	{
		return lSize;
	}
	/*! Returns a const reference to the key of i value in list*/
	const K& key(int i) const
	{
		return keys[i];
	}
	/*! Returns a const reference to i value in list*/
	const V& value(int i) const
	{
		return values[i];
	}
	/*! Adds a item to the list if there is room, returns a reference to the current object*/
	KVList& add(const K& k, const V& v)
	{
		if (lSize < N)
		{
			keys[lSize + 1] = k;
			values[lSize + 1] = v;
			lSize++;
		}
		return *this;
	}
	/*! Returns the index of the first element with key k, defaults to 0*/
	int find(const K& k = 0) const
	{
		for (int i = 0; i < lSize; i++)
		{
			if (keys[i] == k)
			{
				return i;
			}
		}
		return 0;
	}
	/*! Replaces i in list with key and value, returns reference to object*/
	KVList& replace(int i, const K& k, const V& v)
	{
		if (i < lSize)
		{
			keys[i] = k;
			values[i] = v;
		}
		return *this;
	}
};

#endif // !W3_KVLIST_H


