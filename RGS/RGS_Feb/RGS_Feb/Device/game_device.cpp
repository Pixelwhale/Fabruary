//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Device系をまとめたクラス
//-------------------------------------------------------
#include <Device\game_device.h>

using namespace Device;

GameDevice* GameDevice::m_instance = new GameDevice();

GameDevice::GameDevice()
{
}

GameDevice::GameDevice(const GameDevice&)
{
}

GameDevice::~GameDevice()
{
	m_input = 0;
	m_renderer = 0;
	m_content = 0;
	m_projector = 0;
}

bool GameDevice::Initialize()
{
	//Input初期化
	m_input = std::make_shared<Core::InputState>();
	//Content初期化
	m_content = std::make_shared<Device::ContentManager>();
	m_content->Initialize();
	//Renderer初期化
	m_renderer = std::make_shared<Device::Renderer>(m_content);
	m_renderer->Initialize();
	//Random初期化
	m_rand = Random();
	//Projector初期化
	m_projector = std::make_shared<Projector>();
	m_projector->Initialize();

	return true;
}

void GameDevice::ShutDown() 
{
	if (m_input)					//Inputの解放処理
	{
		m_input->ShutDown();
		m_input = 0;
	}

	if (m_renderer)					//Rendererの解放処理
	{
		m_renderer->Release();
		m_renderer = 0;
	}

	m_projector = 0;

	if (m_content)					//Contentの解放処理
	{
		m_content->Release();
		m_content = 0;
	}
}

std::shared_ptr<Core::InputState> GameDevice::GetInput()
{
	return m_input;
}

std::shared_ptr<Renderer> GameDevice::GetRenderer()
{
	return m_renderer;
}

std::shared_ptr<Projector> GameDevice::GetProjector() 
{
	return m_projector;
}

std::shared_ptr<ContentManager> GameDevice::GetContent()
{
	return m_content;
}

Random* GameDevice::GetRandom() 
{
	return &m_rand;
}