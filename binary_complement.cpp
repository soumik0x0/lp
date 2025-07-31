#pragma GCC optimize("O3")
#include <iostream>
#include <cstdint>

[[nodiscard]] inline constexpr uint32_t binaryComplement(uint32_t n)
{
  uint32_t flipped = ~n;
  return flipped;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t;
  std::cin >> t;

  while(t--)
  {
    uint32_t n;
    std::cin >> n;

    std::cout << binaryComplement(n) << "\n";
  }

  return 0;
}