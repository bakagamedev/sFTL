#pragma once
#include <stdint.h>

#include "..\Debug.h"

//
// Declaration
//

namespace Ardutils
{
	template<typename TItem, int8_t Capacity>
	class Queue
	{
	public:
		static_assert(Capacity > 0, "Attempt to instantiate Queue with Capacity less than 1");

	private:
		TItem items[Capacity];
		int8_t next;

	public:
		Queue(void);

		int8_t GetCount(void) const; // O(1)
		int8_t GetCapacity(void) const; // O(1)
			
		TItem Peek(void) const; // O(1)
		bool Enqueue(const TItem & item); // O(1)
		TItem Dequeue(void); // O(1)
		
		void Clear(void); // O(n)	
		bool Contains(const TItem & item) const; // O(n)

		// Returns -1 if item not found
		int8_t IndexOf(const TItem & item) const; // O(n)

		TItem & operator [] (const uint8_t index); // O(1)
		const TItem & operator [] (const uint8_t index) const; // O(1)
	};
}


//
// Definition
//

template<typename TItem, int8_t Capacity>
Ardutils::Queue<TItem, Capacity>::Queue(void)
	: next(0)
{
}

template <typename TItem, int8_t Capacity>
int8_t Ardutils::Queue<TItem, Capacity>::GetCount(void) const // O(1)
{
	return this->next;
}

template <typename TItem, int8_t Capacity>
int8_t Ardutils::Queue<TItem, Capacity>::GetCapacity(void) const // O(1)
{
	return Capacity;
}

template <typename TItem, int8_t Capacity>
TItem Ardutils::Queue<TItem, Capacity>::Peek(void) const // O(1)
{
	return this->items[0];
}

template <typename TItem, int8_t Capacity>
bool Ardutils::Queue<TItem, Capacity>::Enqueue(const TItem & item) // O(1)
{
	if (this->next == Capacity)
		return false;

	this->items[this->next] = item;
	++this->next;
}

template <typename TItem, int8_t Capacity>
TItem Ardutils::Queue<TItem, Capacity>::Dequeue(void) // O(1)
{
	DEBUG_ASSERT(this->next > 0);

	auto result = this->items[0];
	
	for (uint8_t i = 0; i < this->next; ++i)
		this->items[i] = this->items[i + 1];
	--this->next;

	return result;
}

template <typename TItem, int8_t Capacity>
void Ardutils::Queue<TItem, Capacity>::Clear(void) // O(n)
{
	for (uint8_t i = 0; i < this->next; ++i)
		this->items[i] = TItem();
	this->next = 0;
}

template <typename TItem, int8_t Capacity>
bool Ardutils::Queue<TItem, Capacity>::Contains(const TItem & item) const // O(n)
{
	return this->indexOf(item) != -1;
}

template <typename TItem, int8_t Capacity>
int8_t Ardutils::Queue<TItem, Capacity>::IndexOf(const TItem & item) const // O(n)
{
	for (uint8_t i = 0; i < this->next; ++i)
		if (this->items[i] == item)
			return i;

	return -1;
}

template <typename TItem, int8_t Capacity>
TItem & Ardutils::Queue<TItem, Capacity>::operator [] (const uint8_t index) // O(1)
{
	DEBUG_ASSERT(index >= 0);
	DEBUG_ASSERT(index < Capacity);
	DEBUG_ASSERT(index < this->next);

	return this->items[index];
}

template <typename TItem, int8_t Capacity>
const TItem & Ardutils::Queue<TItem, Capacity>::operator [] (const uint8_t index) const // O(1)
{
	DEBUG_ASSERT(index >= 0);
	DEBUG_ASSERT(index < Capacity);
	DEBUG_ASSERT(index < this->next);

	return this->items[index];
}

