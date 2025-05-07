#include <gtest/gtest.h>
#include "../src/memorymanagementunit.hpp"

#define MEMORY_SIZE 0x10000

class MemoryManagementUnitTest : public testing::Test {
  protected:
    MemoryManagementUnitTest() : m_mmu(MEMORY_SIZE) {}
    ~MemoryManagementUnitTest() {}
    MemoryManagementUnit m_mmu;
};

struct MemoryLocationsAndValues {
  size_t memoryAddress;
  uint16_t value;
};

TEST_F(MemoryManagementUnitTest, GetMemorySize) {
  ASSERT_EQ(MEMORY_SIZE, m_mmu.getSize());
}

TEST_F(MemoryManagementUnitTest, SetAndGetValues) {
  MemoryLocationsAndValues values[6] = {{0, 0x2345}, {256, 0xFFFF}, {0xFFFF, 0xAAAA}, {0x3000, 0x5AA5}, {3000, 0x3000}, {0x5555, 12348}};
  for (auto value : values) {
    m_mmu.setValue(value.memoryAddress, value.value);
  }

  for (auto value : values) {
    ASSERT_EQ(value.value, m_mmu.getValue(value.memoryAddress));
  }
}
