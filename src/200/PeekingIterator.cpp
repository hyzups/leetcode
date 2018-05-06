#include <vector>
#include <algorithm>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
	int m_next;
	int m_hasNext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		m_hasNext = Iterator::hasNext();
		if (m_hasNext) {
			m_next = Iterator::next();
		}
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if (m_hasNext) {
			return m_next;
		}
		return -1;
	}

	int next() {
		if (m_hasNext) {
			int res = m_next;
			m_hasNext = Iterator::hasNext();
			if (m_hasNext) {
				m_next = Iterator::next();
			}
			return res;
		}
		return -1;
	}
	// Returns true if the iteration has more elements.
	bool hasNext() const {
		return m_hasNext;
	}
};