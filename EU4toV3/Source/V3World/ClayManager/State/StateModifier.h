#ifndef STATE_MODIFIER_H
#define STATE_MODIFIER_H
#include "Parser.h"

namespace V3
{
class BuildingGroups;
class StateModifier: commonItems::parser
{
  public:
	StateModifier() = default;
	void loadStateModifier(std::istream& theStream);
	void setName(const std::string& theName) { name = theName; }

	[[nodiscard]] const auto& getName() const { return name; }
	[[nodiscard]] const auto& getInfrastructureBonus() const { return infrastructure; }
	[[nodiscard]] const auto& getInfrastructureModifier() const { return infrastructureModifier; }
	[[nodiscard]] const auto& getPortBonus() const { return port; }
	[[nodiscard]] const auto& getNavalBaseBonus() const { return navalBase; }
	[[nodiscard]] const auto& getBuildingGroupModifiersMap() const { return buildingGroupModifiers; }
	[[nodiscard]] const auto& getBuildingModifiersMap() const { return buildingModifiers; }
	[[nodiscard]] const auto& getGoodsModifiersMap() const { return goodsModifiers; }
	[[nodiscard]] std::optional<double> getBuildingGroupModifier(const std::string& buildingGroup, std::shared_ptr<BuildingGroups> bgs) const;
	[[nodiscard]] std::optional<double> getBuildingModifier(const std::string& building) const;
	[[nodiscard]] std::optional<double> getGoodsModifier(const std::string& good) const;

  private:
	void registerKeys();
	commonItems::parser modifierUnwrapper;

	std::string name; // state_trait_natural_harbors

	int infrastructure = 0;
	double infrastructureModifier = 0.0;
	int port = 0;
	int navalBase = 0;
	std::map<std::string, double> buildingGroupModifiers; // building_group to throughput modifier
	std::map<std::string, double> buildingModifiers;		// building to throughput modifier
	std::map<std::string, double> goodsModifiers;			// good to goods throughput modifier
};
} // namespace V3

#endif // STATE_MODIFIER_H
