#include "imemorymanagementunit.hpp"

class MemoryManagementUnit : public IMemoryManagementUnit {
  public:
    MemoryManagementUnit(size_t memoryLength);
    ~MemoryManagementUnit() override;
    void setValue(uint16_t memoryAddress, uint16_t value) override;
    uint16_t getValue(uint16_t memoryAddress) override;
    size_t getSize() override;
  private:
    size_t m_memoryLength;
    uint16_t* m_memoryArray;
};
