#include "SceneStageSelect.h"



SceneStageSelect::SceneStageSelect(){
	setNext(nullptr);
}


SceneStageSelect::~SceneStageSelect()
{
}

//\------ いじるのここから下 (   void Scene,,,::run( ) のなか  ) ---------//

void SceneStageSelect::run() {

	while (true) {//  ---------　これメインループ　－－－－・・



		if (FrameEnd()) {//　これは定型文　みたいなの気にしないでおｋ。
			break;
		}
	}

}
