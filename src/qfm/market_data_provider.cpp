//
// Created by Durante, Matteo on 19/8/23.
//

#include <memory>

#include "qfm/asset/asset.hpp"
#include "qfm/market_data_provider.hpp"

namespace qfm {

double MarketDataProvider::GetAssetSpotPrice(
    const std::string& asset) const noexcept {
  return 1.0;
}

double MarketDataProvider::GetAssetVolatility(
    const std::string& asset) const noexcept {
  return 1.0;
}

double MarketDataProvider::GetInterestRate() const noexcept { return 1.0; }

}  // namespace qfm
