#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) : asset_manager(std::make_shared<GameAssetManager>(mode)) {
	
	for(int i = 0; i<6; i++){
		for(int j = 0; j<6; j++){
		asset_manager->AddAsset(std::make_shared<CubeAsset>(i*2, j*2, 0));
		}
	}
}

void GameWorld::Draw() {
  asset_manager->Draw();
}
