#include <cstddef>
#include <cstdint>

class IMemoryManagementUnit {
  public:
    virtual ~IMemoryManagementUnit() = default;
    virtual void setValue(uint16_t memoryAddress, uint16_t value) = 0;
    virtual uint16_t getValue(uint16_t memoryAddress) = 0;
};
