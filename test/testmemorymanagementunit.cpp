#include <gtest/gtest.h>
#include "../src/memorymanagementunit.hpp"

#define MEMORY_SIZE 0x10000

class MemoryManagementUnitTest : public testing::Test {
  protected:
    MemoryManagementUnitTest() : m_mmu(MEMORY_SIZE) {}
    ~MemoryManagementUnitTest() {}
    MemoryManagementUnit m_mmu;
};

TEST_F(MemoryManagementUnitTest, GetMemorySize) {
  ASSERT_EQ(MEMORY_SIZE, m_mmu.getSize());
}
