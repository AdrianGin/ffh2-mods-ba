#include "CvGameCoreDLL.h"
#include "CyCity.h"
#include "CyPlot.h"
#include "CyArea.h"
#include "CvInfos.h"

//# include <boost/python/manage_new_object.hpp>
//# include <boost/python/return_value_policy.hpp>

//
// published python interface for CyCity
//

void CyCityPythonInterface1(python::class_<CyCity>& x)
{
	OutputDebugString("Python Extension Module - CyCityPythonInterface1\n");

	x
		.def("isNone", &CyCity::isNone, "void () - is the instance valid?")
		.def("kill", &CyCity::kill, "void () - kill the city")
		.def("doTask", &CyCity::doTask, "void (int eTaskTypes, int iData1, int iData2, bool bOption) - Enacts the TaskType passed")
		.def("chooseProduction", &CyCity::chooseProduction, "void (int /*UnitTypes*/ eTrainUnit, int /*BuildingTypes*/ eConstructBuilding, int /*ProjectTypes*/ eCreateProject, bool bFinish, bool bFront) - Chooses production for a city")

		.def("createGreatPeople", &CyCity::createGreatPeople, "void (int /*UnitTypes*/ eGreatPersonUnit, bool bIncrementThreshold) - Creates a great person in this city and whether it should increment the threshold to the next level")

		.def("getCityPlotIndex", &CyCity::getCityPlotIndex, "int (CyPlot* pPlot)")
		.def("getCityIndexPlot", &CyCity::getCityIndexPlot, python::return_value_policy<python::manage_new_object>(), "CyPlot* (int iIndex)")
		.def("canWork", &CyCity::canWork, "bool (CyPlot*) - can the city work the plot?")
		.def("clearWorkingOverride", &CyCity::clearWorkingOverride, "void (int iIndex)")
		.def("countNumImprovedPlots", &CyCity::countNumImprovedPlots, "int ()")
		.def("countNumWaterPlots", &CyCity::countNumWaterPlots, "int ()")
		.def("countNumRiverPlots", &CyCity::countNumRiverPlots, "int ()")

		.def("findPopulationRank", &CyCity::findPopulationRank, "int ()")
		.def("findBaseYieldRateRank", &CyCity::findBaseYieldRateRank, "int (int /*YieldTypes*/ eYield)")
		.def("findYieldRateRank", &CyCity::findYieldRateRank, "int (int /*YieldTypes*/ eYield)")
		.def("findCommerceRateRank", &CyCity::findCommerceRateRank, "int (int /*CommerceTypes*/ eCommerce)")

		.def("allUpgradesAvailable", &CyCity::allUpgradesAvailable, "int UnitTypes (int eUnit, int iUpgradeCount)")
		.def("isWorldWondersMaxed", &CyCity::isWorldWondersMaxed, "bool ()")
		.def("isTeamWondersMaxed", &CyCity::isTeamWondersMaxed, "bool ()")
		.def("isNationalWondersMaxed", &CyCity::isNationalWondersMaxed, "bool ()")
		.def("isBuildingsMaxed", &CyCity::isBuildingsMaxed, "bool ()")
		.def("canTrain", &CyCity::canTrain, "bool (int eUnit, bool bContinue, bool bTestVisible)")
		.def("canConstruct", &CyCity::canConstruct, "bool (int eBuilding, bool bContinue, bool bTestVisible, bool bIgnoreCost)")
		.def("canCreate", &CyCity::canCreate, "bool (int eProject, bool bContinue, bool bTestVisible)")
		.def("canMaintain", &CyCity::canMaintain, "bool (int eProcess, bool bContinue)")
		.def("canJoin", &CyCity::canJoin, "bool () - can a Great Person join the city")
		.def("getFoodTurnsLeft", &CyCity::getFoodTurnsLeft, "int () - how many food turns remain?")
		.def("isProduction", &CyCity::isProduction, "bool () - is city producing?")
		.def("isProductionLimited", &CyCity::isProductionLimited, "bool ()")
		.def("isProductionUnit", &CyCity::isProductionUnit, "bool () - is city training a unit?")
		.def("isProductionBuilding", &CyCity::isProductionBuilding, "bool () - is city constructing a building?")
		.def("isProductionProject", &CyCity::isProductionProject, "bool ()")
		.def("isProductionProcess", &CyCity::isProductionProcess, "bool () - is city maintaining a process?")

		.def("canContinueProduction", &CyCity::canContinueProduction, "bool (OrderData order)")
		.def("getProductionExperience", &CyCity::getProductionExperience, "int (int /*UnitTypes*/ eUnit)")
		.def("addProductionExperience", &CyCity::addProductionExperience, "void (CyUnit* pUnit, bool bConscript)")

		.def("getProductionUnit", &CyCity::getProductionUnit, "UnitID () - ID for unit that is being trained")
		.def("getProductionUnitAI", &CyCity::getProductionUnitAI, "int eUnitAIType ()")
		.def("getProductionBuilding", &CyCity::getProductionBuilding, "BuildingID () - ID for building that is under construction")
		.def("getProductionProject", &CyCity::getProductionProject, "int /*ProjectTypes*/ ()")
		.def("getProductionProcess", &CyCity::getProductionProcess, "int /*ProcessTypes*/ ()")
		.def("getProductionName", &CyCity::getProductionName, "str () - description of item that the city is working on")
		.def("getGeneralProductionTurnsLeft", &CyCity::getGeneralProductionTurnsLeft, "int - # of production turns left for the top order node item in a city...")
		.def("getProductionNameKey", &CyCity::getProductionNameKey, "str () - description of item that the city is working on")
		.def("isFoodProduction", &CyCity::isFoodProduction, "bool () - is item under construction being created with food instead of production?")
		.def("getFirstUnitOrder", &CyCity::getFirstUnitOrder, "int (int /*UnitTypes*/ eUnit)")
		.def("getFirstBuildingOrder", &CyCity::getFirstBuildingOrder, "int (int /*BuildingTypes*/ eBuilding)")
		.def("getFirstProjectOrder", &CyCity::getFirstProjectOrder, "int (int /*ProjectTypes*/ eProject)")
		.def("isUnitFoodProduction", &CyCity::isUnitFoodProduction, "bool (UnitID) - does UnitID require food to be trained?")
		.def("getProduction", &CyCity::getProduction, "int () - returns the current production towards whatever is top of this city's OrderQueue")
		.def("getProductionNeeded", &CyCity::getProductionNeeded, "int () - # of production needed to complete construction")
		.def("getProductionTurnsLeft", &CyCity::getProductionTurnsLeft, "int () - # of turns remaining until item is completed")
		.def("getUnitProductionTurnsLeft", &CyCity::getUnitProductionTurnsLeft, "int (UnitID, int iNum) - # of turns remaining to complete UnitID")
		.def("getBuildingProductionTurnsLeft", &CyCity::getBuildingProductionTurnsLeft, "int (BuildingID, int iNum) - # of turns remaining to complete UnitID")
		.def("getProjectProductionTurnsLeft", &CyCity::getProjectProductionTurnsLeft, "int (int /*ProjectTypes*/ eProject, int iNum)")
		.def("setProduction", &CyCity::setProduction, "void (int iNewValue)")
		.def("changeProduction", &CyCity::changeProduction, "void (int iChange)")
		.def("getProductionModifier", &CyCity::getProductionModifier, "int () - multiplier (if any) for item being produced")
		.def("getCurrentProductionDifference", &CyCity::getCurrentProductionDifference, "int (bool bIgnoreFood, bool bOverflow)")
		.def("getUnitProductionModifier", &CyCity::getUnitProductionModifier, "int (UnitID) - production multiplier for UnitID")
		.def("getBuildingProductionModifier", &CyCity::getBuildingProductionModifier, "int (BuildingID) - production multiplier for BuildingID")
		.def("getProjectProductionModifier", &CyCity::getProductionModifier, "int (int /*ProjectTypes*/ eProject)")

		.def("getExtraProductionDifference", &CyCity::getExtraProductionDifference, "int (int iExtra)")

		.def("canHurry", &CyCity::canHurry, "bool (HurryTypes eHurry, bool bTestVisible = 0) - can player eHurry in this city?")
		.def("hurry", &CyCity::hurry, "void (HurryTypes eHurry) - forces the city to rush production using eHurry")
		.def("getConscriptUnit", &CyCity::getConscriptUnit, "UnitID () - UnitID for the best unit the city can conscript")
		.def("getConscriptPopulation", &CyCity::getConscriptPopulation, "int ()")
		.def("conscriptMinCityPopulation", &CyCity::conscriptMinCityPopulation, "int ()")
		.def("flatConscriptAngerLength", &CyCity::flatConscriptAngerLength, "int ()")
		.def("canConscript", &CyCity::canConscript, "bool () - can the city conscript units?")
		.def("conscript", &CyCity::conscript, "void () - conscripts a unit")
		.def("getBonusHealth", &CyCity::getBonusHealth, "int (BonusID) - total health bonus from BonusID")
		.def("getBonusHappiness", &CyCity::getBonusHappiness, "int (BonusID) - total happiness bonus from BonusID")
		.def("getBonusPower", &CyCity::getBonusPower, "int (int /*BonusTypes*/ eBonus, bool bDirty)")
		.def("getBonusYieldRateModifier", &CyCity::getBonusYieldRateModifier, "int (int /*YieldTypes*/ eIndex, int /*BonusTypes*/ eBonus)")
		.def("getHandicapType", &CyCity::getHandicapType, "HandicapType () - owners difficulty level")
		.def("getCivilizationType", &CyCity::getCivilizationType, "CivilizationID () - owners CivilizationID")
		.def("getPersonalityType", &CyCity::getPersonalityType, "int /*LeaderHeadTypes*/ ()")
		.def("getArtStyleType", &CyCity::getArtStyleType, "int /*ArtStyleTypes*/ ()")
		.def("getCitySizeType", &CyCity::getCitySizeType, "int /*CitySizeTypes*/ ()")

		.def("hasTrait", &CyCity::hasTrait, "bool (TraitID) - does owner have TraitID?")
		.def("isBarbarian", &CyCity::isBarbarian, "bool () - is owner a barbarian?")
		.def("isHuman", &CyCity::isHuman, "bool () - is owner human?")
		.def("isVisible", &CyCity::isVisible, "bool (int /*TeamTypes*/ eTeam, bool bDebug)")

		.def("isCapital", &CyCity::isCapital, "bool () - is city the owners capital?")
		.def("isCoastal", &CyCity::isCoastal, "bool (int) - is the city on the coast?")
		.def("isDisorder", &CyCity::isDisorder, "bool () - is the city in disorder?")
		.def("isHolyCityByType", &CyCity::isHolyCityByType, "bool (ReligionID) - is the city ReligionID's holy city?")
		.def("isHolyCity", &CyCity::isHolyCity, "bool () - is the city ReligionID's holy city?")
		.def("isHeadquartersByType", &CyCity::isHeadquartersByType, "bool (CorporationID) - is the city CorporationID's headquarters?")
		.def("isHeadquarters", &CyCity::isHeadquarters, "bool () - is the city CorporationID's headquarters?")
		.def("getOvercrowdingPercentAnger", &CyCity::getOvercrowdingPercentAnger, "int (iExtra)")
		.def("getNoMilitaryPercentAnger", &CyCity::getNoMilitaryPercentAnger, "int ()")
		.def("getCulturePercentAnger", &CyCity::getCulturePercentAnger, "int ()")
		.def("getReligionPercentAnger", &CyCity::getReligionPercentAnger, "int ()")
		.def("getWarWearinessPercentAnger", &CyCity::getWarWearinessPercentAnger, "int ()")
		.def("getLargestCityHappiness", &CyCity::getLargestCityHappiness, "int ()")
		.def("unhappyLevel", &CyCity::unhappyLevel, "int (int iExtra)")
		.def("happyLevel", &CyCity::happyLevel, "int ()")
		.def("angryPopulation", &CyCity::angryPopulation, "int (iExtra) - # of unhappy citizens")
		.def("totalFreeSpecialists", &CyCity::totalFreeSpecialists)
		.def("extraFreeSpecialists", &CyCity::extraFreeSpecialists, "int () - # of specialist that are allowed for free")
		.def("extraPopulation", &CyCity::extraPopulation, "int () - # of extra/available citizens")
		.def("extraSpecialists", &CyCity::extraSpecialists, "int () - # of extra/available specialists")
		.def("unhealthyPopulation", &CyCity::unhealthyPopulation, "int (bool bNoAngry), int (iExtra)")
		.def("totalGoodBuildingHealth", &CyCity::totalGoodBuildingHealth, "int ()")
		.def("totalBadBuildingHealth", &CyCity::totalBadBuildingHealth, "int ()")
		.def("goodHealth", &CyCity::goodHealth, "int () - total health")
		.def("badHealth", &CyCity::badHealth, "int (bool bNoAngry) - total unhealthiness")
		.def("healthRate", &CyCity::healthRate, "int (bool bNoAngry, int iExtra)")
		.def("foodConsumption", &CyCity::foodConsumption, "int (bool bNoAngry, int iExtra)")
		.def("foodDifference", &CyCity::foodDifference, "int (bool bBottom) - result of getYieldRate(Food) - foodConsumption()")
		.def("growthThreshold", &CyCity::growthThreshold, "int () - value needed for growth")
		.def("productionLeft", &CyCity::productionLeft, "int () - result of (getProductionNeeded() - getProduction()")
		.def("hurryCost", &CyCity::hurryCost, "int (bool bExtra)")
		.def("hurryGold", &CyCity::hurryGold, "int (HurryID) - total value of gold when hurrying")
		.def("hurryPopulation", &CyCity::hurryPopulation, "int (HurryID) - value of each pop when hurrying")
		.def("hurryProduction", &CyCity::hurryProduction, "int (HurryID)")
		.def("flatHurryAngerLength", &CyCity::flatHurryAngerLength, "int ()")
		.def("hurryAngerLength", &CyCity::hurryAngerLength, "int (HurryID)")
		.def("maxHurryPopulation", &CyCity::maxHurryPopulation, "int ()")

		.def("cultureDistance", &CyCity::cultureDistance, "int (iDX, iDY) - culture distance")
		.def("cultureStrength", &CyCity::cultureStrength, "int (ePlayer)")
		.def("cultureGarrison", &CyCity::cultureGarrison, "int (ePlayer)")
		.def("getNumBuilding", &CyCity::getNumBuilding, "int - (BuildingID) - How many BuildingID does this city have (real or free)?")
		.def("isHasBuilding", &CyCity::isHasBuilding, "bool (int iBuildingID) - This function actually no longer exists in C++, this is a helper function which hooks up to getNumBuilding() to help mod backwards compatibility")
		.def("getNumActiveBuilding", &CyCity::getNumActiveBuilding, "bool (BuildingID) - is BuildingID active in the city (present & not obsolete)?")
		.def("getID", &CyCity::getID, "int () - index ID # for the city - use with pPlayer.getCity(ID) to obtain city instance")
		.def("getX", &CyCity::getX, "int () - X coordinate for the cities plot")
		.def("getY", &CyCity::getY, "int () - Y coordinate for the cities plot")
		.def("at", &CyCity::at, "bool (iX, iY) - is the city at (iX, iY) ?")
		.def("atPlot", &CyCity::atPlot, "bool (CyPlot) - is pPlot the cities plot?")
		.def("plot", &CyCity::plot, python::return_value_policy<python::manage_new_object>(), "CyPlot () - returns cities plot instance")
		.def("isConnectedTo", &CyCity::isConnectedTo, "bool (CyCity*) - is city connected to CyCity* via the Trade Network?")
		.def("isConnectedToCapital", &CyCity::isConnectedToCapital, "bool (iOwner) - connected to the capital?")
		.def("area", &CyCity::area, python::return_value_policy<python::manage_new_object>(), "CyArea() () - returns CyArea instance for location of city")
		.def("waterArea", &CyCity::waterArea, python::return_value_policy<python::manage_new_object>(), "CyArea* ()")
		.def("getRallyPlot", &CyCity::getRallyPlot, python::return_value_policy<python::manage_new_object>(), "CyPlot () - returns city's rally plot instance")
		.def("getGameTurnFounded", &CyCity::getGameTurnFounded, "int () - GameTurn the city was founded")

		.def("getGameTurnAcquired", &CyCity::getGameTurnAcquired, "int ()")
		.def("getPopulation", &CyCity::getPopulation, "int () - total city population")
		.def("setPopulation", &CyCity::setPopulation, "void (int iNewValue) - sets the city population to iNewValue")
		.def("changePopulation", &CyCity::changePopulation, "void (int iChange) - adjusts the city population by iChange")
		.def("getRealPopulation", &CyCity::getRealPopulation, "int () - total city population in \"real\" numbers")
		.def("getHighestPopulation", &CyCity::getHighestPopulation, "int () ")
		.def("setHighestPopulation", &CyCity::setHighestPopulation, "void (iNewValue)")
		.def("getWorkingPopulation", &CyCity::getWorkingPopulation, "int () - # of citizens who are working")
		.def("getSpecialistPopulation", &CyCity::getSpecialistPopulation, "int () - # of specialists")
		.def("getNumGreatPeople", &CyCity::getNumGreatPeople, "int () - # of great people who are joined to the city")
		.def("getBaseGreatPeopleRate", &CyCity::getBaseGreatPeopleRate, "int () - base great person rate")
		.def("getGreatPeopleRate", &CyCity::getGreatPeopleRate, "int () - total Great Person rate")
		.def("getTotalGreatPeopleRateModifier", &CyCity::getTotalGreatPeopleRateModifier, "int ()")
		.def("changeBaseGreatPeopleRate", &CyCity::changeBaseGreatPeopleRate)
		.def("getGreatPeopleProgress", &CyCity::getGreatPeopleProgress, "int () - current great person progress")
		.def("getGreatPeopleRateModifier", &CyCity::getGreatPeopleRateModifier, "int ()")
		.def("getNumWorldWonders", &CyCity::getNumWorldWonders, "int ()")
		.def("getNumTeamWonders", &CyCity::getNumTeamWonders, "int ()")
		.def("getNumNationalWonders", &CyCity::getNumNationalWonders, "int ()")
		.def("getNumBuildings", &CyCity::getNumBuildings, "int ()")
		.def("changeGreatPeopleProgress", &CyCity::changeGreatPeopleProgress, "void (int iChange) - adjusts great person progress by iChange")
		.def("isGovernmentCenter", &CyCity::isGovernmentCenter, "bool () - is city the government center?")
		.def("getMaintenance", &CyCity::getMaintenance, "int () - cities current maintenance cost")
		.def("getMaintenanceTimes100", &CyCity::getMaintenanceTimes100, "int () - cities current maintenance cost")
		.def("calculateDistanceMaintenance", &CyCity::calculateDistanceMaintenance, "int ()")
		.def("calculateDistanceMaintenanceTimes100", &CyCity::calculateDistanceMaintenanceTimes100, "int ()")
		.def("calculateNumCitiesMaintenance", &CyCity::calculateNumCitiesMaintenance, "int ()")
		.def("calculateNumCitiesMaintenanceTimes100", &CyCity::calculateNumCitiesMaintenanceTimes100, "int ()")
		.def("calculateColonyMaintenance", &CyCity::calculateColonyMaintenance, "int ()")
		.def("calculateColonyMaintenanceTimes100", &CyCity::calculateColonyMaintenanceTimes100, "int ()")
		.def("calculateCorporationMaintenance", &CyCity::calculateCorporationMaintenance, "int ()")
		.def("calculateCorporationMaintenanceTimes100", &CyCity::calculateCorporationMaintenanceTimes100, "int ()")
		.def("getMaintenanceModifier", &CyCity::getMaintenanceModifier, "int () - total value of the city maintenance modifier")
		.def("getWarWearinessModifier", &CyCity::getWarWearinessModifier)
		.def("getHurryAngerModifier", &CyCity::getHurryAngerModifier)
		.def("changeHealRate", &CyCity::changeHealRate, "void (int iChange) - changes the heal rate of this city to iChange")

		.def("getEspionageHealthCounter", &CyCity::getEspionageHealthCounter, "int ()")
		.def("changeEspionageHealthCounter", &CyCity::changeEspionageHealthCounter, "void (int iChange)")
		.def("getEspionageHappinessCounter", &CyCity::getEspionageHappinessCounter, "int ()")
		.def("changeEspionageHappinessCounter", &CyCity::changeEspionageHappinessCounter, "void (int iChange)")

		.def("getFreshWaterGoodHealth", &CyCity::getFreshWaterGoodHealth, "int ()")
		.def("getFreshWaterBadHealth", &CyCity::getFreshWaterBadHealth, "int ()")
		.def("getBuildingGoodHealth", &CyCity::getBuildingGoodHealth, "int ()")
		.def("getBuildingBadHealth", &CyCity::getBuildingBadHealth, "int ()")
		.def("getFeatureGoodHealth", &CyCity::getFeatureGoodHealth, "int () - returns the good health provided by the feature this city is built on")
		.def("getFeatureBadHealth", &CyCity::getFeatureBadHealth, "int () - returns the bad health provided by the feature this city is built on")
		.def("getBuildingHealth", &CyCity::getBuildingHealth, "int (int eBuilding)")
		.def("getPowerGoodHealth", &CyCity::getPowerGoodHealth, "int ()")
		.def("getPowerBadHealth", &CyCity::getPowerBadHealth, "int ()")
		.def("getBonusGoodHealth", &CyCity::getBonusGoodHealth, "int ()")
		.def("getBonusBadHealth", &CyCity::getBonusBadHealth, "int ()")
		.def("getMilitaryHappiness", &CyCity::getMilitaryHappiness, "int () - happiness created by military units stationed in the city")
		.def("getMilitaryHappinessUnits", &CyCity::getMilitaryHappinessUnits, "number of military units creating happiness")
		.def("getBuildingGoodHappiness", &CyCity::getBuildingGoodHappiness, "int ()")
		.def("getBuildingBadHappiness", &CyCity::getBuildingBadHappiness, "int ()")
		.def("getBuildingHappiness", &CyCity::getBuildingHappiness, "int (int eBuilding)")
		.def("getExtraBuildingGoodHappiness", &CyCity::getExtraBuildingGoodHappiness, "int ()")
		.def("getExtraBuildingBadHappiness", &CyCity::getExtraBuildingBadHappiness, "int ()")
		.def("getFeatureGoodHappiness", &CyCity::getFeatureGoodHappiness, "int ()")
		.def("getFeatureBadHappiness", &CyCity::getFeatureBadHappiness, "int ()")
		.def("getBonusGoodHappiness", &CyCity::getBonusGoodHappiness, "int ()")
		.def("getReligionGoodHappiness", &CyCity::getReligionGoodHappiness, "int ()")
		.def("getReligionBadHappiness", &CyCity::getReligionBadHappiness, "int ()")
		.def("getReligionHappiness", &CyCity::getReligionHappiness, "int (int eReligion)")
		.def("getExtraHappiness", &CyCity::getExtraHappiness, "int ()")
		.def("getExtraHealth", &CyCity::getExtraHealth, "int ()")
		.def("changeExtraHealth", &CyCity::changeExtraHealth, "void (int iChange)")
		.def("changeExtraHappiness", &CyCity::changeExtraHappiness, "void (int iChange)")
		.def("getHurryAngerTimer", &CyCity::getHurryAngerTimer, "int () - Anger caused by Hurrying timer")
		.def("changeHurryAngerTimer", &CyCity::changeHurryAngerTimer, "void (iChange) - adjust Hurry Angry timer by iChange")
		.def("getConscriptAngerTimer", &CyCity::getConscriptAngerTimer, "int () - returns the amount of time left on the conscript anger timer")
		.def("changeConscriptAngerTimer", &CyCity::changeConscriptAngerTimer, "void (int iChange) -changes the amount of time left on the conscript anger timer")
		.def("getDefyResolutionAngerTimer", &CyCity::getDefyResolutionAngerTimer, "int () - returns the amount of time left on the anger timer")
		.def("changeDefyResolutionAngerTimer", &CyCity::changeDefyResolutionAngerTimer, "void (int iChange) -changes the amount of time left on the anger timer")
		.def("flatDefyResolutionAngerLength", &CyCity::flatDefyResolutionAngerLength, "int ()")
		.def("getHappinessTimer", &CyCity::getHappinessTimer, "int () - Temporary Happiness timer")
		.def("changeHappinessTimer", &CyCity::changeHappinessTimer, "void (iChange) - adjust Happiness timer by iChange")
		.def("isNoUnhappiness", &CyCity::isNoUnhappiness, "bool () - is the city unaffected by unhappiness?")
		.def("isNoUnhealthyPopulation", &CyCity::isNoUnhealthyPopulation, "bool () - is the city unaffected by unhealthiness?")
		.def("isBuildingOnlyHealthy", &CyCity::isBuildingOnlyHealthy, "bool () - is the city ?")

		.def("getFood", &CyCity::getFood, "int () - stored food")
		.def("setFood", &CyCity::setFood, "void (iNewValue) - set stored food to iNewValue")
		.def("changeFood", &CyCity::changeFood, "void (iChange) - adjust stored food by iChange")
		.def("getFoodKept", &CyCity::getFoodKept, "int ()")
		.def("getMaxFoodKeptPercent", &CyCity::getMaxFoodKeptPercent, "int ()")
		.def("getOverflowProduction", &CyCity::getOverflowProduction, "int () - value of overflow production")
		.def("setOverflowProduction", &CyCity::setOverflowProduction, "void (iNewValue) - set overflow production to iNewValue")
		.def("getFeatureProduction", &CyCity::getFeatureProduction, "int () - value of feature production")
		.def("setFeatureProduction", &CyCity::setFeatureProduction, "void (iNewValue) - set feature production to iNewValue")
		.def("getMilitaryProductionModifier", &CyCity::getMilitaryProductionModifier, "int () - value of adjustments to military production")
		.def("getSpaceProductionModifier", &CyCity::getSpaceProductionModifier, "int ()")
		.def("getExtraTradeRoutes", &CyCity::getExtraTradeRoutes, "int () - returns the number of extra trade routes this city has")
		.def("changeExtraTradeRoutes", &CyCity::changeExtraTradeRoutes, "void (iChange) - Change the number of trade routes this city has")
		.def("getTradeRouteModifier", &CyCity::getTradeRouteModifier, "int ()")
		.def("getForeignTradeRouteModifier", &CyCity::getForeignTradeRouteModifier, "int ()")
		.def("getBuildingDefense", &CyCity::getBuildingDefense, "int () - building defense")
		.def("getBuildingBombardDefense", &CyCity::getBuildingBombardDefense, "int () - building defense")
		.def("getFreeExperience", &CyCity::getFreeExperience, "int () - # of free experience newly trained units receive")
		.def("getCurrAirlift", &CyCity::getCurrAirlift, "int ()")
		.def("getMaxAirlift", &CyCity::getMaxAirlift, "int ()")
		.def("getAirModifier", &CyCity::getAirModifier, "int () - returns the air defense modifier")
		.def("getAirUnitCapacity", &CyCity::getAirUnitCapacity, "int (int /*TeamTypes*/ eTeam) - returns the number of air units allowed here")
		.def("getNukeModifier", &CyCity::getNukeModifier, "int ()")
		.def("getFreeSpecialist", &CyCity::getFreeSpecialist, "int ()")
		.def("isPower", &CyCity::isPower, "bool ()")
		.def("isAreaCleanPower", &CyCity::isAreaCleanPower, "bool ()")
		.def("isDirtyPower", &CyCity::isDirtyPower, "bool ()")
		.def("getDefenseDamage", &CyCity::getDefenseDamage, "int () - value of damage city defenses can receive")
		.def("changeDefenseDamage", &CyCity::changeDefenseDamage, "void (iChange) - adjust damage value by iChange")
		.def("isBombardable", &CyCity::isBombardable, "bool (CyUnit* pUnit)")
		.def("getNaturalDefense", &CyCity::getNaturalDefense, "int ()")
		.def("getTotalDefense", &CyCity::getTotalDefense, "int (bool bIgnoreBuilding)")
		.def("getDefenseModifier", &CyCity::getDefenseModifier, "int (bool bIgnoreBuilding)")


		;
}
