#include "memorymanagementunit.hpp"

MemoryManagementUnit::MemoryManagementUnit(size_t memoryLength) {
  m_memoryLength = memoryLength;
  m_memoryArray = new uint16_t[memoryLength];
}

MemoryManagementUnit::~MemoryManagementUnit() {
  delete [] m_memoryArray;
}

void MemoryManagementUnit::setValue(uint16_t memoryAddress, uint16_t value) {}

uint16_t MemoryManagementUnit::getValue(uint16_t memoryAddress) {
  return 0;
}

size_t MemoryManagementUnit::getSize() {
  return m_memoryLength;
}
