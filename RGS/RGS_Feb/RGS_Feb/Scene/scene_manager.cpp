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
#include <Scene\end.h>
#include <Scene\pause.h>

using namespace Scene;
using namespace std;

SceneManager::SceneManager()
{
}

void SceneManager::Initialize()
{
	Add(kTitle, make_shared<Title>());
	Add(kTutorial, make_shared<Tutorial>());
	Add(kGamePlay, make_shared<GamePlay>());
	Add(kEnd, make_shared<End>());
	Add(kPause, make_shared<Pause>());

	Add(kLoading, make_shared<Loading>());
	m_current_type = kLoading;
	m_current_scene = m_map[kLoading];
}

void SceneManager::Add(SceneType type, std::shared_ptr<SceneBase> scene)
{
	m_map[type] = scene;
}

void SceneManager::Change(SceneType type)
{
	SceneType previous_type = m_current_type;
	m_current_type = type;
	m_current_scene = m_map[type];

	//if scene is not "pause" => initialize
	if (previous_type != kPause) m_current_scene.lock()->Initialize(previous_type);
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