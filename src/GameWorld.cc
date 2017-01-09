#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {
	
	for(int j=-2; j<2; j++) {
		for(int i=-2; i<3; i++) {
			auto cube = std::make_shared<CubeAsset>(i, -0.5, j);
			asset_manager->AddAsset(cube);
		}
	}
	/*for(int i = 0; i<6; i++){
		for(int j = 0; j<6; j++){
		auto cube = std::make_shared<CubeAsset>(i, j, 0);
		cube->setColour(0,0,0);
		asset_manager->AddAsset(cube);
		}
	}*/
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
