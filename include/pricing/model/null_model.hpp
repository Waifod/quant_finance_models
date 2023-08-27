#pragma once

#include "market_data_provider.hpp"
#include "pricing/model/model.hpp"

class NullModel : public Model {
 public:
  NullModel() = default;
  NullModel(std::shared_ptr<MarketDataProvider> market_data_provider) noexcept;
  double GetAssetPrice(std::shared_ptr<Asset> asset) const noexcept;
};
