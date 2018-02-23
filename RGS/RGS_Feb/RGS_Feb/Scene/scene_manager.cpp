//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.18
// 内容　：シーンを管理するマネージャー
//-------------------------------------------------------
#include <Scene\scene_manager.h>
#include <Scene\loading.h>
#include <Scene\title.h>
#include <Scene\tutorial.h>
#include <Scene\gameplay.h>
#include <Scene\game_result.h>
#include <Scene\end.h>
#include <Scene\pause.h>
#include <Scene\scene_fader.h>
#include <Scene\game_manager.h>

using namespace Scene;
using namespace std;

SceneManager::SceneManager()
{
}

void SceneManager::Initialize()
{
	shared_ptr<GameManager> game_manager = make_shared<GameManager>();			//GameManager生成
	shared_ptr<GamePlay> game_play = make_shared<GamePlay>(game_manager);		//GamePlayScene

	Add(kTitle, make_shared<SceneFader>(make_shared<Title>(),1.0f,1.0f));
	//Add(kTitle, make_shared<Title>());
	Add(kTutorial, make_shared<Tutorial>());
	Add(kGamePlay, game_play);
	Add(kGameResult, make_shared<SceneFader>(make_shared<GameResult>(game_play), 0.0f, 1.0f));
	Add(kEnd, make_shared<End>());
	Add(kPause, make_shared<Pause>(game_play, game_manager));

	Add(kLoading, make_shared<Loading>());
	m_current_type = kLoading;
	m_current_scene = m_map[kLoading];
}

void SceneManager::Add(SceneType type, const std::shared_ptr<SceneBase> scene)
{
	m_map[type] = scene;
}

void SceneManager::Change(SceneType type)
{
	SceneType previous_type = m_current_type;
	m_current_type = type;
	m_current_scene = m_map[type];

	//if scene is not "pause" => initialize
	//if (previous_type != kPause) 
	m_current_scene.lock()->Initialize(previous_type);
}

void SceneManager::Update()
{
	m_current_scene.lock()->Update();
	if (m_current_scene.lock()->IsEnd())
	{
		m_current_scene.lock()->Shutdown();
		Change(m_current_scene.lock()->Next());
	}
}

void SceneManager::Draw()
{
	m_current_scene.lock()->Draw();
}