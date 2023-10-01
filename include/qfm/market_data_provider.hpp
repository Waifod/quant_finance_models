//
// Created by Durante, Matteo on 19/8/23.
//

#pragma once

#include <memory>

#include "qfm/asset/asset.hpp"
#include "qfm/asset/asset_ticker.hpp"

namespace qfm {

class MarketDataProvider {
 public:
  MarketDataProvider(const double interest_rate) noexcept;
  double GetAssetSpotPrice(const asset::AssetTicker& asset) const noexcept;
  double GetAssetVolatility(const asset::AssetTicker& asset) const noexcept;
  double GetInterestRate() const noexcept;
  void SetInterestRate(const double interest_rate) noexcept;

 private:
  double interest_rate_;
};
}  // namespace qfm
